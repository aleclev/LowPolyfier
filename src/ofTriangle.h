#pragma once

#include "ofVec2f.h"
#include "ofVec3f.h"
#include <vector>

namespace lp {
    class ofTriangle {

        public:
            ofTriangle(ofVec2f, ofVec2f, ofVec2f);
            std::vector<ofTriangle> subdivideBarycentric(ofVec3f);
            std::vector<lp::ofTriangle> subdivideRegular();
            ofVec2f barycentricToCartesian(ofVec3f);
            void draw();

        private:
            ofVec2f x, y, z;
    };
}
