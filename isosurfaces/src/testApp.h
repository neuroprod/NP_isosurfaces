#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "isoSurface.h"

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



        int boxsize;

        ofLight light;
        ofImage screen;

        vector<Particles> particles;

        isoSurface mesh;


        /*
        ofVBO myVbo;
        ofMesh myMesh;

        // ad vertex
        myMesh.addColor( ofFloatColor(1.,1.,1.,1.) );
        myMesh.addVertex( ofVec3f(1.,1.,1.) );

        // pass mesh to vbo
        myVbo.setMesh(myMesh, GL_STATIC_DRAW);

        customDraw() {
            setScale(100);
            glDisable(GL_CULL_FACE);

            myVbo.draw(GL_QUADS, 0, 4); // 0=start, 4=aantal vertex points

        }

        depthBuffer >> opvragen, kan gebruikt worden als heightmap voor bumpMapping

        gl_modelViewProjectionMatrix = 2D projectie van de 3D wereld
        gl_Vertex = 3D wereld coordinaten

        */
};
