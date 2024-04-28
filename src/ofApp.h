#pragma once

#include "ofMain.h"
#include "ofTriangle.h"
#include "ofVec2f.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:

		ofVec3f randomBarycentricVec();
		std::vector<lp::ofTriangle> triangles;
		void ofSetRandomColor();
		void ofAppRandomSubdivide(lp::ofTriangle tri, int depth);
		bool skipDraw;
		int maxDepth = 0;
};
