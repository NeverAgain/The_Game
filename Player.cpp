/*
 * Player.cpp
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#include "Player.h";

Player::Player(int px, int py):GameObj(px,py){
	state = STAND;
	x = px;
	y = py;
}


Player::~Player(){

}


void GameObj::update(){
	//x = 3;
	//lprintfln("player Event fired");

	lprintfln(("LOG "+Convert::toString(x)).c_str());
}
