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

GameWorldState GameWorld::checkGameWorldState(){
	return gameWorldState;
}

void GameWorld::runTimerEvent(){
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
