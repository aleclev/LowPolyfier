#include "ofApp.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofTriangle.h"
#include "ofVec2f.h"
#include <set>

//--------------------------------------------------------------
void ofApp::setup(){
    ofVec2f topLeft(0, 0);
    ofVec2f topRight(ofGetWidth(), 0);
    ofVec2f bottomLeft(0, ofGetHeight());
    ofVec2f bottomRight(ofGetWidth(), ofGetHeight());
    ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);

    triangles = {
        lp::ofTriangle(topLeft, topRight, center),
        lp::ofTriangle(topRight, bottomRight, center),
        lp::ofTriangle(bottomRight, bottomLeft, center),
        lp::ofTriangle(bottomLeft, topLeft, center),
    };

    ofNoFill();

    //ofSetRandomColor();

    ofAppRandomSubdivide(lp::ofTriangle(topLeft, topRight, center), 0);
    ofAppRandomSubdivide(lp::ofTriangle(topRight, bottomRight, center), 0);
    ofAppRandomSubdivide(lp::ofTriangle(bottomRight, bottomLeft, center), 0);
    ofAppRandomSubdivide(lp::ofTriangle(bottomLeft, topLeft, center), 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //if (skipDraw) return;

    for (auto triangle: triangles) {
        //ofSetRandomColor();
        triangle.draw();
    }

    skipDraw = true;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if (button == 0) {
        maxDepth++;
        triangles.clear();
        setup();
    }
    else if (button == 2) {
        maxDepth--;
        triangles.clear();
        setup();
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

ofVec3f ofApp::randomBarycentricVec() {

    double x = ofRandom(1);
    double y = ofRandom(1);
    double z = ofRandom(1);

    double sum = x+y+z;

    //return ofVec3f(x/sum, y/sum, z/sum);

    return ofVec3f(0.333, 0.333, 0.334);

}

void ofApp::ofAppRandomSubdivide(class lp::ofTriangle tri, int depth) {

    if (depth >= maxDepth) {
        triangles.push_back(tri);
        return;
    }
    
    for (auto tri1: tri.subdivideRandom()) {
        ofAppRandomSubdivide(tri1, depth + 1);
    }
}

void ofApp::ofSetRandomColor() {

    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
}