/***********************************************************************
 
 Copyright (c) 2008, 2009, Memo Akten, www.memo.tv
 *** The Mega Super Awesome Visuals Company ***
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of MSA Visuals nor the names of its contributors 
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE. 
 *
 * ***********************************************************************/ 

/***************
 DEPENDENCIES:
 - MSACore
 - MSAPingPong
***************/ 



#pragma once

#include "MSACore.h"

#include <OpenCL/Opencl.h>

#include "MSAOpenCLKernel.h"
#include "MSAOpenCLProgram.h"
#include "MSAOpenCLBuffer.h"
#include "MSAOpenCLTypes.h"
#include "MSAOpenCLImage.h"
#include "MSAOpenCLImagePingPong.h"

namespace MSA {
	
	class OpenCL {
	public:
		OpenCL();
		~OpenCL();
		
		static OpenCL *currentOpenCL;
		
		// initializes openCL with the passed in device (leave empty for default)
		void	setup(int clDeviceType = CL_DEVICE_TYPE_GPU, int numDevices = 1);
		void	setupFromOpenGL();
		
		cl_device_id&		getDevice();
		cl_context&			getContext();
		cl_command_queue&	getQueue();
		
		
		// doesn't return until all commands in the queue have been sent
		void	flush();
		
		
		// doesn't return until all commands in the queue have been sent and finished executing
		void	finish();	
		
		
		// load a program (contains a bunch of kernels)
		// returns pointer to the program should you need it (for most operations you won't need this)
		OpenCLProgram*	loadProgramFromFile(string filename, bool isBinary = false);
		OpenCLProgram*	loadProgramFromSource(string programSource);
		
		
		// specify a kernel to load from the specified program
		// if you leave the program parameter blank it will use the last loaded program
		// returns pointer to the kernel should you need it (for most operations you won't need this)
		OpenCLKernel*	loadKernel(string kernelName, OpenCLProgram *program = NULL);
		
		
		
		// create OpenCL buffer memory objects
		// if dataPtr parameter is passed in, data is uploaded immediately
		// parameters with default values can be omited
		OpenCLBuffer*	createBuffer(int numberOfBytes,
									 cl_mem_flags memFlags = CL_MEM_READ_WRITE,
									 void *dataPtr = NULL,
									 bool blockingWrite = CL_FALSE);
		
		// create buffer from the GL Object - e.g. VBO (they share memory space on device)
		// parameters with default values can be omited
		OpenCLBuffer*	createBufferFromGLObject(GLuint glBufferObject,
												 cl_mem_flags memFlags = CL_MEM_READ_WRITE);
		
		
		
		// create OpenCL image memory objects
		// if dataPtr parameter is passed in, data is uploaded immediately
		
		// create a 2D Image with given properties
		// Image is not linked to an OpenGL texture
		// parameters with default values can be omited
		OpenCLImage*		createImage2D(int width,
										  int height,
										  cl_channel_order imageChannelOrder = CL_RGBA,
										  cl_channel_type imageChannelDataType = CL_FLOAT,
										  cl_mem_flags memFlags = CL_MEM_READ_WRITE,
										  void *dataPtr = NULL,
										  bool blockingWrite = CL_FALSE);
		
		// create a 2D Image from the ofTexture passed in (they share memory space on device)
		// parameters with default values can be omited
		OpenCLImage*		createImageFromTexture(ofTexture &tex,
												   cl_mem_flags memFlags = CL_MEM_READ_WRITE,
												   int mipLevel = 0);
		
		
		// create both a 2D Image AND an ofTexture at the same time (they share memory space on device)
		// parameters with default values can be omited
		OpenCLImage*		createImageWithTexture(int width,
												   int height,
												   int glType = GL_RGBA,
												   cl_mem_flags memFlags = CL_MEM_READ_WRITE);
		
		
		
		// parameters with default values can be omited
		OpenCLImage*		createImage3D(int width,
										  int height,
										  int depth,
										  cl_channel_order imageChannelOrder = CL_RGBA,
										  cl_channel_type imageChannelDataType = CL_FLOAT,
										  cl_mem_flags memFlags = CL_MEM_READ_WRITE,
										  void *dataPtr = NULL,
										  bool blockingWrite = CL_FALSE);
		
		
		// retrieve kernel so you can run it or setup params etc.
		OpenCLKernel*	kernel(string kernelName);
		
		
		vector<OpenCLProgram*>	getPrograms() {
			return programs;
		}
		
		map<string, OpenCLKernel*>	getKernels() {
			return kernels;
		}
		
		string getInfoAsString();
		
		struct {
			cl_char		vendorName[1024];
			cl_char		deviceName[1024];
			cl_char		driverVersion[1024];
			cl_char		deviceVersion[1024];
			cl_uint		maxComputeUnits;
			cl_uint		maxWorkItemDimensions;
			size_t		maxWorkItemSizes[32];
			size_t		maxWorkGroupSize;
			cl_uint		maxClockFrequency;
			cl_ulong	maxMemAllocSize;
			cl_bool		imageSupport;
			cl_uint		maxReadImageArgs;
			cl_uint		maxWriteImageArgs;
			size_t		image2dMaxWidth;
			size_t		image2dMaxHeight;
			size_t		image3dMaxWidth;
			size_t		image3dMaxHeight;
			size_t		image3dMaxDepth;
			cl_uint		maxSamplers;
			size_t		maxParameterSize;
			cl_ulong	globalMemCacheSize;
			cl_ulong	globalMemSize;
			cl_ulong	maxConstantBufferSize;
			cl_uint		maxConstantArgs;
			cl_ulong	localMemSize;
			cl_bool		errorCorrectionSupport;
			size_t		profilingTimerResolution;
			cl_bool		endianLittle;
			cl_char		profile[1024];
			cl_char		extensions[1024];		
		} info;
		
		
	protected:	
		
		cl_device_id					clDevice;
		cl_context						clContext;
		cl_command_queue				clQueue;
		
		vector<OpenCLProgram*>		programs;	
		map<string, OpenCLKernel*>	kernels;
		vector<OpenCLMemoryObject*>	memObjects;
		bool							isSetup;
		
		int createDevice(int clDeviceType, int numDevices);
		void createQueue();
	};
	
}