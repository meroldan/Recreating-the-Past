#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//background color
	ofBackground(11, 24, 19);
	//line width
	ofSetLineWidth(9);

	//variable to get time
	float time = 40 * ofGetElapsedTimef();

	//starting angle of white sequence and pink sequence. W is for white, P is for pink
	float wangle = 10 * time;
	float pangle = 10 * time;

	//inner radius is for the sphere that rotates inside the big circle, which is out_radius
	int in_radius = 30;
	int out_radius = 400;

	//midpoint of the canvas
	float xorigin = ofGetWidth() / 2;
	float yorigin = ofGetHeight() / 2;

	// origins to be modified for the small and large circles
	float wxorigin = xorigin;
	float pxorigin = xorigin;
	
	//starting amplitude of spiral
	float spiral = 40;

	for (int j = 0; j < 3; j++)
	{
		//background clears after every loop. Outer loop creates small circle, inner loop creates the lines that connect small with the big circle
		ofBackground(11, 24, 19);
			//white circle spiral
			float wx = (spiral* cos(ofDegToRad(-wangle)) + wxorigin);
			float wy = (spiral* sin(ofDegToRad(-wangle)) + yorigin);

			//pink circle spiral
			float px = (spiral* cos(ofDegToRad(pangle)) + pxorigin);
			float py = (spiral* sin(ofDegToRad(pangle)) + yorigin);
	
			//this for loop draws the 31 lines
			for (int i = 0; i < 31; i++) {
				float wa = (in_radius * cos(ofDegToRad(wangle)) + wx);
				float wb = (in_radius * sin(ofDegToRad(wangle)) + wy);
				float wc = (out_radius * cos(ofDegToRad(wangle)) + wxorigin);
				float wd = (out_radius * sin(ofDegToRad(wangle)) + yorigin);
				ofSetColor(221,216,203);
				ofDrawLine(wa, wb, wc, wd);
				wangle -= (360 / 50);
				wxorigin += .2;

				float pa = (in_radius * cos(ofDegToRad(pangle)) + px);
				float pb = (in_radius * sin(ofDegToRad(pangle)) + py);
				float pc = (out_radius * cos(ofDegToRad(pangle)) + pxorigin);
				float pd = (out_radius * sin(ofDegToRad(pangle)) + yorigin);
				ofSetColor(159,84,95);
				ofDrawLine(pa, pb, pc, pd);
				pangle += (360 / 62);
				pxorigin -= 2;
				spiral += 0.009*time;

				in_radius += 1;
				out_radius -= 2;
			}
			//in_radius += 40;
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
