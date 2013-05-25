/*
 * GameWorld.h
 *
 *  Created on: 2013-05-11
 *      Author: Samuel
 */


#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include <MAUtil/Environment.h>
#include <MAUtil/List.h>
#include <MAUtil/Hashmap.h>
#include <MAUtil/HashDict.h>
#include <MAUtil/String.h>
#include <MAUtil/Dictionary.h>
#include <conprint.h>

#include "GameObj.h"

using namespace MAUtil;

class GameWorld : public TimerListener {

	enum GameWorldState {
		RUN,
		PAUSE
	};

	public:
		GameWorld();
		~GameWorld();

		GameWorldState checkGameWorldState();

		void propegateObjs();
		void runTimerEvent();
		void addGameObj(GameObj *addObj);
		void removeGameObj(GameObj *rmObj);
		void getGameObj(GameObj*getObj);

	private:
		HashMap<String,GameObj*>gameObjList;
		GameWorldState gameWorldState;
		//List<GameObj*> gameObjList;

};

#endif /* GAMEWORLD_H_ */

