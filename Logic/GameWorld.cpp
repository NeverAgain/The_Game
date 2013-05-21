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
	gameObjList.clear();
	delete &gameObjList;
};

void GameWorld::runTimerEvent(){
	//lprintfln("timer event fired");//needs to be in debug mode to show message
	//printf(Convert::toString(gameObjList->size()).c_str());

	//requires more than one object in list to iterate through
	//List<GameObj*>::ListIterator iterator = gameObjList.begin();

	for(	HashMap<String, GameObj*>::Iterator iterator = gameObjList.begin();
			iterator != gameObjList.end();
			iterator++){
		iterator->second->update();
	}

};

HashMap<String,GameObj*>* GameWorld::getGameObjListRef(){
	return &gameObjList;
}

void GameWorld::removeGameObj(GameObj *rmObj){
	gameObjList.erase(rmObj->getName());
	delete rmObj;
}

void GameWorld::addGameObj(GameObj *addObj){
	gameObjList.insert(addObj->getName(),addObj);
}

void GameWorld::getGameObj(GameObj *getObj){
	gameObjList.find(getObj->getName());
}
