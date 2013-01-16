
#include "ofxColorGradient.h"


void ofxColorGradient::addColor( ofColor newColor ){
	gradientBar.push_back(newColor);
}


void ofxColorGradient::reset(){
	gradientBar.clear();
}


int ofxColorGradient::getNumColors(){
	return gradientBar.size();
}


bool ofxColorGradient::replaceColorAtIndex( int index, ofColor newColor ){

	if ( index < gradientBar.size() && index >=0 ){
		gradientBar[index] = newColor;
		return true;
	}else
		return false;
}

void ofxColorGradient::drawDebug( float x, float y, float w, float h){

	int numSteps = 25;
	float step = w / numSteps;
	ofMesh m;
	m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

	for(float i = 0; i <= numSteps; i++){
		ofColor color = getColorAtPercent( i / (float)numSteps );
		m.addColor(color);
		m.addVertex(ofVec2f( x + i * step, y +  0) );
		m.addColor(color);
		m.addVertex(ofVec2f( x + i * step, y + h) );
	}

	m.draw();
}

ofColor ofxColorGradient::getColorAtPercent( float percent ){

	ofColor result;
	int numC = gradientBar.size();
	
	// handle special cases
	if (numC == 0)
		return result;
	else if (numC == 1)
		return gradientBar[0];
	else if ( percent < 0.0f || percent > 1.0f )	//percent has to be in the [0..1] range
		return result;

	int leftColor = (int)floor ( percent * (float)(numC - 1.0f) );
	int rightColor = leftColor + 1.0f;
	float percentPerColor =  1.0f / (numC - 1.0f);
	float aux = (float)leftColor * percentPerColor;
	float percentInRange = 1.0f - (percent - aux) / percentPerColor; //(percent - aux) should always be < 0

	result = gradientBar[leftColor] * percentInRange + gradientBar[rightColor] * (1.0f - percentInRange );
	result.a = gradientBar[leftColor].a * percentInRange + gradientBar[rightColor].a * (1.0f - percentInRange );
	return result;
}




