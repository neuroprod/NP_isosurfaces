#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

   ofSetFrameRate(60);
	ofBackground(30 ,30,30);
    
    mouseX =0;
    mouseY =0;
    
	ofSetVerticalSync(false);
	
  
    boxsize = 650;

    particles.assign(25, Particles());
    for(int i=0; i<particles.size(); ++i) {
        particles [i].boxsize = boxsize;
        particles [i].setup();
    }
program =new MainShaderProgram();
    
   
    mesh = isoSurface();
    mesh.gridsize = boxsize;
    mesh.resolution =25;
    mesh.resolutionPass2 =4;
    mesh.isoValue =0.0030;
    mesh.isoValuePass2 =0.0045;
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
       
      
        
        part->update(1,1);
             
    
    }
         //particles[i].update();
    
    mesh.particles = particles;
    mesh.update();
    
  
}

//--------------------------------------------------------------
void testApp::draw(){
  
    
   

  /*
     glDisable (GL_DEPTH_TEST);
      ofPushMatrix();
            ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5);
           ofRotateY(mouseX); 
            ofRotateX(mouseY);
            ofPushMatrix();
                ofTranslate(-boxsize*.5, -boxsize*.5, 0);

                mesh.draw();

            ofPopMatrix();
       ofPopMatrix();*/
glEnable(GL_DEPTH_TEST);
   program->enable();
    
    program->render(mesh.openglbuffer,mesh.numTriangles);
    program->disable();
   }

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   
    if(key=='f' ){ofToggleFullscreen();
     
    ofBackground(0 ,0,0);
    }
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
    mouseX =(float)x;
    mouseY =(float)y;
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
