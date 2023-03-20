#include "ofApp.h"
#include "Images.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Java Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	looseState = new LooseState();
	winState = new WinState();
	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}
			else if(currentState->getNextState() == "Game"){
				currentState = gameState;
			}
			else if(currentState->getNextState() == "LooseState"){
				currentState = looseState;
			}
			else if(currentState->getNextState() == "WinState"){
				currentState = winState;
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
		if(currentState == menuState){
			ofSetColor(255,255,255);
			ofDrawBitmapString("Instructions:", 10 ,15);
			ofDrawBitmapString("Press 'e' key to pickup ingredients ", 10 ,30);
			ofDrawBitmapString("Press 's' key to serve the hamburger", 10 ,45);
			ofDrawBitmapString("Press 'u' key to remove the last item of the hamburger", 10 ,60);
			ofDrawBitmapString("Press 'd' key to remove the all items of the hamburger", 10 ,75);
			
		}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
