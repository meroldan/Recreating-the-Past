#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.initGrabber(640, 480);
	//black and white image
	camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//background
	bgGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//foreground
	diffImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
	//treshold image
	threshImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);

	bRecordBg = true;

	font.load("TheanoDidot-Regular.ttf", 12);
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

	//int pixel;
	


}

//--------------------------------------------------------------
void ofApp::draw(){

	//letters initial position
	int x = 10;
	int y = 15;
	char *letters[] = { "I ", "w", "h", "i", "p ", "m", "y ", "h", "a", "i", "r" , "b", "a", "c", "k ", "a", "n", "d ", "f", "o", "r", "t", "h"};

	//grabber.draw(0,0);
	//camGray.draw(0, 0);
	//bgGray.draw(0, 0);
	//diffImg.draw(0, 0);
	ofScale(2, 2);
	//threshImg.draw(0, 0);

	ofSetBackgroundColor(0);
	   
	//for (int i = 0; i < 640; i++) {
		//for (int j = 0; j < 480; j++) {
			//ofColor pixel = diffImg.getColor(i, j);
			//float brightness = pixel.getBrightness();
			//int text = ofMap(0, 255, 0, 1);
		//}
	//}
	int k = 0;
	for (int j = 0; j < 70; j++) {
		int x = 5;
		for (int i = 0; i < 70; i++) {

			ofColor pixel = threshImg.getColor(x, y);
			float brightness = pixel.getBrightness();
			//int text = ofMap(brightness, 0, 255, 0, 1);
			//if (brightness <= 10) {
				//ofSetColor(0);
			//}
			if (brightness <= 5)  {
				ofSetColor(255, 0, 0);
			}
			else {
				ofSetColor(0, 0, 0);
			}
			
			ofDrawRectangle(x, y, 9, 9);

			float u = font.stringWidth(letters[k]);
			x += 5;
			k++;
			if (k == 23) {
				k = 0;
			}
			
		}
		y += 5;
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
