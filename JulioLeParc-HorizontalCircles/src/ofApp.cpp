#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	//thanks @NickHardeman forthis color array structure @ the Forum!

	//colors[0] = ofColor(85, 5, 8);
	//colors[1] = ofColor(164, 51, 53);
	//colors[2] = ofColor(184, 113, 47);
	//colors[3] = ofColor(201, 155, 77);
	//colors[4] = ofColor(232, 219, 78);
	//colors[5] = ofColor(123, 161, 100);
	//colors[6] = ofColor(31, 76, 17);
	//colors[7] = ofColor(24, 34, 88);
	//colors[8] = ofColor(59, 23, 51);

	colors[8] = ofColor(59, 23, 51);
	colors[7] = ofColor(24, 34, 88);
	colors[6] = ofColor(31, 76, 17);
	colors[5] = ofColor(123, 161, 100);
	colors[4] = ofColor(232, 219, 78);
	colors[3] = ofColor(201, 155, 77);
	colors[2] = ofColor(184, 113, 47);
	colors[1] = ofColor(164, 51, 53);
	colors[0] = ofColor(85, 5, 8);
	
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
	int posx = 2100;
	int reduce = 1;

	for (int i = 0; i < 9; i++) {		
		posx -= 100;
		radius = 400;
		int amount = 361;
		ofSetColor(colors[i]);
		reduce = 1;
		for (int r = 1; r < 1000; r++) {			
			for (int a = 1; a < 2*amount; a += 2) {
				density = (int)ofRandom(0, reduce);
				if (density == 0) {
					x = posx + radius * cos(ofDegToRad(angle));
					y = 900 + radius * sin(ofDegToRad(angle));
					ofDrawCircle(x, y, 3);
				}
				angle += ofRandom(2, 2.1);
			}
			if (r % 10 == 0) {
				reduce++;
			}
			radius += 2;
			amount -= 1;
		}
	
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
