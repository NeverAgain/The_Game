/*
 * GameWorld.h
 *
 *  Created on: 2013-05-11
 *      Author: Samuel
 */


#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include <MAUtil/Environment.h>
#include <conprint.h>


class GameWorld : public MAUtil::TimerListener {
//class GameWorld {
	public:
		int test;
		GameWorld();
		void runTimerEvent();

};

#endif /* GAMEWORLD_H_ */

