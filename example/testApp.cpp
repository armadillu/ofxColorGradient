#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	
	gradient.addColor( ofColor::black );
	gradient.addColor( ofColor::red );
	gradient.addColor( ofColor::green );
	gradient.addColor( ofColor::yellow );
	gradient.addColor( ofColor::blue );
	gradient.addColor( ofColor::magenta );
	gradient.addColor( ofColor::cyan );
	gradient.addColor( ofColor::white );
	gradient.addColor( ofColor::black );

}

//--------------------------------------------------------------
void testApp::draw(){
	gradient.drawDebug(0, 0, ofGetWidth(), ofGetHeight());
}
