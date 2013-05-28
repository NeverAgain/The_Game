/*
 * AnimationData.h
 *
 *  Created on: 2013-05-22
 *      Author: Samuel
 */

#ifndef ANIMATIONDATA_H_
#define ANIMATIONDATA_H_

#include <MAUI/Image.h>
#include "maapi.h"

class AnimationData
{
	private:
		MAHandle displayImage;

		int currentFrame;
		int numOfFrame;

		int sheetWidth;
		int sheetHeight;

		int spriteWidth;
		int spriteHeight;

		int rows;
		int columns;

		int xDrawPos;
		int yDrawPos;

	public:
		AnimationData(MAHandle image, int rows=1, int columns=1);
		~AnimationData();

		void update();
		int getXDrawPos() const;
		void setXDrawPos(int xDrawPos);

		int getYDrawPos() const;
		void setYDrawPos(int yDrawPos);
};



#endif /* ANIMATIONDATA_H_ */
