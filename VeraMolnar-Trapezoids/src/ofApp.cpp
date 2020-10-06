#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//ofSetupOpenGL(1200, 1200, OF_WINDOW);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//set background color
	ofBackground(231, 231, 231);
	//set line color
	ofSetColor(51,51,51);
	//indicate that polygon has no fill
	ofNoFill();
	//set line width
	ofSetLineWidth(4);

	// width of the square
	int square = 60;
	//space in between the squares
	int space = 25;
	//starting point for rectangles
	int start = 430;

	// a, b, c, d are the x-coordinates. e, f are the y-coordinates. holda and holdb are the original values of a and b
	int increment = square + space;
	int a = start;
	int b = a + square;
	int c = b;
	int d = a;
	int e = a;
	int f = a;
	int g = b;
	int h = b;
	int holda = start;
	int holdb = start + square;

	ofSeedRandom(mouseX);
	//int mouse = mouseX;

	//create squares			
	for (int i = 0; i < 12; i++) {
		//outer for loop creates a column of squares
		for (int j = 0; j < 12; j++) {
			//inner for loop creates a row of squares
			ofBeginShape();
			int mouse = mouseX;
			//for the x-coordinates, either add or subtract a random number between 0 and the position of the mouse. 
			// The smaller the mouse coordinate, the less variability. the larger the mouse coordinate, the more variability.
			ofVertex(a - ofRandom(0, mouse), e + ofRandom(0, mouse)*.1);
			ofVertex(b + ofRandom(0, mouse), f + ofRandom(0, mouse)*.1);
			ofVertex(c + ofRandom(0, mouse), g - ofRandom(0, mouse)*.1);
			ofVertex(d - ofRandom(0, mouse), h - ofRandom(0, mouse)*.1);
			ofEndShape(true);
			a += increment;
			b += increment;
			c += increment;
			d += increment;
		}
		//reset the value of x coordinates to create the next square
		a = holda;
		b = holdb;
		c = holdb;
		d = holda;
		// move on to the next row
		e += increment;
		f += increment;
		g += increment;
		h += increment;
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
