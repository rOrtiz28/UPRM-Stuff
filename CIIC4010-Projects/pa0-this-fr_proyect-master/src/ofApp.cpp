#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    xSpeed = 130; // 1 to 130 change
    ySpeed = 100; // 1 to 100 change
    text = "Vamos a intentar no colgarnos";

}

//--------------------------------------------------------------
void ofApp::update(){
    if(xPos >= ofGetWidth() || xPos <= 0){
        xSpeed *= -1;
    }
    if(yPos >= ofGetHeight() || yPos <= 0){
        ySpeed *=-1;
    }
    xPos += xSpeed;
    yPos += ySpeed;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(xPos, ofGetWidth()/2, ofGetHeight()/2);
    ofDrawBitmapString(yPos, ofGetWidth()/2, ofGetHeight()/2 + 25);
    ofDrawBitmapString(text, xPos,yPos);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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