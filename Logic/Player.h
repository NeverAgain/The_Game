/*
 * Player.h
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <conprint.h>
#include "GameObj.h"
#include "../Convert/Convert.h"

class Player: public GameObj{

	enum PlayerState {
		ATTACK,
		MOVE,
		STAND
	};

	public:
		Player(String objName, int px, int py,HashMap<String,GameObj*> *gmObjList);
		~Player();
	private:
};

#endif /* PLAYER_H_ */
