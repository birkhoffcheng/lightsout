#include "ofApp.h"
#include <cstdio>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(500, 800);
	uint64_t random;
	FILE *fp = fopen("/dev/urandom", "rb");
	fread(&random, sizeof(random), 1, fp);
	fclose(fp);
	b.board = random;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor(255, 255, 255));
	int rect_start_x = 10;
	int rect_start_y = 10;
	uint8_t bit_index = 0;
	for (int i = 0; i < 5; ++i) {
		rect_start_x = 10;
		for (int j = 0; j < 5; ++j) {
			if (b.get_bit(bit_index)) {
				ofSetColor(ofColor(255, 255, 255));
			} else {
				ofSetColor(ofColor(127, 127, 127));
			}
			
			++bit_index;
			ofDrawRectangle(rect_start_x, rect_start_y, 80, 80);
			rect_start_x += 100;
		}
		
		rect_start_y += 100;
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
