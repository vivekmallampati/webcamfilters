#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	finder.setup("haarcascade_frontalface_default.xml");
	filter.load("beard.png");
	filterG.load("glasses.png");

	video.setDeviceID(0);
	video.setDesiredFrameRate(10);
	video.initGrabber(ofGetWindowWidth(), ofGetWindowHeight());
	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	if (video.isFrameNew()){
		img.setFromPixels(video.getPixels());
		finder.findHaarObjects(img);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	img.draw(0, 0);
	for (unsigned int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		if (cur.getHeight() > 100) {
			//for beard
			filter.resize(cur.width, cur.height*1.5);
			filter.draw(cur.getTopLeft().x, cur.getTopLeft().y+150);
			//for glasses
			filterG.resize(cur.width, cur.height*0.75);
			filterG.draw(cur.getTopLeft().x, cur.getTopLeft().y);
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
