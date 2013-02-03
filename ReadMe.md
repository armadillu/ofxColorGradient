Simple of addon to create linear color gradients 

	ofxColorGradient gradient;
	
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
	
