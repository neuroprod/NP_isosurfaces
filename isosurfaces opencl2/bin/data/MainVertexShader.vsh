
  
//
//
//  Created by Kris Temmerman on 29/11/10.
//  Copyright 2010 Neuro Productions. All rights reserved.
//


uniform mat4 objectMatrix;
uniform mat4 worldMatrix;
uniform mat4 perspMatrix;

attribute vec4 position;
attribute vec4 normals;

varying vec3 normal_var;
varying vec3 eyeVec;
varying vec3 lightDir;
varying vec3 lightDir2;
void main()
{
	
	vec4 localspace  =position*objectMatrix;
    vec4 worldSpace =localspace*worldMatrix;
   normal_var = normals.xyz;

    lightDir = vec3(vec3(-2000.0,-500.0,-500.0) - worldSpace.xyz);
    lightDir2 = vec3(vec3(-1000.0,-1000.0,-500.0) - worldSpace.xyz);
	eyeVec = -worldSpace.xyz;
    gl_Position =worldSpace*perspMatrix ;
}