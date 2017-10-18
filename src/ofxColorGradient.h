

#ifndef _OFX_COLOR_GRADIENT_H
#define _OFX_COLOR_GRADIENT_H

#include "ofMain.h"

template <class ColorType> /*ofColor or ofFloatColor*/
class ofxColorGradient {
  public:
	/// supply an image to be scanned, see example
	void loadFromImage(const ofPixels & img, int skipCount) {
		if(skipCount < 1)
			skipCount = 1;
		int w = img.getWidth();
		int h = img.getHeight();

		for(int i = 0; i < w; i += skipCount) {
			gradientBar.push_back(img.getColor(i, h / 2));
		}
	}

	/// colors are added from left to right; so add wisely!
	void addColor(ColorType newColor) { gradientBar.push_back(newColor); }

	/// fully empties the gradient bar
	void reset() { gradientBar.clear(); }

	bool replaceColorAtIndex(int index, ColorType newColor) {

		if(index < gradientBar.size() && index >= 0) {
			gradientBar[index] = newColor;
			return true;
		} else
			return false;
	}

	int getNumColors() const { return gradientBar.size(); }

	//percent[0..1] defines the whole range of the gradient bar, 0 being left, 1 being right
	ColorType getColorAtPercent(float pct) const {

		ColorType result;
		int numC = gradientBar.size();

		// handle special cases
		if(numC == 0)
			return result;
		else if(numC == 1)
			return gradientBar[0];

		int indexMax = numC - 1;

		if(pct >= 0.0f) {
			if(pct > 1.0f){
				pct = fmod(pct, 1.0f);
			}
		} else {
			pct = 1.0f - fmod(-pct, 1.0f);
		}

		int leftColor = (int)floor(pct * (float)indexMax);
		int rightColor = leftColor + 1;
		if(rightColor > indexMax)
			rightColor = indexMax;

		float percentPerColor = 1.0f / indexMax;

		float percentInRange =
			1.0f - (pct - leftColor * percentPerColor) / percentPerColor; //(percent - aux) should always be < 0
		float iPercentInRange = 1.0f - percentInRange;

		const ColorType &leftC = gradientBar[leftColor];
		const ColorType &rightC = gradientBar[rightColor];

		// this seems much slower !!
		// result = leftC * percentInRange + rightC * iPercentInRange;

		// doing it manually
		result.r = leftC.r * percentInRange + rightC.r * iPercentInRange;
		result.g = leftC.g * percentInRange + rightC.g * iPercentInRange;
		result.b = leftC.b * percentInRange + rightC.b * iPercentInRange;
		result.a = leftC.a * percentInRange + rightC.a * iPercentInRange;

		return result;
	}

	ColorType& getColorCacheAtPercent(float pct) const{

		float pctRemapped = pct;
		if(pctRemapped >= 0.0f) {
			if(pctRemapped > 1.0f){
				pctRemapped = fmod(pct, 1.0f);
			}
		} else {
			pctRemapped = 1.0f - fmod(-pctRemapped, 1.0f);
		}

		int index = pctRemapped * (cache.size() - 1);
		return cache[index];
	}


	///no safety checks - make sure pct is [0..1] or YOU WILL CRASH!
	ColorType getColorCacheAtPercent_01(float pct) const{
		int index = pct * (cache.size() - 1);
		return cache[index];
	}


	void drawDebug(float x, float y, float w, float h, int numSteps = 25) const{

		float step = w / numSteps;
		ofMesh m;
		m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
		m.getVertices().reserve(numSteps * 2);
		m.getColors().reserve(numSteps * 2);

		for(float i = 0; i <= numSteps; i++) {
			ColorType color = getColorAtPercent(i / (float)numSteps);
			m.addColor(color);
			m.addVertex(ofVec3f(x + i * step, y + 0));
			m.addColor(color);
			m.addVertex(ofVec3f(x + i * step, y + h));
		}
		m.draw();
	}

	void createCache(int numSamples) {

		cache.resize(numSamples);

		for(int i = 0; i < numSamples; i++) {
			float pct = i / float(numSamples-1);
			cache[i] = getColorAtPercent(pct);
		}
	}

  private:
	std::vector<ColorType> gradientBar;
	std::vector<ColorType> cache;
};

#endif
