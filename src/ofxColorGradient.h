

#ifndef _OFX_COLOR_GRADIENT_H
#define _OFX_COLOR_GRADIENT_H

#include "ofMain.h"

class ofxColorGradient{

	public:

		void addColor(ofColor newColor); ///colors are added from left to right; so add wisely!
		void reset();					 ///fully empties the gradient bar
		bool replaceColorAtIndex(int index, ofColor newColor);
		int getNumColors();

		ofColor getColorAtPercent(float percent);	//percent[0..1] defines the whole range of the gradient bar, 0 being left, 1 being right

		void drawDebug( float x, float y, float w, float h);
	private:

		vector <ofColor>  gradientBar;
		
};

#endif


