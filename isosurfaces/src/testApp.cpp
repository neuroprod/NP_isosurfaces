#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    //ofSetFrameRate(20);
	ofBackground(0,0,0);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();

	glEnable(GL_DEPTH_TEST);

    boxsize = 700;

    particles.assign(25, Particles());
    for(int i=0; i<particles.size(); ++i) {
        particles [i].boxsize = boxsize;
        particles [i].setup();
    }

    mesh = isoSurface();
    mesh.gridsize = boxsize;
    mesh.resolution =50;
    mesh.particles = particles;
    mesh.setup();
}

//--------------------------------------------------------------
void testApp::update(){

   // if(ofGetFrameNum()!=0 )return;
    int i;
    int numPoints =particles.size();
    for( i=0; i<numPoints; ++i) particles[i].update();
mesh.particles = particles;
    //mesh.resolution = (float)mouseX / (float)ofGetWidth() * 100;
   // mesh.isoValue = (float)mouseY / (float)ofGetHeight() * 100;
   // mesh.update(points);
    mesh.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();

        ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);

        //ofEnableLighting();
        //light.enable();
        //light.setPosition(boxsize, boxsize, boxsize);

     ofRotateX((float)ofGetFrameNum()*0.3); //mouseY);
       ofRotateY((float)ofGetFrameNum()*0.1); //mouseX);

        ofPushMatrix();
            ofTranslate(-boxsize*.5, -boxsize*.5, -boxsize*.8);

         //   for(int i=0; i<points.size(); ++i) points[i].draw();
            mesh.draw();

        ofPopMatrix();


        light.disable();
        ofDisableLighting();

        /*
        ofSetColor(255,255,255,50);
        ofNoFill();
        ofBox(boxsize);
        */

    ofPopMatrix();

    // draw framerate
	glColor3f(1,1,1);
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='s' ){
        screen.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        char fileName[255];
        sprintf(fileName, "snapshot-%0.4i.png", ofGetFrameNum());
        screen.saveImage(fileName);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
