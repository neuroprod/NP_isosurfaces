#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
    window.setGlutDisplayString("rgba double samples>=4 depth"); 
	ofSetupOpenGL(&window, 1250,750, OF_WINDOW);			// <-------- setup the GL context

    //window.setGlutDisplayString("rgba double samples>=4 depth");

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
