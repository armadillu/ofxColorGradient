#pragma once

#include "ofMain.h"

template <class CT> /*CT ofColor or ofFloatColor*/
class ofxColorGradient {

public:

	void loadFromImage(const ofPixels & img, int skipCount); /// supply an image to be scanned, see example

	void addColor(const CT & newColor){ gradientBar.push_back(newColor); } /// colors are added from left to right; so add wisely!
	void removeLastColor(){ gradientBar.pop_back(); }
	void reset() { gradientBar.clear(); } /// fully empties the gradient bar

	bool replaceColorAtIndex(int index, CT newColor);
	int getNumColors() const { return gradientBar.size(); }

	void setupAsTurbo(int numSamples); //sets up as a turbo rainbow colormap, empties gradient
	//https://ai.googleblog.com/2019/08/turbo-improved-rainbow-colormap-for.html

	void setHardMode(bool h){ hardMode = h;} //disables color interpolation between supplied colors

	//percent[0..1] defines the whole range of the gradient bar, 0 being left, 1 being right
	CT getColorAtPercent(float pct) const; //this will interpolate colors giving you the best quality, at cost of cpu time
	CT & getColorCacheAtPercent(float pct); //note that this will not interpolate between colors, and relies on cache to return the closes aprox
	CT & getColorCacheAtPercent_01(float pct); ///no safety checks - make sure pct is [0..1] or YOU WILL CRASH!

	void createCache(int numSamples); //call this before using any of the getColorCache*() calls
									//note that whenever you modify the gradient, you must re-create the cache yourself!

	void drawDebug(float x, float y, float w, float h, int numSteps = 25, bool bDrawDirFlip = false, bool bDrawVertical = false) const;

protected:

	std::vector<CT> gradientBar;
	std::vector<CT> cache;

	bool hardMode = false; //if true, there will be no interpolation between colors

	ofxColorGradient<CT> createTurboGradient(); //create a gradient with the 256 colors included in the Turbo Gradient
};
