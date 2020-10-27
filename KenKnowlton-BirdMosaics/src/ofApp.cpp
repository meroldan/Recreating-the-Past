#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	img.load("canaries.jpg");
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	int rect_dim = 10;
	int rect_startx = 1;
	int rect_starty = 1;
		
	for (int i = rect_dim/2; i < img.getWidth(); i += rect_dim+1) {
		for (int j = rect_dim/2; j < img.getHeight(); j += rect_dim + 1) {
			int dice = 255;
			ofColor color = img.getColor(i, j);
			float brightness = color.getBrightness();
			int colorsplit = ofMap(brightness, 0, 255, 0, 30);

			//set the colors
			if (colorsplit <= 6)
			{				
				//white
				ofSetColor(218, 210, 216);
				dice = 0;
			}

			else if (colorsplit <= 12)
			{
				//blue
				ofSetColor(69, 73, 204);				
			}

			else if (colorsplit <= 18)
			{
				//green
				ofSetColor(43, 137, 87);
			}

			else if (colorsplit <= 24)
			{
				//yellow
				ofSetColor(195, 183, 38);
				dice = 0;
			}

			else if (colorsplit <= 30)
			{
				//red
				ofSetColor(185, 41, 63);
			}

			ofDrawRectangle(rect_startx, rect_starty, rect_dim, rect_dim);

			//set the dice based on gradient within each color 
			ofSetColor(dice);

			//dice 1
			if (colorsplit % 6 == 0) {
				ofDrawCircle(rect_startx+5, rect_starty +5, 1);
			}

			//dice 2
			if (colorsplit % 6 == 1) {
				ofDrawCircle(rect_startx + 8, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 8, 1);
			}

			//dice 3
			if (colorsplit % 6 == 2) {
				ofDrawCircle(rect_startx + 8, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 5, rect_starty + 5, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 8, 1);
			}

			//dice 4
			if (colorsplit % 6 == 3) {
				ofDrawCircle(rect_startx + 2, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 8, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 8, 1);
			}

			//dice 5
			if (colorsplit % 6 == 4) {
				ofDrawCircle(rect_startx + 2, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 5, rect_starty + 5, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 8, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 8, 1);
			}

			//dice 6
			if (colorsplit % 6 == 5) {
				ofDrawCircle(rect_startx + 2, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 2, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 5, 1);
				ofDrawCircle(rect_startx + 2, rect_starty + 8, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 8, 1);
				ofDrawCircle(rect_startx + 8, rect_starty + 5, 1);
			}					   			 			
			rect_starty += rect_dim + 2;
		}
		rect_startx += rect_dim + 2;
		rect_starty = 1;		
	}

	ofSetColor(255);
	//img.draw(0, 0);
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
