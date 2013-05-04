/*
 * Player.h
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObj.h"

class Player: protected GameObj{
	enum PlayerState{
		STAND,
		MOVE,
		ATTACK,
		COUNTER
	};

	public:
		Player(int px, int py);

	private:
};

#endif /* PLAYER_H_ */
