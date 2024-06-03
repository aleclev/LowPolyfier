

#include "ofTriangle.h"
#include "ofGraphics.h"
#include "ofVec2f.h"
#include <algorithm>
#include <vector>

using namespace lp;

ofTriangle::ofTriangle(ofVec2f x, ofVec2f y, ofVec2f z) {

    this->x = x;
    this->y = y;
    this->z = z;
}

std::vector<lp::ofTriangle> ofTriangle::subdivideRandom() {

    return subdivideBarycentric(ofVec3f(ofTriangle::randomBarycentricVec()));
}

ofVec3f ofTriangle::randomBarycentricVec() {
    std::vector<float> breaks = {
        ofRandom(1.0),
        ofRandom(1.0)
    };

    std::sort(breaks.begin(), breaks.end());

    float s = breaks[0];
    float t = breaks[1] - breaks[0];
    float u = 1 - breaks[1];

    return ofVec3f(s, t, u);
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