/*
 * Player.cpp
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#include "Player.h";

Player::Player(String objName, int px, int py):GameObj(objName,px,py){
	state = STAND;
}


Player::~Player(){

}


void GameObj::update(){
	//x = 3;
	//lprintfln("player Event fired");

	//lprintfln(("LOG "+this->name).c_str());
	//lprintfln("LOG %d",this->x);
	//lprintfln("LOG %s",this->name.c_str());
}
