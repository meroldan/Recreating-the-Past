#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	//thanks @NickHardeman for this color array structure @ the Forum!
	
	
	colors[0] = ofColor(59, 23, 51);
	colors[1] = ofColor(73, 109, 165);
	colors[2] = ofColor(31, 76, 17);
	colors[3] = ofColor(123, 161, 100);
	colors[4] = ofColor(232, 219, 78);
	colors[5] = ofColor(201, 155, 77);
	colors[6] = ofColor(184, 113, 47);
	colors[7] = ofColor(164, 51, 53);
	colors[8] = ofColor(85, 5, 8);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float x;
	float y;
	float angle = 0;
	int radius;
	int amount;
	int density;
	int posx;
	int posy;
	//start with angle 0
	float motion = 0;
	//how much to add to each main circle
	int xadd = 100;
	int yadd = 900;
	//this number scales the sine wave. the smaller the flatter
	int multiplier = 75;
	//density of the first ring
	int reduce = 5;
	//these variables are to reverse the colors in the sin positioning
	int reverse = 0;
	int position = 0;

	//this for loop is for the general circles. Values are reset in the beginning
	for (int i = 0; i < 25; i++) {
		radius = 200;
		int amount = 361;
		reduce = 1;		
		posx = xadd + multiplier * sin(ofDegToRad(motion));
		posy = yadd + multiplier * cos(ofDegToRad(motion));
		ofSetColor(colors[i - position * reverse]);
		motion += 45;

		if (i == 8) {
			reverse = 2;
		}
		if (i >= 8 && i < 16) {
			reverse = +2;
			position++;
		}
		if (i == 16) {
			reverse = 16;
			position = 1;
		}
		//this for loop is for creating rings around each main circle
		for (int r = 1; r < 750; r++) {
			//this for loop is for adding circles around each ring
			for (int a = 1; a < 2*amount; a += 2) {
				//density is controlled by increasing the upper bound of the random number generation,thus reducing density of particles each time
				density = (int)ofRandom(0, reduce);
				if (density == 0) {
					x = posx + radius * cos(ofDegToRad(angle));
					y = posy + radius * sin(ofDegToRad(angle));
					ofDrawCircle(x, y, 2);
				}
				//alter the angle slightly so pattern doesnt look repetitive but still looks circular
				angle += ofRandom(2, 2.5);
			}
			//change the upper bound of the upper bound of the random number generator every couple of rings
			if (r % 5 == 0) {
				reduce++;
			}
			// increase the ring of each radius, and decrease the amount of circles around the ring
			radius +=4;
			amount -= 1;
		}
		//translate in the x axis to center
		xadd += 120;
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
