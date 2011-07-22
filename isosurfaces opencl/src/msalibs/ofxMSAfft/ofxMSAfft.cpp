/*
 *  ofxMSAfft.cpp
 *  fft
 *
 *  Created by Mehmet Akten on 08/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxMSAfft.h"


ofxMSAfft::ofxMSAfft() {
	avgPower = 0;
	buffer = 0;
	phase = 0;
	power = 0;
	freq = 0;
}

ofxMSAfft::~ofxMSAfft() {
	clear();
}


void ofxMSAfft::clear() {
	if(buffer) delete[] buffer;
	if(phase) delete[] phase;
	if(power) delete[] power;
	if(freq) delete[] freq;
}


void ofxMSAfft::setup(int samplingRate, int bufferSize, int nOutputs, int nInputs, int nBuffers, int nAveragesPerOctave) {
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// BUFFER_SIZE samples per buffer
	// 4 num buffers (latency)
	
	this->bufferSize = bufferSize;
	
	ofSoundStreamSetup(nOutputs, nInputs, this, samplingRate, bufferSize, nBuffers);	
	FFTanalyzer.setup(samplingRate, bufferSize/2, nAveragesPerOctave);
	FFTanalyzer.peakHoldTime = 0;			// hold longer
	FFTanalyzer.peakDecayRate = 0.99f;		// decay slower
	FFTanalyzer.linearEQIntercept = 0.9f;	// reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f;		// increasing gain at higher frequencies
	
	buffer	= new float[bufferSize];
	phase	= new float[bufferSize];
	power	= new float[bufferSize];
	freq	= new float[bufferSize/2];
	
	audioMult = 1;
	
//	ofAddListener(ofEvents.audioReceived, this, &ofxMSAfft::_audioReceived);
}

void ofxMSAfft::update() {
//	printf("ofxMSAfft::update %i\n", ofGetFrameNum());
	myfft.powerSpectrum(0,bufferSize>>1, buffer, bufferSize, freq, phase, power, &avgPower);
	avgPower *= audioMult;
	if(avgPower>1) avgPower = 1;
	FFTanalyzer.audioMult = audioMult;
	FFTanalyzer.calculate(freq);
}

void ofxMSAfft::drawBins(float x, float y, float w, float h) {
	ofSetColor(0xffffff);
	int size = (bufferSize>>1) - 1;
	float iw = w/size;
	for (int i = 0; i < size; i++){
		ofRect(x+(i*iw), y, iw, -freq[i] * h);
	}
}

void ofxMSAfft::drawAvg(float x, float y, float w, float h) {
	float iw = w/FFTanalyzer.nAverages;
	
	ofSetColor(0xffffff);
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		ofRect(x+(i*iw), h + y, iw , -FFTanalyzer.averages[i] * h);
	}
	
	ofSetColor(0xff0000);
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		ofRect(x+(i*iw), h + y - FFTanalyzer.peaks[i] * h, iw, -6);
	}
}

void ofxMSAfft::draw(float x, float y) {
	drawAvg(x, y, getWidth(), getHeight());
}

void ofxMSAfft::draw(float x, float y, float w, float h) {
	drawAvg(x, y, w, h);
}

float ofxMSAfft::getWidth() {
	return 1000;
}

float ofxMSAfft::getHeight() {
	return 1000;
}

float* ofxMSAfft::getAverages() {
	return FFTanalyzer.averages;
}

float* ofxMSAfft::getPeaks() {
	return FFTanalyzer.peaks;
}

int ofxMSAfft::getNumAverages() {
	return FFTanalyzer.nAverages;
}


//void ofxMSAfft::audioReceived(ofAudioEventArgs &e) {
void ofxMSAfft::audioReceived(float * input, int bufferSize, int nChannels) {
//	printf("ofxMSAfft::audioReceived %i\n", ofGetFrameNum());
	buffer = input;
//	memcpy(buffer, input, bufferSize);
//	float avg_power = 0.0f;	
//	myfft.powerSpectrum(0,bufferSize>>1, buffer, bufferSize, freq, phase, power, &avg_power);
//	FFTanalyzer.calculate(freq);
	
}

//void ofxMSAfft::_audioReceived(ofAudioEventArgs &e) {
//	printf("ofxMSAfft::_audioReceived %i\n", ofGetFrameNum());
//	audioReceived(e.buffer, e.bufferSize, e.nChannels);
//}

