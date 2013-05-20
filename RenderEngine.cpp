/*
 * RenderEngine.cpp
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */
#include "RenderEngine.h"

RenderEngine::RenderEngine()
{

}

void RenderEngine::enableRenderEngine(){
	enable = true;
}

void RenderEngine::disableRenderEngine(){
	enable = false;
}

bool RenderEngine::getIfEnable(){
	return enable;
}

void RenderEngine::setMDepth(float mDepth){
	this->mDepth = mDepth;
}

float RenderEngine::getMDepth(){
	return this->mDepth;
}

void RenderEngine::setMStartTime(GLfloat mStartTime){
	this->mStartTime = mStartTime;
}

GLfloat RenderEngine::getMStartTime(){
	return this->mStartTime;
}

void RenderEngine::initGL()
{
	glShadeModel(GL_SMOOTH);
	glClearDepthf(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
	int z = mDepth;
	GLfloat rotation = (maGetMilliSecondCount() - mStartTime) * -0.05f;


	// Define quad vertices.
    GLfloat vertices[4][3];
    // Top right.
    vertices[0][0] = 1.0f; vertices[0][1] = 1.0f; vertices[0][2] = 0.0f;
    // Top left.
    vertices[1][0] = -1.0f; vertices[1][1] = 1.0f; vertices[1][2] = 0.0f;
    // Bottom left.
    vertices[2][0] = 1.0f; vertices[2][1] = -1.0f; vertices[2][2] = 0.0f;
    // Bottom right.
    vertices[3][0] = -1.0f; vertices[3][1] = -1.0f; vertices[3][2] = 0.0f;

    // Draw quad.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, -z);
	glClearColor(0.8, 0.9, 0.6, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor4f(0.9, 0.0, 0.0, 1.0);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glFinish();
}

/**
 * Compute the visible size of the quad by
 * setting the depth coordinate.
 */
void RenderEngine::computeZoomFactor(MAPoint2d point)
{
	float screenHeight = EXTENT_Y(maGetScrSize());
	mDepth = 20.0f / screenHeight * point.y;
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
