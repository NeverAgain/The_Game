/*
 * RenderEngine.h
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */

#include <GLES/gl.h>

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_

class RenderEngine
{
	private:
		GLfloat mStartTime;
		GLfloat mDepth;

	public :
		RenderEngine();

		void setMDepth(float mDepth);
		float getMDepth();

		void setMStartTime(GLfloat mDepth);
		GLfloat getMStartTime();

		void initGL();
		void setViewport(int width, int height);
		void draw(GLfloat z, GLfloat rotation);
		void computeZoomFactor(MAPoint2d point);
		void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);

};

#endif /* RENDERENGINE_H_ */
