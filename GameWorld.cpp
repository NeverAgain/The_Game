/*
 * GameWorld.cpp
 *
 *  Created on: 2013-05-11
 *      Author: Samuel
 */

#include "GameWorld.h"

GameWorld::GameWorld(){
	//gameObjList = new MAUtil::List<GameObj>();
};

GameWorld::~GameWorld(){

};

void GameWorld::runTimerEvent(){
	//lprintfln("timer event fired");//needs to be in debug mode to show message
	//printf(Convert::toString(gameObjList->size()).c_str());

	//requires more than one object in list to iterate through
	List<GameObj*>::ListIterator iterator = gameObjList.begin();

	while(iterator.hasNext()){
		iterator.next()->update();
	}
};

void GameWorld::addGameObj(GameObj *addObj){
	gameObjList.addLast(addObj);
}
