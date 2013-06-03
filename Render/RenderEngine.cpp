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

void RenderEngine::initGL()
{
}

void RenderEngine::setViewport(int width, int height)
{
	// Protect against divide by zero.
	if (0 == height)
	{
		height = 1;
	}

	// Set viewport and perspective.
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = (GLfloat)width / (GLfloat)height;
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}

/**
 * Setup the projection matrix.
 */
void RenderEngine::draw()
{
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

	glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);
}
