/*
 *  Matrix3D.mm
 *  UniverseGL
 *
 *  Created by Kris Temmerman on 15/12/10.
 *  Copyright 2010 Neuro Productions. All rights reserved.
 *
 */

#include "Matrix3D.h"

Matrix3D::Matrix3D(void)
{
	
	//Matrix3D::identity();
	m[0] =1.0f;
	m[4] =0.0f;
	m[8] =0.0f;
	m[12] =0.0f;
	
	
	m[1] =0.0f;
	m[5] =1.0f;
	m[9] =0.0f;
	m[13] =0.0f;
	
	m[2] =0.0f;
	m[6] =0.0f;
	m[10] =1.0f;
	m[14] =0.0f;
	
	m[3] =0.0f;
	m[7] =0.0f;
	m[11] =0.0f;
	m[15] =1.0f;
	
	
	
}
GLfloat* Matrix3D::getRawData(void)
{

	return Matrix3D::m;

}
void projectVector(float *vec)
{
//	float vecBack[4]  ={1,1,1,1};
	
	//vec[0] =1.0;//vecBack[0];
	/*vec[1] =vecBack[1];
	vec[2] =vecBack[2];
	vec[3] =vecBack[3];*/
	

};
void Matrix3D::identity(void)
{
	

	m[0] =1.0f;
	m[4] =0.0f;
	m[8] =0.0f;
	m[12] =0.0f;
	
	
	m[1] =0.0f;
	m[5] =1.0f;
	m[9] =0.0f;
	m[13] =0.0f;
	
	m[2] =0.0f;
	m[6] =0.0f;
	m[10] =1.0f;
	m[14] =0.0f;
	
	m[3] =0.0f;
	m[7] =0.0f;
	m[11] =0.0f;
	m[15] =1.0f;
	
	
	
}
void Matrix3D::rotate(GLfloat angle,GLfloat x,GLfloat y,GLfloat z)
{
	GLfloat sinAngle, cosAngle;
	GLfloat mag = sqrtf(x * x + y * y + z * z);
	
	sinAngle = sinf ( angle * 3.1415 / 180.0f );
	cosAngle = cosf ( angle * 3.1415 / 180.0f );
	if ( mag > 0.0f )
	{
		GLfloat xx, yy, zz, xy, yz, zx, xs, ys, zs;
		GLfloat oneMinusCos;
				
		x /= mag;
		y /= mag;
		z /= mag;
		
		xx = x * x;
		yy = y * y;
		zz = z * z;
		xy = x * y;
		yz = y * z;
		zx = z * x;
		xs = x * sinAngle;
		ys = y * sinAngle;
		zs = z * sinAngle;
		oneMinusCos = 1.0f - cosAngle;
		
		m[0] = (oneMinusCos * xx) + cosAngle;
		m[1] = (oneMinusCos * xy) - zs;
		m[2] = (oneMinusCos * zx) + ys;
		m[3] = 0.0F; 
		
		m[4] = (oneMinusCos * xy) + zs;
		m[5] = (oneMinusCos * yy) + cosAngle;
		m[6] = (oneMinusCos * yz) - xs;
		m[7] = 0.0F;
		
		m[8] = (oneMinusCos * zx) - ys;
		m[9] = (oneMinusCos * yz) + xs;
		m[10] = (oneMinusCos * zz) + cosAngle;
		m[11] = 0.0F; 
		
		m[12] = 0.0F;
		m[13] = 0.0F;
		m[14] = 0.0F;
		m[15] = 1.0F;
		
		
	}
	
	
	
	
	
	
	
}
void Matrix3D::multiply (GLfloat m1[],GLfloat m2[])
{
	GLfloat mr[16];
	
	mr[0] = m1[0]*m2[0] +m1[1]*m2[4]+m1[2]*m2[8]+m1[3]*m2[12];
	mr[1] = m1[0]*m2[1] +m1[1]*m2[5]+m1[2]*m2[9]+m1[3]*m2[13];
	mr[2] = m1[0]*m2[2] +m1[1]*m2[6]+m1[2]*m2[10]+m1[3]*m2[14];
	mr[3] = m1[0]*m2[3] +m1[1]*m2[7]+m1[2]*m2[11]+m1[3]*m2[15];

	mr[4] = m1[4]*m2[0] +m1[5]*m2[4]+m1[6]*m2[8]+m1[7]*m2[12];
	mr[5] = m1[4]*m2[1] +m1[5]*m2[5]+m1[6]*m2[9]+m1[7]*m2[13];
	mr[6] = m1[4]*m2[2] +m1[5]*m2[6]+m1[6]*m2[10]+m1[7]*m2[14];
	mr[7] = m1[4]*m2[3] +m1[5]*m2[7]+m1[6]*m2[11]+m1[7]*m2[15];
	
	mr[8] = m1[8]*m2[0] +m1[9]*m2[4]+m1[10]*m2[8]+m1[11]*m2[12];
	mr[9] = m1[8]*m2[1] +m1[9]*m2[5]+m1[10]*m2[9]+m1[11]*m2[13];
	mr[10] = m1[8]*m2[2] +m1[9]*m2[6]+m1[10]*m2[10]+m1[11]*m2[14];
	mr[11] = m1[8]*m2[3] +m1[9]*m2[7]+m1[10]*m2[11]+m1[11]*m2[15];
	
	mr[12] = m1[12]*m2[0] +m1[13]*m2[4]+m1[14]*m2[8]+m1[15]*m2[12];
	mr[13] = m1[12]*m2[1] +m1[13]*m2[5]+m1[14]*m2[9]+m1[15]*m2[13];
	mr[14] = m1[12]*m2[2] +m1[13]*m2[6]+m1[14]*m2[10]+m1[15]*m2[14];
	mr[15] = m1[12]*m2[3] +m1[13]*m2[7]+m1[14]*m2[11]+m1[15]*m2[15];
	
	m[0] = mr[0];
	m[1] = mr[1];
	m[2] = mr[2];
	m[3] = mr[3];
	
	m[4] = mr[4];
	m[5] = mr[5];
	m[6] = mr[6];
	m[7] = mr[7];
	
	m[8] = mr[8];
	m[9] = mr[9];
	m[10] = mr[10];
	m[11] = mr[11];
	
	m[12] = mr[12];
	m[13] =mr[13];
	m[14] =mr[14];
	m[15] =mr[15];
}
void Matrix3D::translate(GLfloat x, GLfloat y,GLfloat z)
{
	GLfloat m2[16] ;
	m2[0] =1.0f;
	m2[4] =0.0f;
	m2[8] =0.0f;
	m2[12] =0.0f;
	
	
	m2[1] =0.0f;
	m2[5] =1.0f;
	m2[9] =0.0f;
	m2[13] =0.0f;
	
	m2[2] =0.0f;
	m2[6] =0.0f;
	m2[10] =1.0f;
	m2[14] =0.0f;
	
	m2[3] =x;
	m2[7] =y;
	m2[11] =z;
	m2[15] =1.0f;
	
	
	Matrix3D::multiply(m,m2);
	
	
}

void Matrix3D::gluInvertMatrix(float *m, float *invOut)
{
	float inv[16], det;
	int i;
	
	inv[0] =   m[5]*m[10]*m[15] - m[5]*m[11]*m[14] - m[9]*m[6]*m[15]
	+ m[9]*m[7]*m[14] + m[13]*m[6]*m[11] - m[13]*m[7]*m[10];
	inv[4] =  -m[4]*m[10]*m[15] + m[4]*m[11]*m[14] + m[8]*m[6]*m[15]
	- m[8]*m[7]*m[14] - m[12]*m[6]*m[11] + m[12]*m[7]*m[10];
	inv[8] =   m[4]*m[9]*m[15] - m[4]*m[11]*m[13] - m[8]*m[5]*m[15]
	+ m[8]*m[7]*m[13] + m[12]*m[5]*m[11] - m[12]*m[7]*m[9];
	inv[12] = -m[4]*m[9]*m[14] + m[4]*m[10]*m[13] + m[8]*m[5]*m[14]
	- m[8]*m[6]*m[13] - m[12]*m[5]*m[10] + m[12]*m[6]*m[9];
	inv[1] =  -m[1]*m[10]*m[15] + m[1]*m[11]*m[14] + m[9]*m[2]*m[15]
	- m[9]*m[3]*m[14] - m[13]*m[2]*m[11] + m[13]*m[3]*m[10];
	inv[5] =   m[0]*m[10]*m[15] - m[0]*m[11]*m[14] - m[8]*m[2]*m[15]
	+ m[8]*m[3]*m[14] + m[12]*m[2]*m[11] - m[12]*m[3]*m[10];
	inv[9] =  -m[0]*m[9]*m[15] + m[0]*m[11]*m[13] + m[8]*m[1]*m[15]
	- m[8]*m[3]*m[13] - m[12]*m[1]*m[11] + m[12]*m[3]*m[9];
	inv[13] =  m[0]*m[9]*m[14] - m[0]*m[10]*m[13] - m[8]*m[1]*m[14]
	+ m[8]*m[2]*m[13] + m[12]*m[1]*m[10] - m[12]*m[2]*m[9];
	inv[2] =   m[1]*m[6]*m[15] - m[1]*m[7]*m[14] - m[5]*m[2]*m[15]
	+ m[5]*m[3]*m[14] + m[13]*m[2]*m[7] - m[13]*m[3]*m[6];
	inv[6] =  -m[0]*m[6]*m[15] + m[0]*m[7]*m[14] + m[4]*m[2]*m[15]
	- m[4]*m[3]*m[14] - m[12]*m[2]*m[7] + m[12]*m[3]*m[6];
	inv[10] =  m[0]*m[5]*m[15] - m[0]*m[7]*m[13] - m[4]*m[1]*m[15]
	+ m[4]*m[3]*m[13] + m[12]*m[1]*m[7] - m[12]*m[3]*m[5];
	inv[14] = -m[0]*m[5]*m[14] + m[0]*m[6]*m[13] + m[4]*m[1]*m[14]
	- m[4]*m[2]*m[13] - m[12]*m[1]*m[6] + m[12]*m[2]*m[5];
	inv[3] =  -m[1]*m[6]*m[11] + m[1]*m[7]*m[10] + m[5]*m[2]*m[11]
	- m[5]*m[3]*m[10] - m[9]*m[2]*m[7] + m[9]*m[3]*m[6];
	inv[7] =   m[0]*m[6]*m[11] - m[0]*m[7]*m[10] - m[4]*m[2]*m[11]
	+ m[4]*m[3]*m[10] + m[8]*m[2]*m[7] - m[8]*m[3]*m[6];
	inv[11] = -m[0]*m[5]*m[11] + m[0]*m[7]*m[9] + m[4]*m[1]*m[11]
	- m[4]*m[3]*m[9] - m[8]*m[1]*m[7] + m[8]*m[3]*m[5];
	inv[15] =  m[0]*m[5]*m[10] - m[0]*m[6]*m[9] - m[4]*m[1]*m[10]
	+ m[4]*m[2]*m[9] + m[8]*m[1]*m[6] - m[8]*m[2]*m[5];
	
	det = m[0]*inv[0] + m[1]*inv[4] + m[2]*inv[8] + m[3]*inv[12];
	if (det == 0)
       // return false;
	
	det = 1.0 / det;
	
	for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;
	
	//return true;
}




void Matrix3D::perspProjMat( float fov, float aspect,
							float znear, float zfar)
{
	float xymax = znear * tan(fov * (3.145/360.0));
	float ymin = -xymax;
	float xmin = -xymax;
	
	float width = xymax - xmin;
	float height = xymax - ymin;
	
	float depth = zfar - znear;
	float q = -(zfar + znear) / depth;
	float qn = -2 * (zfar * znear) / depth;
	
	float w = 2 * znear / width;
	w = w / aspect;
	float h = 2 * znear / height;
	
	m[0]  = w;
	m[1]  = 0;
	m[2]  = 0;
	m[3]  = 0;
	
	m[4]  = 0;
	m[5]  = h;
	m[6]  = 0;
	m[7]  = 0;
	
	m[8]  = 0;
	m[9]  = 0;
	m[10] = q;
	m[11] = -1;
	
	m[12] = 0;
	m[13] = 0;
	m[14] = qn;
	m[15] = 0;
}
	void Matrix3D::log()
{

}