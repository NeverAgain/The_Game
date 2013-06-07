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

    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepthf(1.0f);

	alphaBlending(true);
	textures(true);
	blendMode(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

void RenderEngine::blendMode(int srcBlendMode,int dstBlendMode){
	glBlendFunc(srcBlendMode, dstBlendMode);
}

void RenderEngine::checkGLError(const char* where) {
	GLenum err = glGetError();
	if (err != GL_NO_ERROR) {
		lprintfln("%s: glGetError returned %x", where, err);
	}
}

void RenderEngine::setViewport(int viewWidth, int viewHeight)
{
	// Protect against divide by zero.
	if (0 == viewHeight) {
		viewHeight = 1;
	}

	// Set viewport and perspective.
	glViewport(0, 0, (GLint)viewWidth, (GLint)viewHeight);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	GLfloat ratio = (GLfloat)viewWidth / (GLfloat)viewHeight;
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}

/**
 * Setup the projection matrix.
 */
void RenderEngine::draw()
{
	lprintfln("LOG drawing");
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
