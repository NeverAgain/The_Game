/*
 * RenderEngine.h
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */

#include <GLES2/gl2.h>
#include "../Logic/GameWorld.h"

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_

class RenderEngine
{
	public :
		enum RenderEngineState {
			RUN,
			PAUSE
		};


		RenderEngine(GameWorld *gameWorld);
		~RenderEngine();

		void enableRenderEngine();
		void disableRenderEngine();
		bool getIfEnable();

		RenderEngineState getRenderEngineState();
		void setRenderEngineState(RenderEngineState state);

		//Render settings
		void alphaBlending(bool enable);
		void textures(bool enable);
		void blendMode(int srcBlendMode, int dstBlendMode);

		//Setup
		bool initGL();
		void setViewport(int width, int height);
		void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
		void bindTexture();

		//Runtime functions
		void draw();
		void checkGLError(const char* where);

	private:
		bool enable;
		GameWorld *gameWorldRef;
		RenderEngineState renderEngineState;

		int width;
		int height;

};

#endif /* RENDERENGINE_H_ */
