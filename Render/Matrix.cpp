/*
 * Matrix.cpp
 *
 *  Created on: 2013-06-14
 *      Author: Samuel
 */

#include "Matrix.h";

void Matrix::matrixIdentity(mat4 m){
	m[0] = 1.0;		m[4] = 0.0;		m[8] = 0.0;		m[12] = 0.0;
	m[1] = 0.0;		m[5] = 1.0;		m[9] = 0.0;		m[13] = 0.0;
	m[2] = 0.0;		m[6] = 0.0;		m[10] = 1.0;	m[14] = 0.0;
	m[3] = 0.0;		m[7] = 0.0;		m[11] = 0.0;	m[15] = 1.0;
}

void setFrustum(mat4 matrix,float left, float right, float top, float bottom, float near, float far){
	//TODO stuff
}
