#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(25);
	ofBackground(50 ,50,50);
    
    
    
    
	ofSetVerticalSync(true);
	

	glEnable(GL_DEPTH_TEST);

    boxsize = 700;

    particles.assign(20, Particles());
    for(int i=0; i<particles.size(); ++i) {
        particles [i].boxsize = boxsize;
        particles [i].setup();
    }
program =new MainShaderProgram();
    
   
    mesh = isoSurface();
    mesh.gridsize = boxsize;
    mesh.resolution =50;
    mesh.isoValue =0.0017;
    mesh.particles = particles;
    mesh.setup();
  
}

//--------------------------------------------------------------
void testApp::update(){

    int i;
    
   
    int numPoints =particles.size();
     

    for( i=0; i<numPoints; ++i) 
    {
        Particles  *part =  &particles[i];
        
        part->update();
              
    
    }
         //particles[i].update();
    
    mesh.particles = particles;
    mesh.update();
    
  
}

//--------------------------------------------------------------
void testApp::draw(){
  
    /*  
       ofPushMatrix();
            ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
            ofRotateY(ofGetFrameRate()); 
            ofRotateX(ofGetFrameRate()/3);
            ofPushMatrix();
                ofTranslate(-boxsize*.5, -boxsize*.5, -boxsize*.5);

                mesh.draw();

            ofPopMatrix();
       ofPopMatrix();
    */
    program->enable();
    
    program->render(mesh.openglbuffer,mesh.numTriangles);
    program->disable();
    delete [] mesh.openglbuffer;
	glColor3f(1,1,1);
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   
   // ofToggleFullscreen();
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
    program->windowResized(w, h);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
