#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "isoSurface.h"
#import "MainShaderProgram.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
 
    MainShaderProgram * program;

    int boxsize;

        ofImage screen;
   
        vector<Particles> particles;

        isoSurface mesh;
    float mouseX;
    float mouseY;
 
     
};
