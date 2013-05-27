/*
 * AnimationData.h
 *
 *  Created on: 2013-05-22
 *      Author: Samuel
 */

#ifndef ANIMATIONDATA_H_
#define ANIMATIONDATA_H_

#include <conprint.h>
#include <MAUI/Image.h>
#include "maapi.h"

class AnimationData
{
	private:
		MAHandle image;

		int currentFrame;
		int numOfFrame;

		int sheetWidth;
		int sheetHeight;

		int spriteWidth;
		int spriteHeight;

		int rows;
		int columns;

		MARect frameRect;

		int imagePixelWidth;
		int imagePixelHeight;


	public:
		AnimationData(MAHandle image, int rows, int columns);
		~AnimationData();

		void update();
};



#endif /* ANIMATIONDATA_H_ */
