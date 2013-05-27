/*
 * Player.cpp
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#include "Player.h"


Player::Player(String objName, int px, int py, HashMap<String,GameObj*>* gmObjList):GameObj(objName,px,py,gmObjList){
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

	/*
	Player *test;
	if(this->name == "player1"){
		test = (Player*)(this->gameObjList->find("player2")->second);
		lprintfln("LOG I am %s printing %s from the other player",this->name.c_str(),test->name.c_str());
	}
	*/
}
