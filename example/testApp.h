#pragma once

#include "ofMain.h"
#include "ofxColorGradient.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		ofxColorGradient<ofColor> gradient;
};
