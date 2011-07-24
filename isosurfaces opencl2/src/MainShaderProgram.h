//
//  MainShaderProgram.h
//  polygonExample
//
//  Created by Kris Temmerman on 20/04/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//


#ifndef _MAINSHADER_PROG
#define _MAINSHADER_PROG


#import "ShaderUtil.h"
#import "Matrix3D.h"

class MainShaderProgram 
{
    GLuint program;
	GLuint vShader;
	GLuint fShader;
	
	
	
	
    GLint objectMatrixLocation;
    GLint worldMatrixLocation ;
    GLint perspMatrixLocation;

    Matrix3D *perspectiveMatrix;
    Matrix3D *worldMatrix;
    Matrix3D *objectMatrix;
    
    float verh;  
    bool perspectiveisDirty;
    
public:
    MainShaderProgram ();

    void enable();
    void render(float *buffer, int numTris);
    void disable();
    void windowResized(int w, int h);

};

#endif