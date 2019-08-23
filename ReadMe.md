# ofxColorGradient

[![Build Status](https://travis-ci.org/armadillu/ofxColorGradient.svg?branch=master)](https://travis-ci.org/armadillu/ofxColorGradient)

added in this fork:

    // draw orientation (default is horizontal)
    gradient.setDrawVertical(true);

    // draw gradient direction (invert default direction)
    gradient.setDrawDirFlip(true);
    
Simple OpenFrameworks addon to create linear color gradients 

	ofxColorGradient<ofColor> gradient;
	
	//first, fill in the gradient with colors, left to right
	gradient.addColor( ofColor::red );
	gradient.addColor( ofColor::green );
	gradient.addColor( ofColor::yellow );

	//query the gradient for a color at a specific spot
	ofColor color = gradient.getColorAtPercent(0.2);

	//rinse and repeat to draw the full gradient
	for(float i = 0.0f; i < 1.0f; i+= 0.1f){
		ofSetColor( gradient.getColorAtPercent(i) );
		//draw using that color
	}
	
It also allows creating a gradient from an image.

It also provides Google's [Turbo Rainbow Colormap](https://ai.googleblog.com/2019/08/turbo-improved-rainbow-colormap-for.html), which comes with an Apache-2.0 license.

# License

ofxColorGradient is made available under the [MIT](http://opensource.org/licenses/MIT) license.

It includes Google's [Turbo Rainbow Colormap](https://ai.googleblog.com/2019/08/turbo-improved-rainbow-colormap-for.html), which uses the Apache-2.0 license.