/*
 * AnimationData.cpp
 *
 *  Created on: 2013-05-22
 *      Author: Samuel
 */

#include "AnimationData.h"

AnimateData::AnimationData(MAHandle image, int rows=1, int columns=1) : image(image),rows(rows),columns(columns){
	MAExtent extent = maGetImageSize(image);
	spriteWidth = EXTENT_X(extent)/columns;
	spriteHeight = EXTENT_Y(extent)/rows;

}

AnimationData::~AnimationData(){}

AnimationData::update(){
	//TODO should use
	//void maGetImageData	(MAHandle image,void * dst, const MARect * srcRect,int scanlength)

	//TODO consider
	//int maCreateImageFromData	(MAHandle placeholder,MAHandle data,int offset,int size)
	//or
	//int maCreateImageRaw	(MAHandle placeholder,const void * src,MAExtent size, int alpha)
}
