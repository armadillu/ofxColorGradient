#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
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
	ofLoadImage(img, "falseColor.png");

	gradient.loadFromImage(img, 3);

	//or setup as google's turbo https://ai.googleblog.com/2019/08/turbo-improved-rainbow-colormap-for.html
	gradient.setupAsTurbo(10); //with 10 samples

	gradient.setHardMode(false);

}

//--------------------------------------------------------------
void ofApp::draw(){
	gradient.drawDebug(0, 0, ofGetWidth(), ofGetHeight(), 50);
}
