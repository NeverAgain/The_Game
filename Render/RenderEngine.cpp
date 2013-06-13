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

//setup functions////////////////////////////////////////////////////
bool RenderEngine::initGL(){
	GLuint ver;

	width = EXTENT_X(maGetScrSize());
	height = EXTENT_Y(maGetScrSize());

	alphaBlending(true);
	textures(true);
	//cullFace(true);
	//depthTest(true);
	blendMode(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//setupRenderBuffer();
	//setupFrameBuffer();
	setupVertexBufferObj();

	String vertexShaderSource = getVertexShader();
	GLuint vertexShader = loadShader(vertexShaderSource.c_str(),GL_VERTEX_SHADER);
	checkGLError("Load vertex shader");

	String fragmentShaderSource = getFragmentShader();
	GLuint fragmentShader = loadShader(fragmentShaderSource.c_str(),GL_FRAGMENT_SHADER);
	checkGLError("Load fragment shader");

	buildProgram(vertexShader, fragmentShader);


    glClearColor(0, 104.0/255.0, 55.0/255.0, 1.0);
	glClearDepthf(1.0f);
	enableRenderEngine();

	return true;
}

void RenderEngine::setupRenderBuffer(){
	glGenRenderbuffers(1,&_colorRenderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER,_colorRenderBuffer);
}

void RenderEngine::setupFrameBuffer(){
	GLuint framebuffer;
	glGenFramebuffers(1, &framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _colorRenderBuffer);
}

void RenderEngine::setupVertexBufferObj(){
	glGenBuffers(1,&_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glGenBuffers(1,&_indexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
}

//////////////////////////////////////////////////////////////////////
// render engine settings/////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////
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
		lprintfln("LOG %s: glGetError returned %x", where, err);
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
		lprintfln("LOG Error compiling shader");
		GLint infoLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen == 0) // android bug.
			infoLen = 1024;
		if (infoLen > 1) {
			char* infoLog = (char*) malloc(sizeof(char) * infoLen);
			glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
			lprintfln("LOG Error compiling shader:\n%s\n", infoLog);
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
		lprintfln("LOG Could not create program!");
		return FALSE;
	}
	checkGLError("Create program");

	glAttachShader(programObject, vertexShader);
	checkGLError("Attach vertex shader");

	glAttachShader(programObject, fragmentShader);
	checkGLError("Attach fragment shader");

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

	glUseProgram(programObject);

	//set variables to be use in shaders
	_positionData = glGetAttribLocation(programObject,"Position");
	_colorData = glGetAttribLocation(programObject,"SourceColor");
	glEnableVertexAttribArray(_positionData);
	glEnableVertexAttribArray(_colorData);

	_projectionUniform = glGetUniformLocation(programObject, "Projection");


	CC3GLMatrix *projection = [CC3GLMatrix matrix];
	float h = 4.0f * height / width;
	[projection populateFromFrustumLeft:-2 andRight:2 andBottom:-h/2 andTop:h/2 andNear:4 andFar:10];


	return programObject;
}

//////////////////////////////////////////////////////////////////////
// Render functions///////////////////////////////////////////////////
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
    glClearColor(0, 104.0/255.0, 55.0/255.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);



	glViewport(0, 0, (GLint)width, (GLint)height);

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);

	glVertexAttribPointer(_positionData, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),0);
	glVertexAttribPointer(_colorData, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*) (sizeof(float) * 3));

	//glUniformMatrix4fv(_projectionUniform, 1, 0, projection.glMatrix);

	glDrawElements(GL_TRIANGLES, sizeof(Indices)/sizeof(Indices[0]), GL_UNSIGNED_BYTE,0);
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
