#include "GameWorld.h"
#include "RenderEngine.h"

#include <maapi.h>
#include <mastdlib.h>
#include <mavsprintf.h>
#include <MAUtil/Moblet.h>
#include <MAUtil/GLMoblet.h>
#include <GLES/gl.h>


using namespace MAUtil;

#define LOGIC_UPDATE_INTERVAL 20

/**
 * Moblet to be used as a template for an Open GL application.
 * The template program draws a rotating quad. Touch the
 * screen to change the depth coordinate.
 */
class MyGLMoblet : public GLMoblet
{
public:
	GameWorld* gameWorld;
	RenderEngine* renderEngine;


	// ================== Constructor ==================
	/**
	 * Initialize rendering parameters.
	 */
	MyGLMoblet() :
		GLMoblet(GLMoblet::GL1),
		mDepth(5.0f),
		mStartTime(maGetMilliSecondCount())
	{
	}

	// ================== Event methods ==================

	/**
	 * Called when a fullscreen window with an OpenGL context
	 * has been created and is ready to be used.
	 */
	void init()
	{
		gameWorld = new GameWorld();
		addTimer(gameWorld, LOGIC_UPDATE_INTERVAL, 0);

		renderEngine = new RenderEngine();
		// Set the GL viewport to be the entire MoSync screen.
		renderEngine->setViewport(EXTENT_X(maGetScrSize()),EXTENT_Y(maGetScrSize()));

		// Initialize OpenGL.
		renderEngine->initGL();

		// Call draw 60 times per second.
		setPreferredFramesPerSecond(60);
	}

	/**
	 * Called when the application should render the model.
	 * Use method setPreferredFramesPerSecond to set the
	 * desired frame rate.
	 */
	void draw()
	{
		// Compute rotation.
		GLfloat rotation = (maGetMilliSecondCount() - renderEngine->mStartTime) * -0.05f;

		// Render scene.
		renderEngine->draw(renderEngine->mDepth, rotation);
	}

	/**
	 * Called when a key is pressed.
	 */
	void keyPressEvent(int keyCode, int nativeCode)
	{
		if (MAK_BACK == keyCode || MAK_0 == keyCode)
		{
			// Call close to exit the application.
			close();
		}
	}

	/**
	 * Called on a touch down event.
	 */
	void pointerPressEvent(MAPoint2d point)
	{
		renderEngine->computeZoomFactor(point);
	}

	/**
	 * Called on a touch drag event.
	 */
	void pointerMoveEvent(MAPoint2d point)
	{
		renderEngine->computeZoomFactor(point);
	}


};

/**
 * Main function that is called when the program starts.
 */
extern "C" int MAMain()
{
	Moblet::run(new MyGLMoblet);
	return 0;
}
