#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		ofxColorGradient<ofColor> gradient;
};
