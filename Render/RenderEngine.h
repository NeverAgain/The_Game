/*
 * RenderEngine.h
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */

#include <GLES/gl.h>
#include "../Logic/GameWorld.h"

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_

class RenderEngine
{
	public :
		RenderEngine(GameWorld *gameWorld);

		void enableRenderEngine();
		void disableRenderEngine();
		bool getIfEnable();

		void setMDepth(float mDepth);
		float getMDepth();

		void setMStartTime(GLfloat mDepth);
		GLfloat getMStartTime();

		GLfloat mStartTime;
		GLfloat mDepth;

		void initGL();
		void setViewport(int width, int height);
		void draw();
		void computeZoomFactor(MAPoint2d point);
		void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);

	private:
		bool enable;
		GameWorld *gameWorldRef;

};

#endif /* RENDERENGINE_H_ */
