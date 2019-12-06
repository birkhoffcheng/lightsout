#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(500, 800);
	b.reset();
	reset_button.set(200, 600, 100, 50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int rect_start_x = 10;
	int rect_start_y = 10;
	uint8_t bit_index = 0;
	for (int i = 0; i < 5; ++i) {
		rect_start_x = 10;
		for (int j = 0; j < 5; ++j) {
			if (b.get_bit(bit_index)) {
				ofSetColor(255, 255, 255);
			} else {
				ofSetColor(127, 127, 127);
			}

			++bit_index;
			ofDrawRectangle(rect_start_x, rect_start_y, 80, 80);
			rect_start_x += 100;
		}

		rect_start_y += 100;
	}

	ofSetColor(0, 200, 255);
	ofDrawRectangle(reset_button);
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
	if (y <= 500) {
		int col = x / 100;
		int row = y / 100;
		b.press_button(row * 5 + col);
	} else if (reset_button.inside(x, y)) {
		b.reset();
	}
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
