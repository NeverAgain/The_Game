/*
 * GameObj.cpp
 *
 *  Created on: 2013-05-04
 *      Author: Samuel
 */

#include "GameObj.h";

GameObj::GameObj(String objName, int px, int py):name(objName),x(px),y(py){}

//Direction GameObj::getDirection() { return direction;	}
//void GameObj::setDirection(Direction direction) { this->direction = direction;	}

int GameObj::getX() const {	return x;	}
void GameObj::setX(int x) {	this->x = x;}

int GameObj::getY() const {	return y;	}
void GameObj::setY(int y) {	this->y = y;}

int GameObj::getHeight() const {	return height;}
void GameObj::setHeight(int height) {this->height = height;}

int GameObj::getWidth() const {		return width;	}
void GameObj::setWidth(int width) {	this->width = width;}

String GameObj::getName() const {	return name;	}
void GameObj::setName(String name) {this->name = name;}
