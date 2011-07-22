//
//  ShaderUtil.m
//  
//
//  Created by Kris Temmerman on 10/12/10.
//  Copyright 2010 Neuro Productions. All rights reserved.
//
#include "ShaderUtil.h"


GLuint ShaderUtil::getShader (string name, GLenum type)
{

	
	
	string *typeName;
	string *pathName;
	
	GLuint shader; 
	
	string shaderPath  = ofToDataPath(name);
	
	char *vertexName =(char*)   shaderPath.data();
	
	//cout << vertexName <<"huuue";
	const GLchar *source = NULL;
	
	
	source = LoadShaderText(vertexName);
	
	
	
	if (!source)
    {
		cout << "Failed to load  shader" << name;
		return 0;
      
    }
	
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
	
	
	delete source;
	
    GLint logLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0)
    {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetShaderInfoLog(shader, logLength, &logLength, log);
        cout << "Shader compile log:" << log<<"/n";
        free(log);
    }
	
	
	GLint status;
    
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == 0)
    {
		 cout << "Shader faild"<<"/n";
        glDeleteShader(shader);
        return 0;
    }
	return shader ; 

}

GLchar * ShaderUtil::LoadShaderText(const char *fileName)
{
    GLchar *shaderText = NULL;
    GLint shaderLength = 0;
    FILE *fp;
	
    fp = fopen(fileName, "r");
	
    if (fp != NULL)
    {
        while (fgetc(fp) != EOF)
        {
            shaderLength++;
        }
        rewind(fp);
        shaderText = (GLchar *)malloc(shaderLength+1);
        if (shaderText != NULL)
        {
            fread(shaderText, 1, shaderLength, fp);
        }
        shaderText[shaderLength] = '\0';
        fclose(fp);
    }
	
    return shaderText;
}
