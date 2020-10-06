#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	//populating the array
	for (int t = 0; t < 768; t++) {
		triangles[t] = (int)ofRandom(0, 2);
	}
	//creating the edge conditions
	for (int m = 0; m < 32; m++) {
		for (int n = 0; n < 24; n++) {

			//control length of blue
			if ((triangles[24 * m + n]) == triangles[(24 * (m + 1) + (n - 1))] && n != 0)
			{
				if (triangles[24 * m + n] == 0)
				{
					triangles[24 * (m + 1) + (n - 1)] = 1;
				}

				else if (triangles[24 * m + n] == 1)
				{
					triangles[24 * (m + 1) + (n - 1)] = 1;
				}
			}	

			//control length of black
			if ((triangles[24 * m + n]) == triangles[(24 * (m + 1) + (n + 1))] && n != 23)
			{
				if (triangles[24 * m + n] == 0)
				{
					triangles[24 * (m + 1) + (n + 1)] = 1;
				}

				else if (triangles[24 * m + n] == 1)
				{
					triangles[24 * (m + 1) + (n + 1)] = 1;
				}
			}
			
			if ((24 * m + n) % 6 == 0 && n != 0)
			{
				triangles[24 * m + n] = triangles[24 * m + n - 1];
			}
			if (m % 8 == 0 && m!= 0)
			{
				if (triangles[24 * (m - 1) + n] == 0) {
					triangles[24 * m + n] = 1;
				}

				else {
					triangles[24 * m + n] = 0;
				}

			}
		}
	}
	for (int t = 0; t < 768; t++) {
		
		std::printf("cell # is %i and vert_swap_counter is %i\n", t, triangles[t]);
	}
	
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	int a = 100;
	int b = 100;
	int size = 50;
	//boolean toggle activates a color change that stays put until the next mod condition is met
	bool swap = true;
	//swap counter is the general color block
	int hori_swap_counter = 0;
	int vert_swap_counter = 0;
	bool vert_swap = true;
	
	
	ofSetBackgroundColor(250,246,242);
	ofFill();
	for (int i = 0; i < 32; i++) {
		int test[] = { a, size + a, b, size + b };
		if (i % 8 == 0) {
			if (vert_swap_counter % 2 == 0) {
				vert_swap = true;
			}
			else if (vert_swap_counter % 2 == 1) {
				vert_swap = false;
			}
			vert_swap_counter++;

		}
		for (int j = 0; j < 24; j++) {
			if (vert_swap == true) {
				if (j % 6 == 0) {
					if (hori_swap_counter % 2 == 0) {
						swap = false;
					}
					else if (hori_swap_counter % 2 == 1) {
						swap = true;
					}
					hori_swap_counter++;
				}			
			}
			else if (vert_swap == false) {
				if (j % 6 == 0) {
					if (hori_swap_counter % 2 == 0) {
						swap = true;
					}
					else if (hori_swap_counter % 2 == 1) {
						swap = false;
					}
					hori_swap_counter++;
				}
			}		
						
			//color everything after the edge condition is identified

			//blue 
			if (swap == false) {
				ofSetColor(11,24,80);
				if (triangles[24 * i + j] == 0) {
					ofDrawTriangle(a, b + size, a, b, a + size, b);
				}
				else if (triangles[24 * i + j] == 1) {
					ofDrawTriangle(a, b + size, a + size, b + size, a + size, b);
				}
				
			}

			//black
			else {
				ofSetColor(17,17,22);
				if (triangles[24 * i + j] == 0) {
					ofDrawTriangle(a, b, a, b + size, a + size, b + size);
				}
				else if (triangles[24 * i + j] == 1) {
					ofDrawTriangle(a, b, a + size, b, a + size, b + size);
				}
			}		
			a += size;
		}
		a = 100;
		b += size;
		
		
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
