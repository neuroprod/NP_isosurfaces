//
//  ShaderUtil.h
//  UniverseGL
//
//  Created by Kris Temmerman on 10/12/10.
//  Copyright 2010 Neuro Productions. All rights reserved.
//

#ifndef SHADER_UTIL
#define SHADER_UTIL

#include "ofMain.h"

class ShaderUtil{
	
public:
	GLuint getShader (string name, GLenum type);
	GLchar * LoadShaderText(const char *fileName);
};



#endif