/*
 *  Matrix3D.h
 *  UniverseGL
 *
 *  Created by Kris Temmerman on 15/12/10.
 *  Copyright 2010 Neuro Productions. All rights reserved.
 *
 */
#ifndef _MATRIX3D_H
#define _MATRIX3D_H

#import <GLUT/GLUT.h>

class Matrix3D 
{

 
 GLfloat m[16];

public:
	
	Matrix3D();
	GLfloat* getRawData(void);
	void identity(void);
	void translate(GLfloat x, GLfloat y,GLfloat z);
	void rotate(GLfloat angle,GLfloat x,GLfloat y,GLfloat z);
	void multiply (GLfloat m1[],GLfloat m2[]);
	void perspProjMat( float fov, float aspect, float znear, float zfar);
	void log(void);
	void projectVector(float *vec);
	void gluInvertMatrix(float *m,float *invOut);
};

#endif