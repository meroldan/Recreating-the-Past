#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//setup the cameras
	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.initGrabber(1000, 1000);
	//black and white image
	camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//background
	bgGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//foreground
	diffImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//treshold image
	threshImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);

	bRecordBg = true;

	//Create the array of colors
	colors[0] = ofColor(248, 131, 177); 
	colors[1] = ofColor(206, 52, 117);
	colors[2] = ofColor(197, 0, 53); 
	colors[3] = ofColor(188, 21, 37);
	colors[4] = ofColor(243, 177, 76);
	colors[5] = ofColor(255, 117, 0);
	colors[6] = ofColor(237, 73, 0);  
	colors[7] = ofColor(246, 233, 83); 
	colors[8] = ofColor(242, 193, 0); 
	colors[9] = ofColor(237, 208, 0); 
	colors[10] = ofColor(172, 229, 167);
	colors[11] = ofColor(169, 180, 7);
	colors[12] = ofColor(107, 176, 34);
	colors[13] = ofColor(42, 149, 124);
	colors[14] = ofColor(0, 74, 157);
	//blues
	colors[15] = ofColor(65, 182, 255);
	colors[16] = ofColor(65, 182, 255);
	colors[17] = ofColor(65, 182, 255);
	colors[18] = ofColor(65, 182, 255);
	colors[19] = ofColor(65, 182, 255);
	colors[20] = ofColor(65, 182, 255);
	colors[21] = ofColor(65, 182, 255);
	colors[22] = ofColor(65, 182, 255);
	//pinks
	colors[23] = ofColor(237, 208, 0);
	colors[24] = ofColor(206, 52, 117);
	colors[25] = ofColor(197, 0, 53);

	for (int i = 0; i < 40000; i++) {
		squares[i] = ofRandom(0, 26);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		convertColor(grabber, camGray, CV_RGB2GRAY);
		camGray.update();
	}

	if (bRecordBg) {
		bgGray.setFromPixels(camGray.getPixels());
		bgGray.update();
		bRecordBg = false;
	}

	absdiff(camGray, bgGray, diffImg);
	diffImg.update();

	threshImg.setFromPixels(diffImg.getPixels());
	threshold(threshImg, 80);
	threshImg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	int frame = ofGetFrameNum();
	int y = 0;
	ofScale(2, 2);
	//draw the video
	threshImg.draw(1040, 0);
	ofSetBackgroundColor(0);

	int b = 0;
	//dimension of square
	int rec = 5;
	int sq_num = 0;
	//# of squares
	int base = 200;

	//draw the base grid
	for (int i = 0; i < base; i++) {
		int a = 0;
		for (int j = 0; j < base; j++) {
			ofSetColor(colors[squares[sq_num]]);
			ofDrawRectangle(a, b, rec, rec);
			a += rec;
			sq_num = base * i + j;
			//std::cout << "i: " << sq_num << endl;
		}
		b += rec;
	}

	//change the base grid based on pixel brightness
	int t = 3;
	for (int i = 0; i < base; i++) {
		int x = 3;
		for (int j = 0; j < base; j++) {
			if (frame < 5) {
				break;
			}
			int num = base * i + j;
			ofColor pixel = threshImg.getColor(x, t);
			float brightness = pixel.getBrightness();

			//0 = dark
			//select the blue pixels and swap them for yellow
			//then spread that effect to the neighboring pixels
			if (brightness == 0) {		
					int horspread = ofRandom(15, 20);
					int verspread = ofRandom(15, 20);
					for (int k = 0; k < horspread; k++) {
						//horizontal
						if (squares[num + k] > 15 && squares[num + k] < 23) {
							int newcolor = ofRandom(6, 9);
							ofSetColor(colors[newcolor]);
							squares[num + k] = newcolor;
							//vertical
							for (int g = 0; g < verspread; g++) {
								if (squares[num + k - g * base] > 15 && squares[num + k - g * base] < 23) {
									int newcolor = ofRandom(6, 9);
									ofSetColor(colors[newcolor]);
									squares[num + k - g * base] = newcolor;
								}
							}

						}
					}

					//simplified version-just one color
				//if (squares[num] > 15 && squares[num] < 23) {
					//ofSetColor(colors[9]);
					//squares[num] = 9;
				//}
			}
			//otherwise, keep the color from the base grid
			else  {
				ofSetColor(colors[squares[num]]);
			}
			x += rec;
		}
		t += rec;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		bRecordBg = true;
	}
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
