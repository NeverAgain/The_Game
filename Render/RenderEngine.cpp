/*
 * RenderEngine.cpp
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */
#include "RenderEngine.h"

RenderEngine::RenderEngine(GameWorld *gmWorldRef)
{
	gameWorldRef = gmWorldRef;
}

RenderEngine::~RenderEngine(){
	delete gameWorldRef;
}

void RenderEngine::setRenderEngineState(RenderEngineState state){
	this->renderEngineState = state;
}

RenderEngine::RenderEngineState RenderEngine::getRenderEngineState(){
	return renderEngineState;
}

void RenderEngine::enableRenderEngine(){
	this->enable = true;
}

void RenderEngine::disableRenderEngine(){
	this->enable = false;
}

bool RenderEngine::getIfEnable(){
	return this->enable;
}

bool RenderEngine::initGL(){
	GLuint ver;

	width = EXTENT_X(maGetScrSize());
	height = EXTENT_Y(maGetScrSize());

	alphaBlending(true);
	textures(true);
	cullFace(true);
	depthTest(true);
	blendMode(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLuint vertexShader;
	String vertexShaderSource = getVertexShader();
	vertexShader = loadShader(vertexShaderSource.c_str(),GL_VERTEX_SHADER);
	checkGLError("Load vertex shader");

	GLuint fragmentShader;
	String fragmentShaderSource = getFragmentShader();
	fragmentShader = loadShader(fragmentShaderSource.c_str(),GL_FRAGMENT_SHADER);
	checkGLError("Load fragment shader");

	GLuint programObject = buildProgram(vertexShader, fragmentShader);

	// Store the program object
	fullShader = programObject;

    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepthf(1.0f);
	enableRenderEngine();

	return true;
}

void RenderEngine::alphaBlending(bool enable){
	if(enable){
		glEnable(GL_BLEND);
	}else{
		glDisable(GL_BLEND);
	}
}

void RenderEngine::textures(bool enable){
	if(enable){
		glEnable(GL_TEXTURE_2D);
	}else{
		glDisable(GL_TEXTURE_2D);
	}
}

void RenderEngine::cullFace(bool enable){
	if(enable){
		glEnable(GL_CULL_FACE);
	} else {
		glDisable(GL_CULL_FACE);
	}
}

void RenderEngine::depthTest(bool enable){
	if(enable){
		glEnable(GL_DEPTH_TEST);
	} else {
		glDisable(GL_DEPTH_TEST);
	}
}

void RenderEngine::blendMode(int srcBlendMode,int dstBlendMode){
	glBlendFunc(srcBlendMode, dstBlendMode);
}

//Util functions////////////////////////////////////////////////////////////////////
String RenderEngine::getVertexShader(){
	int len = maGetDataSize(R_VERTEX_SHADER);
	char buffer[len+1];
	maReadData(R_VERTEX_SHADER,&buffer,0,len);
	buffer[len] = '\0';

	String shader = "";
	shader.append(buffer,len);
	return shader;
}

String RenderEngine::getFragmentShader(){
	int len = maGetDataSize(R_FRAGMENT_SHADER);
	char buffer[len+1];
	maReadData(R_FRAGMENT_SHADER,&buffer,0,len);
	buffer[len] = '\0';

	String shader = "";
	shader.append(buffer,len);
	return shader;
}

void RenderEngine::checkGLError(const char* where) {
	GLenum err = glGetError();
	if (err != GL_NO_ERROR) {
		lprintfln("%s: glGetError returned %x", where, err);
	}
}

GLuint RenderEngine::loadShader(const char *shaderSrc, GLenum type) {
	//lprintfln("loading shader: %s", shaderSrc);
	checkGLError("begin loading shader");

	GLuint shader;
	GLint compiled;
	// Create the shader object
	shader = glCreateShader(type);
	checkGLError("glCreateShader");

	if (shader == 0) {
		lprintfln("Invalid shader handle!");
		return 0;
	}
	// Load the shader source
	glShaderSource(shader, 1, &shaderSrc, NULL);
	checkGLError("glShaderSource");

	// Compile the shader
	glCompileShader(shader);
	checkGLError("glCompileShader");

	// Check the compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	checkGLError("glGetShaderiv");

	if (!compiled) {
		lprintfln("Error compiling shader");
		GLint infoLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen == 0) // android bug.
			infoLen = 1024;
		if (infoLen > 1) {
			char* infoLog = (char*) malloc(sizeof(char) * infoLen);
			glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
			lprintfln("Error compiling shader:\n%s\n", infoLog);
			free(infoLog);
		}
		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

GLuint RenderEngine::buildProgram(GLuint vertexShader, GLuint fragmentShader){
	GLuint programObject;
	// Create the program object
	programObject = glCreateProgram();
	if (programObject == 0) {
		lprintfln("Could not create program!");
		return FALSE;
	}
	checkGLError("Create program");

	glAttachShader(programObject, vertexShader);
	checkGLError("Attach vertex shader");

	glAttachShader(programObject, fragmentShader);
	checkGLError("Attach fragment shader");

	// Bind vPosition to attribute 0
	glBindAttribLocation(programObject, 0, "vPosition");
	checkGLError("Bind vPosition to vertex shader");

	// Link the program
	glLinkProgram(programObject);

	GLint linked;
	// Check the link status
	glGetProgramiv(programObject, GL_LINK_STATUS, &linked);
	if (!linked) {
		lprintfln("Failed to link shader!");
		GLint infoLen = 0;
		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen == 0) // android bug.
			infoLen = 1024;
		if (infoLen > 1) {
			char* infoLog = (char*) malloc(sizeof(char) * infoLen);
			glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
			lprintfln("Error linking program:\n%s\n", infoLog);
			free(infoLog);
		}
		glDeleteProgram(programObject);
		return FALSE;
	}

	return programObject;
}

//////////////////////////////////////////////////////////////////////

void RenderEngine::setViewport(int viewWidth, int viewHeight)
{
	// Protect against divide by zero.
	if (0 == viewHeight) {
		viewHeight = 1;
	}

	// Set viewport and perspective.
	glViewport(0, 0, (GLint)viewWidth, (GLint)viewHeight);
	GLfloat ratio = (GLfloat)viewWidth / (GLfloat)viewHeight;
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}

/**
 * Setup the projection matrix.
 */
void RenderEngine::draw()
{
	//lprintfln("LOG drawing");
	GLfloat vVertices[] = { -1.0f, 1.0f, 0.0f,
							 1.0f, 1.0f, 0.0f,
							 1.0f,-1.0f, 0.0f,
							-1.0f,-1.0f, 0.0f };

	glViewport(0, 0, (GLint)width, (GLint)height);
	glClear(GL_COLOR_BUFFER_BIT);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	checkGLError("glVertexAttribPointer");

	glEnableVertexAttribArray(0);
	checkGLError("glEnableVertexAttribArray");

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	checkGLError("glDrawArrays");
}

/**
 * Standard OpenGL utility function for setting up the
 * perspective projection matrix.
 */
void RenderEngine::gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar)
{
	const float M_PI = 3.14159;

	GLfloat ymax = zNear * tan(fovy * M_PI / 360.0);
	GLfloat ymin = -ymax;
	GLfloat xmin = ymin * aspect;
	GLfloat xmax = ymax * aspect;

	//glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);
}
