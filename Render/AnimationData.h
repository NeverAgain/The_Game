/*
 * AnimationData.h
 *
 *  Created on: 2013-05-22
 *      Author: Samuel
 */

#ifndef ANIMATIONDATA_H_
#define ANIMATIONDATA_H_

#include <MAUI/Image.h>

class AnimationData
{
	private:
		Image* displayImage;

		int currentFrame;
		int numOfFrame;

		int sheetWidth;
		int sheetHeight;

		int spriteWidth;
		int spriteHeight;

		int rows;
		int columns;

	public:
		AnimationData(int sheetWidth, int sheetHeight, int rows, int columns);
		~AnimationData();
};



#endif /* ANIMATIONDATA_H_ */
