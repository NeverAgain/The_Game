/*
 * AnimationData.cpp
 *
 *  Created on: 2013-05-22
 *      Author: Samuel
 */

#include "AnimationData.h"

AnimationData::AnimationData(MAHandle image, int rows=1, int columns=1) : image(image),rows(rows),columns(columns){
	MAExtent extent = maGetImageSize(image);

	imagePixelWidth = EXTENT_X(extent);
	imagePixelHeight = EXTENT_Y(extent);

	spriteWidth = imagePixelWidth/columns;
	spriteHeight = imagePixelHeight/rows;

	frameRect.width = spriteWidth;
	frameRect.height = spriteHeight;

	numOfFrames = rows*columns;
	currentFrame = 0;

	currentRow = 0;
	currentColumn = 0;
}

AnimationData::~AnimationData(){}

void AnimationData::update(){
	currentFrame = (int) (currentFrame + 1);

	if(currentFrame >= numOfFrames){
		currentFrame = 0;
	}

	currentRow = ((int)currentFrame / columns);
	currentColumn = ((int)currentFrame % columns);

	frameRect.left = currentColumn*spriteWidth;
	frameRect.top = currentRow*spriteHeight;

	//lprintfln("LOG frame left %d, top %d, width %d, height %d",frameRect.left,frameRect.top,frameRect.width,frameRect.height);
	//lprintfln("LOG rows %d, columns %d, currentFrame %d", currentRow, currentColumn,currentFrame);
}

int AnimationData::getXDrawPos() const {
	return xDrawPos;
}

void AnimationData::setXDrawPos(int xDrawPos) {
	this->xDrawPos = xDrawPos;
}

int AnimationData::getYDrawPos() const {
	return yDrawPos;
}

void AnimationData::setYDrawPos(int yDrawPos) {
	this->yDrawPos = yDrawPos;
}
