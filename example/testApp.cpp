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

	int w = ofGetWidth();
	int h = ofGetHeight();
	float step = w / 100.0f;
	
	ofMesh m;
	m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	
	for(float i = 0; i < w; i += step){
		float left = i / (float)w;
		ofColor color = gradient.getColorAtPercent(left);
		m.addColor(color);
		m.addVertex(ofVec2f( i, 0) );
		m.addColor(color);
		m.addVertex(ofVec2f( i, h) );
	}
	
	m.draw();
}
