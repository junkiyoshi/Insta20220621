#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofNoFill();
}


//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int x = -220; x <= 220; x += 220) {

		for (int y = -220; y <= 220; y += 220) {

			auto rotate_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
			for (float z = 30; z < 100; z += 7.5) {

				ofPushMatrix();
				ofTranslate(x, y);

				ofRotateZ(ofMap(ofNoise(rotate_seed.z, z * 0.0035 + ofGetFrameNum() * 0.003), 0, 1, -360, 360));
				ofRotateY(ofMap(ofNoise(rotate_seed.y, z * 0.0035 + ofGetFrameNum() * 0.003), 0, 1, -360, 360));
				ofRotateX(ofMap(ofNoise(rotate_seed.x, z * 0.0035 + ofGetFrameNum() * 0.003), 0, 1, -360, 360));

				ofSetColor(ofMap(z, 100, 30, 255, 55));

				ofDrawRectangle(0, 0, z, 35, 35);

				ofPopMatrix();
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}