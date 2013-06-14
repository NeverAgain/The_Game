/*
 * Matrix.h
 *
 *  Created on: 2013-06-14
 *      Author: Samuel
 */

#ifndef MATRIX_H_
#define MATRIX_H_

typedef float mat4[16];

class Matrix{
	void matrixIdentity(mat4 matrix);

	void setFrustum(mat4 matrix,float left, float right, float top, float bottom, float near, float far);
};


#endif /* MATRIX_H_ */
