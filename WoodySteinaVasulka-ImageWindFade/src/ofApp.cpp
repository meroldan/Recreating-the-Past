#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//set up camera
	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.setup(640, 480);
	//make image of camera bw
	camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);

	//create mesh, draw a line to connect vertices of mesh
	mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
	mesh.enableColors();
	//thanks openframeowkrs Graphics/Basics: Working with ofMesh, https://github.com/mikewesthad/ofSite/blob/master/_tutorials/03_graphics/generativemesh.markdown
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		convertColor(grabber, camGray, CV_RGB2GRAY);
		camGray.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetLineWidth(3);
	int windstart;
	int windmove;
	int multiplier;
	float angle = 0.0;
	for (int y = 0; y < camGray.getHeight(); y += 5) {
		//clear the mesh so the beginning of the line doesn't connect with the diagonal endpoint of another

		ofPolyline line;
		vector < ofColor > colors;

		//mesh.clear();
		for (int x = 0; x < camGray.getWidth(); x += 20) {
			ofColor c = camGray.getPixels().getColor(x, y);
			float brightness = camGray.getPixels().getColor(x, y).getBrightness();
			ofVec3f(vert);
			//change height of vector based on brightness. mapped 0 to 2 because there should be little variation in the beginning
			vert.set(x, y + ofMap(brightness, 0, 255, 0, 2), 0);
			//windstart determines the startpoint for the wind to happen. 
			windstart = ofRandom(200, 640);
			//the start of the wind determines the multiplier. points that are closer to the middle should have less noise than points closer to the right of the image.
			if (x > windstart) {
				if (x > 200 && x < 420) {
					multiplier = ofRandom(3, 5);
				}
				else if (x >= 420) {
					multiplier = ofRandom(10, 20);
				}
				//add variation to separate the lines
				windmove = 10;
				//redraw the vector for the wind
				vert.set(x + 5 * sin(ofDegToRad(angle)) + windmove, y + 5 * cos(ofDegToRad(angle)) + windmove, 0);
				//angle changes to create noise
				angle += ofRandom(20, 45);
			}
			line.addVertex(vert);
			colors.push_back(ofFloatColor(c, .75));
		}
		line = line.getResampledBySpacing(1);
		line = line.getSmoothed(15);

		ofMesh m;
		m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
		for (int j = 0; j < line.size(); j++) {

			int j_m_1 = j - 1;
			int j_p_1 = j + 1;
			j_m_1 = ofClamp(j_m_1, 0, line.size() - 1);
			j_p_1 = ofClamp(j_p_1, 0, line.size() - 1);
			ofPoint diff = line[j_p_1] - line[j_m_1];
			diff = diff.getNormalized().rotate(90, ofPoint(0, 0, 1));
			m.addVertex(line[j] + diff * 2);
			m.addVertex(line[j] - diff * 2);
			float pct = ofMap(j, 0, line.size(), 0, 1);
			ofFloatColor c = colors[pct*colors.size()];
			m.addColor(c);
			m.addColor(c);

		}
	m.draw();
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
