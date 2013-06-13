/*
 * RenderEngine.h
 *
 *  Created on: 2013-05-11
 *      Author: Jie Jerry Lin
 */

#include <GLES2/gl2.h>
#include "../Logic/GameWorld.h"
#include <MAFS/File.h>
#include <MAUtil/String.h>
#include "MAHeaders.h"

#ifndef RENDERENGINE_H_
#define RENDERENGINE_H_

typedef struct {
    float Position[3];
    float Color[4];
} Vertex;

const Vertex Vertices[] = {
    {{1, -1, 0}, {1, 0, 0, 1}},
    {{1, 1, 0}, {0, 1, 0, 1}},
    {{-1, 1, 0}, {0, 0, 1, 1}},
    {{-1, -1, 0}, {0, 0, 0, 1}}
};

const GLubyte Indices[] = {
     0, 1, 2,
     2, 3, 0
};

class RenderEngine
{
	public :
		enum RenderEngineState {
			RUN,
			PAUSE
		};

		GLuint _colorRenderBuffer;

		GLuint _positionData;
		GLuint _colorData;

	    GLuint _vertexBuffer;
	    GLuint _indexBuffer;


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
		void cullFace(bool enable);
		void depthTest(bool enable);
		void blendMode(int srcBlendMode, int dstBlendMode);

		//Setup
		bool initGL();
		void setupRenderBuffer();
		void setupFrameBuffer();
		void setupVertexBufferObj();
		void setViewport(int width, int height);
		void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
		void bindTexture();

		//Runtime functions
		void draw();

		//Util functions
		//TODO move to different file
		String getVertexShader();
		String getFragmentShader();
		void checkGLError(const char* where);
		GLuint loadShader(const char *shaderSrc,GLenum type);
		GLuint buildProgram(GLuint vertexShader, GLuint fragmentShader);

	private:
		bool enable;
		GameWorld *gameWorldRef;
		RenderEngineState renderEngineState;

		int width;
		int height;

};

#endif /* RENDERENGINE_H_ */
