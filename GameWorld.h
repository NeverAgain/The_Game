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
#include <conprint.h>
#include "GameObj.h"

using namespace MAUtil;

class GameWorld : public TimerListener {
//class GameWorld {
	public:
		int test;
		GameWorld();
		~GameWorld();
		void propegateObjs();
		void runTimerEvent();
		void addGameObj(GameObj *addObj);
		void removeGameObj(GameObj rmObj);

	private:
		List<GameObj*> gameObjList;

};

#endif /* GAMEWORLD_H_ */

