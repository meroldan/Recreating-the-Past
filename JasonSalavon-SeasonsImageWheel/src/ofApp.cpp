#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//directory of images
	ofDirectory dir;
	dir.listDir("Images");
	for (int i = 0; i < dir.size(); i++) {
		imageWithData img;
		images.push_back(img);
		images.back().img.load(dir.getPath(i));

		ofRectangle targetDim(0, 0, 100, 100);
		ofRectangle imageDim(0, 0, images.back().img.getWidth(), images.back().img.getHeight());

		//resize all the images to the same dim
		targetDim.scaleTo(imageDim);
		images.back().img.crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
		images.back().img.resize(100, 100);

	}
		//sort by hue. 
		for (int i = 0; i < images.size(); i++) {
			float hue = 0;
			for (int j = 0; j < 100; j++) {
				for (int k = 0; k < 100; k++) {
					hue += images[i].img.getColor(j, k).getHue();
				}
			}
			hue /= 1000;
			images[i].hue = hue;
		}

		sort(images.begin(), images.end(), 
			[](const imageWithData & a, const imageWithData & b) -> bool
		{
			return a.hue > b.hue;
		});
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(255);
	int radius = 50;
	//amount of images in each circle
	int amt_img = 5;
	int img_pos = 0;
	int k = 0;
	//angle to rotate each image
	float theta = 360 / amt_img;
	ofNoFill();
	//draw the images
	for (int i = 0; i < 8; i++) {
		ofDrawCircle(1000, 1000, radius);
		float theta = 360 / amt_img;
		float angle = 270;
		
		for (int j = 0; j < amt_img+14; j++)
		{
			float x = 1000 + radius * cos(ofDegToRad(angle));
			float y = 1000 + radius * sin(ofDegToRad(angle));			
			ofPushMatrix();
				ofTranslate(x, y, 0);
				ofRotate(angle+90);
				images[img_pos].img.setAnchorPoint(images[img_pos].img.getWidth() / 2, images[img_pos].img.getHeight() / 2);
				images[img_pos].img.draw(0, 0);
			ofPopMatrix();
			angle += theta;
			img_pos += 1;
			cout << "amt_img is" << img_pos << endl; 
		}
		amt_img +=10;
		radius += 100;
		theta = 0;
		
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
