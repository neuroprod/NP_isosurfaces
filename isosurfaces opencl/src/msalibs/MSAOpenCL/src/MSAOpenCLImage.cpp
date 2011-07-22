/***********************************************************************
 
 OpenCL Image Memory Object
 You can either instantiate this class directly. e.g.:
 OpenCLImage myImage;
 myImage.initWithGLTexture(320, 240, GL_RGBA);
 
 or create it via Instead use OpenCL::createImageXXXX. e.g.:
 OpenCLImage *myImage = openCL.createImageWithTexture(320, 240, GL_RGBA);
 (this method is here for backwards compatibility with previous versions of OpenCL)
 
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


#include "MSAOpenCL.h"
#include "MSAOpenCLImage.h"

namespace MSA { 
	
	OpenCLImage::OpenCLImage() {
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::OpenCLImage");
		texture = NULL;
	}
	
	
	void OpenCLImage::initWithoutTexture(int w,
										 int h,
										 int d,
										 cl_channel_order imageChannelOrder,
										 cl_channel_type imageChannelDataType,
										 cl_mem_flags memFlags,
										 void *dataPtr,
										 bool blockingWrite)
	{
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::initWithoutTexture");
		
		init(w, h, d);
		
		cl_int err;
		cl_image_format imageFormat;
		imageFormat.image_channel_order		= imageChannelOrder;
		imageFormat.image_channel_data_type	= imageChannelDataType;
		
		int image_row_pitch = 0;	// TODO
		int image_slice_pitch = 0;
		
		if(clMemObject) clReleaseMemObject(clMemObject);
		
		if(depth == 1) {
			clMemObject = clCreateImage2D(pOpenCL->getContext(), memFlags, &imageFormat, width, height, image_row_pitch, memFlags & CL_MEM_USE_HOST_PTR ? dataPtr : NULL, &err);
		} else {
			clMemObject = clCreateImage3D(pOpenCL->getContext(), memFlags, &imageFormat, width, height, depth, image_row_pitch, image_slice_pitch, memFlags & CL_MEM_USE_HOST_PTR ? dataPtr : NULL, &err);
		}
		assert(err != CL_INVALID_CONTEXT);
		assert(err != CL_INVALID_VALUE);
		assert(err != CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
		assert(err != CL_INVALID_IMAGE_SIZE );
		assert(err != CL_INVALID_HOST_PTR);
		assert(err != CL_IMAGE_FORMAT_NOT_SUPPORTED);
		assert(err != CL_MEM_OBJECT_ALLOCATION_FAILURE);
		assert(err != CL_INVALID_OPERATION);
		assert(err != CL_OUT_OF_HOST_MEMORY );
		assert(err == CL_SUCCESS);
		assert(clMemObject);
		
		if(dataPtr) {
			write(dataPtr, blockingWrite);
		}
		
		if(texture) delete texture;
		texture = NULL;
	}
	
	
	
	void OpenCLImage::initFromTexture(ofTexture &tex,
									  cl_mem_flags memFlags,
									  int mipLevel)
	{
		
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::initFromTexture");
		
		init(tex.getWidth(), tex.getHeight(), 1);
		
		cl_int err;
		if(clMemObject) clReleaseMemObject(clMemObject);
		
		clMemObject = clCreateFromGLTexture2D(pOpenCL->getContext(), memFlags, tex.getTextureData().textureTarget, mipLevel, tex.getTextureData().textureID, &err);
		assert(err != CL_INVALID_CONTEXT);
		assert(err != CL_INVALID_VALUE);
		//	assert(err != CL_INVALID_MIPLEVEL);
		assert(err != CL_INVALID_GL_OBJECT);
		assert(err != CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
		assert(err != CL_OUT_OF_HOST_MEMORY);
		assert(err == CL_SUCCESS);
		assert(clMemObject);
		
		texture = &tex;
	}
	
	
	
	
	void OpenCLImage::initWithTexture(int w,
									  int h,
									  int glTypeInternal,
									  cl_mem_flags memFlags)
	{
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::initWithTexture");
		
		if(texture) delete texture;
		texture = new ofTexture();
		texture->allocate(w, h, glTypeInternal);
		initFromTexture(*texture, memFlags, 0);
		reset();
	}
	
	
	
	void OpenCLImage::init(int w, int h, int d) {
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::init()");
		
		if(d<0) d = 1;
		
		this->width			= w;
		this->height		= h;
		this->depth			= d;
		
		origin[0] = 0; 
		origin[1] = 0;
		origin[2] = 0;
		
		region[0] = width; 
		region[1] = height;
		region[2] = depth;
		
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::init " + ofToString(width) + ", " + ofToString(height) + ", " + ofToString(depth));
		
		memoryObjectInit();
	}
	
	void OpenCLImage::reset() {
		ofLog(OF_LOG_VERBOSE, "OpenCLImage::reset()");
		int numElements = width * height * 4; // TODO, make real
		if(texture->getTextureData().pixelType == GL_FLOAT) numElements *= sizeof(cl_float);
		char *data = new char[numElements];
		memset(data, 0, numElements);
		write(data, true);
		delete []data;
	}
	
	
	void OpenCLImage::read(void *dataPtr, bool blockingRead, size_t *pOrigin, size_t *pRegion, size_t rowPitch, size_t slicePitch) {
		if(pOrigin == NULL) pOrigin = origin;
		if(pRegion == NULL) pRegion = region;
		
		cl_int err = clEnqueueReadImage(pOpenCL->getQueue(), clMemObject, blockingRead, pOrigin, pRegion, rowPitch, slicePitch, dataPtr, 0, NULL, NULL);
		assert(err == CL_SUCCESS);
	}
	
	
	void OpenCLImage::write(void *dataPtr, bool blockingWrite, size_t *pOrigin, size_t *pRegion, size_t rowPitch, size_t slicePitch) {
		if(pOrigin == NULL) pOrigin = origin;
		if(pRegion == NULL) pRegion = region;
		
		cl_int err = clEnqueueWriteImage(pOpenCL->getQueue(), clMemObject, blockingWrite, pOrigin, pRegion, rowPitch, slicePitch, dataPtr, 0, NULL, NULL);
		assert(err == CL_SUCCESS);
	}
	
	void OpenCLImage::copyFrom(OpenCLImage &srcImage, size_t *pSrcOrigin, size_t *pDstOrigin, size_t *pRegion) {
		if(pSrcOrigin == NULL) pSrcOrigin = origin;
		if(pDstOrigin == NULL) pDstOrigin = origin;
		if(pRegion == NULL) pRegion = region;
		
		cl_int err = clEnqueueCopyImage(pOpenCL->getQueue(), srcImage.getCLMem(), clMemObject, pSrcOrigin, pDstOrigin, pRegion, 0, NULL, NULL);
		assert(err == CL_SUCCESS);
	}
	
	
	
	ofTexture &OpenCLImage::getTexture() {
		return *texture;
	}
	
	
	void OpenCLImage::draw(float x, float y) {
		if(texture) texture->draw(x, y);
	}
	
	void OpenCLImage::draw(float x, float y, float w, float h) {
		if(texture) texture->draw(x, y, w, h);
	}
}

