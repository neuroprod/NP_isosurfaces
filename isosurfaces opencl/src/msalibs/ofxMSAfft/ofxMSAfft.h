/*
 *  ofxMSAfft.h
 *  fft
 *
 *  Created by Mehmet Akten on 08/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

#include "FFT.h"
#include "fftOctaveAnalyzer.h"

class ofxMSAfft : public ofBaseApp, public ofBaseDraws {
public:
	
	ofxMSAfft();
	~ofxMSAfft();
	
	void setup(int samplingRate = 44100, int bufferSize = 256, int nOutputs = 0, int nInputs = 1, int nBuffers = 4, int nAveragesPerOctave = 1);
	void update();
	void drawBins(float x, float y, float w, float h);
	void drawAvg(float x, float y, float w, float h);
	
	void draw(float x, float y);
	void draw(float x, float y, float w, float h);
	
	float getWidth();
	float getHeight();
	float* getAverages();
	float* getPeaks();
	int getNumAverages();

	void audioReceived(float * input, int bufferSize, int nChannels); 
//	void _audioReceived(ofAudioEventArgs &e); 

	
	void clear();
	
	FFTOctaveAnalyzer FFTanalyzer;
	FFT		myfft;
	
	float avgPower;
	float audioMult;
	float *buffer;
	float *phase;
	float *power;
	float *freq;
	
	int bufferSize;
	int nChannels;
};

