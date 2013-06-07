#include "Logic/GameWorld.h"
#include "Logic/Player.h"
#include "Render/RenderEngine.h"
#include "Render/AnimationData.h"


#include <ma.h>
#include <maapi.h>
#include <mastdlib.h>
#include <mavsprintf.h>
#include <MAUtil/Moblet.h>
#include <MAUtil/GLMoblet.h>
#include <GLES2/gl2.h>
#include "MAHeaders.h"

using namespace MAUtil;

#define LOGIC_UPDATE_INTERVAL 20

/**
 * Moblet to be used as a template for an Open GL application.
 * The template program draws a rotating quad. Touch the
 * screen to change the depth coordinate.
 */
class MyGLMoblet : public GLMoblet, FocusListener
{
public:
	GameWorld* gameWorld;
	RenderEngine* renderEngine;

	AnimationData *data;


	// ================== Constructor ==================
	/**
	 * Initialize rendering parameters.
	 */
	MyGLMoblet() :
		GLMoblet(GLMoblet::GL2)
	{
		gameWorld = new GameWorld();
		addTimer(gameWorld, LOGIC_UPDATE_INTERVAL, 0);

		Player *player1 = new Player("player1",1,0,gameWorld->getGameObjListRef());
		Player *player2 = new Player("player2",2,0,gameWorld->getGameObjListRef());

		gameWorld->addGameObj(player1);
		gameWorld->addGameObj(player2);

		renderEngine = new RenderEngine(gameWorld);

		Environment::getEnvironment().addFocusListener(this);

	}

	// ================== Event methods ==================

	/**
	 * Called when a fullscreen window with an OpenGL context
	 * has been created and is ready to be used.
	 */
	void init()
	{
		// Initialize OpenGL.
		renderEngine->initGL();


		// Set the GL viewport to be the entire MoSync screen.
		renderEngine->setViewport(EXTENT_X(maGetScrSize()),EXTENT_Y(maGetScrSize()));

		//AnimationData *data = new AnimationData(R_BASIC,1,1);
		data = new AnimationData(R_TEST,5,5);

		// Call draw 60 times per second.
		setPreferredFramesPerSecond(60);
	}

	void focusLost(){
		renderEngine->disableRenderEngine();
	}

	void focusGained(){
		renderEngine->enableRenderEngine();
	}

	/**
	 * Called when the application should render the model.
	 * Use method setPreferredFramesPerSecond to set the
	 * desired frame rate.
	 */
	void draw()
	{
		if(renderEngine->getIfEnable()){
			renderEngine->draw();
			data->update();
		}
	}

	/**
	 * Called when a key is pressed.
	 */
	void keyPressEvent(int keyCode, int nativeCode)
	{
		if (MAK_BACK == keyCode || MAK_0 == keyCode)
		{
			// Call close to exit the application.
			//renderEngine = 0;

			delete gameWorld;
			delete renderEngine;
			close();
		}
	}

	/**
	 * Called on a touch down event.
	 */
	void pointerPressEvent(MAPoint2d point)
	{
	}

	/**
	 * Called on a touch drag event.
	 */
	void pointerMoveEvent(MAPoint2d point)
	{
	}


};

/**
 * Main function that is called when the program starts.
 */
extern "C" int MAMain()
{
	MyGLMoblet *game = new MyGLMoblet();
	Moblet::run(game);

	delete game;
	return 0;
}
