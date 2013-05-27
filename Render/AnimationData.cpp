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

	//lprintfln("LOG spriteWIDTH %d",spriteWidth);

	numOfFrame = rows*columns;
	currentFrame = 0;

}

AnimationData::~AnimationData(){}

void AnimationData::update(){
	//TODO should use
	//void maGetImageData	(MAHandle image,void * dst, const MARect * srcRect,int scanlength)
	MAHandle *dataSrc;
	maGetImageData(image,dataSrc,&frameRect,imagePixelWidth);

	MAHandle *getImage;
	MARect r = {0, 0, spriteWidth, spriteHeight};
	int test = maCreateImageFromData(getImage, dataSrc,0,maGetDataSize(dataSrc));

	//TODO consider
	//int maCreateImageFromData	(MAHandle placeholder,MAHandle data,int offset,int size)
	//or
	//int maCreateImageRaw	(MAHandle placeholder,const void * src,MAExtent size, int alpha)
}
