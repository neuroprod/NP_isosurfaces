//
//  MainShaderProgram.cpp
//  polygonExample
//
//  Created by Kris Temmerman on 20/04/11.
//  Copyright 2011 Neuro Productions. All rights reserved.
//

#include "MainShaderProgram.h"

enum {
	ATTRIB_VERTEX,
	ATTRIB_NORMALS
};
MainShaderProgram::MainShaderProgram ()
{

    ShaderUtil *su =new ShaderUtil;
	vShader =su->getShader("MainVertexShader.vsh",GL_VERTEX_SHADER );
	
	fShader =su->getShader("MainFragmentShader.fsh",GL_FRAGMENT_SHADER );
	program = glCreateProgram();	
	free (su);
	
	glAttachShader(program,vShader);
	glAttachShader(program,fShader);
    
	glLinkProgram(program);
	
	GLint linked;
	
	glGetProgramiv(program,GL_LINK_STATUS, &linked);
	if (!linked)
	{
		
		GLint logLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		
		if (logLength > 0)
		{
			GLchar *log = (GLchar *)malloc(logLength);
			glGetProgramInfoLog(program, logLength, &logLength, log);
			cout <<"backProgram log: "<< log;
			free(log);
		}
		
		
		
	}
	
	glUseProgram(program);
	
    
    GLenum errCode;
    errCode = glGetError();
    if (errCode != GL_NO_ERROR) 
    {
        if (errCode == GL_INVALID_ENUM)cout << "invalid enumeration" ;
        if (errCode == GL_INVALID_VALUE)cout << "invalid value" ;
        if (errCode == GL_INVALID_OPERATION)cout << "invalid operation" ;
        if (errCode == GL_OUT_OF_MEMORY)cout << "invalid out of memory" ;
        
    }
    objectMatrixLocation =glGetUniformLocation(program, "objectMatrix");
    worldMatrixLocation =glGetUniformLocation(program, "worldMatrix");
    perspMatrixLocation =glGetUniformLocation(program, "perspMatrix");
    
    
	glBindAttribLocation(program, ATTRIB_VERTEX, "position");
	glBindAttribLocation(program, ATTRIB_NORMALS, "normals");
	
    
    
   
    
    
    cout << objectMatrixLocation <<" " <<worldMatrixLocation<<" "<<perspMatrixLocation;
    
    verh =750/1250;
   
    perspectiveisDirty =false;
    
    
    perspectiveMatrix =new Matrix3D();
    perspectiveMatrix->perspProjMat(90,  verh,1, 5000);
    glUniformMatrix4fv(this->perspMatrixLocation,16, 0, perspectiveMatrix->getRawData()  );

    worldMatrix =new Matrix3D;
    
    worldMatrix->translate(0,0,-200);
    glUniformMatrix4fv(this->worldMatrixLocation,16, 0, worldMatrix->getRawData() );
    
    objectMatrix =new Matrix3D;
    objectMatrix->translate(-350,-350,-350);
    glUniformMatrix4fv(this->objectMatrixLocation,16, 0, objectMatrix->getRawData() );
   
    errCode = glGetError();
    if (errCode != GL_NO_ERROR) 
    {
        if (errCode == GL_INVALID_ENUM)cout << "invalid enumeration" ;
        if (errCode == GL_INVALID_VALUE)cout << "invalid value" ;
        if (errCode == GL_INVALID_OPERATION)cout << "invalid operation" ;
        if (errCode == GL_OUT_OF_MEMORY)cout << "invalid out of memory" ;
        
    }	
 glUseProgram(0);
  
    //glEnable (GL_BLEND);
    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void MainShaderProgram::enable  ()
{
    glUseProgram(program);
    
   
    
    if(perspectiveisDirty)
    {
        perspectiveMatrix->perspProjMat(40,  verh,1, 1500);
     
        glUniformMatrix4fv(this->perspMatrixLocation,16, 0, perspectiveMatrix->getRawData() );
        perspectiveisDirty =false;
    }
    
    
}
void MainShaderProgram::render(float *vtxBuffer ,int numTris)
{
   
    worldMatrix->identity();
    
    worldMatrix->translate(0,0,-350);
    
    glUniformMatrix4fv(this->perspMatrixLocation,16, 0, perspectiveMatrix->getRawData() );

    glUniformMatrix4fv(this->worldMatrixLocation,16, 0, worldMatrix->getRawData());
    glUniformMatrix4fv(this->objectMatrixLocation,16, 0, objectMatrix->getRawData() );
    
	glEnableVertexAttribArray(ATTRIB_VERTEX);
	glEnableVertexAttribArray(ATTRIB_NORMALS);
	
	glVertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, 0, 6*sizeof(GLfloat), vtxBuffer);
	vtxBuffer+=3;
	glVertexAttribPointer(ATTRIB_NORMALS, 3, GL_FLOAT, 0, 6*sizeof(GLfloat), vtxBuffer);
	
    glDrawArrays(GL_TRIANGLES, 0, numTris*3);
    
    GLenum errCode;
    errCode = glGetError();
    if (errCode != GL_NO_ERROR) 
    {
        if (errCode == GL_INVALID_ENUM)cout << "invalid enumeration" ;
        if (errCode == GL_INVALID_VALUE)cout << "invalid value" ;
        if (errCode == GL_INVALID_OPERATION)cout << "invalid operation" ;
        if (errCode == GL_OUT_OF_MEMORY)cout << "invalid out of memory" ;
        
    }	
   
    
}

void MainShaderProgram::disable  ()
{
    glUseProgram(0);
    glDisableVertexAttribArray(ATTRIB_VERTEX);
	glDisableVertexAttribArray(ATTRIB_NORMALS);
    
}
void MainShaderProgram::windowResized(int w, int h){
    verh =(float)w/h;
   
  
    
 
    perspectiveisDirty =true ; 
   
}