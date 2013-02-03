#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);

	//custom gradient design
	gradient.addColor( ofColor::black );
	gradient.addColor( ofColor::red );
	gradient.addColor( ofColor::green );
	gradient.addColor( ofColor::yellow );
	gradient.addColor( ofColor::blue );
	gradient.addColor( ofColor::magenta );
	gradient.addColor( ofColor::cyan );
	gradient.addColor( ofColor::white );
	gradient.addColor( ofColor::black );

	//empty
	gradient.reset();

	//or load from an image
	ofImage img;
	img.loadImage("falseColor.png");
	gradient.loadFromImage(img, 3);

}

//--------------------------------------------------------------
void testApp::draw(){
	gradient.drawDebug(0, 0, ofGetWidth(), ofGetHeight());
}
