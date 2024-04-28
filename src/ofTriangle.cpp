

#include "ofTriangle.h"
#include "ofGraphics.h"
#include "ofVec2f.h"
#include <vector>

using namespace lp;

ofTriangle::ofTriangle(ofVec2f x, ofVec2f y, ofVec2f z) {

    this->x = x;
    this->y = y;
    this->z = z;
}


std::vector<class ofTriangle> ofTriangle::subdivideBarycentric(ofVec3f coords) {

    ofVec2f p = barycentricToCartesian(coords);

    return {
        ofTriangle(x, y, p),
        ofTriangle(x, z, p),
        ofTriangle(y, z, p)
    };
}

std::vector<lp::ofTriangle> ofTriangle::subdivideRegular() {
    

    ofVec2f p1 = barycentricToCartesian(ofVec3f(0.5, 0.5, 0));
    ofVec2f p2 = barycentricToCartesian(ofVec3f(0.5, 0, 0.5));
    ofVec2f p3 = barycentricToCartesian(ofVec3f(0, 0.5, 0.5));

    return {
        ofTriangle(x, p1, p2),
        ofTriangle(y, p1, p3),
        ofTriangle(z, p2, p3),
        ofTriangle(p1, p2, p3)
    };
}


ofVec2f ofTriangle::barycentricToCartesian(ofVec3f coords) {
    return (x * coords.x) + (y * coords.y) + (z * coords.z);
}

void ofTriangle::draw() {
    ofDrawTriangle(x, y, z);
}