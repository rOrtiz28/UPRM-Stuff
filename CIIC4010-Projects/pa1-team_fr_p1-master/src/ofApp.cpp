#include "ofApp.h"

bool stopParticles = false;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	p.assign(num, Particle());
	currentMode = PARTICLE_MODE_ATTRACT;

	currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 

	resetParticles();
}
//--------------------------------------------------------------
void ofApp::resetParticles(){

	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	if(stopParticles) {
		return;
	}

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].update();
	}
	
	//lets add a bit of movement to the attract points
	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor (0, 255, 255), ofColor(0, 0, 255)); //Color of Background (first ofColor((60,60,60)) modifies a circle in the center, the second one ofColor(0, 255, 0) all of the window app)

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
	
	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofDrawCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofDrawCircle(attractPointsWithMovement[i], 4);
		}
	}

	ofSetColor(230);	
	ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-5 to change mode.", 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if( key == '1'){
		currentMode = PARTICLE_MODE_ATTRACT;
		currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 		
	}
	if( key == '2'){
		currentMode = PARTICLE_MODE_REPEL;
		currentModeStr = "2 - PARTICLE_MODE_REPEL: repels from mouse"; 				
	}
	if( key == '3'){
		currentMode = PARTICLE_MODE_NEAREST_POINTS;
		currentModeStr = "3 - PARTICLE_MODE_NEAREST_POINTS: hold 'f' to disable force"; 						
	}
	if( key == '4'){
		currentMode = PARTICLE_MODE_NOISE;
		currentModeStr = "4 - PARTICLE_MODE_NOISE: snow particle simulation"; 						
		resetParticles();
	}	
	if( key == '5'){
        currentMode = PARTICLE_MODE_UMBRELLAFORSNOW;
        currentModeStr = "5 - PARTICLE_MODE_UMBRELLAFORSNOW: snow particle simulation but with a Umbrella effect in the cursor";                         
    } 	
	if( key == ' ' ){
		resetParticles();
	}

	if ( key == 'A' || key == 'a'){
		if(stopParticles) {
			stopParticles = false;
		}
		else {
			stopParticles = true;
		}
	}
	if (key == 'D' || key == 'd') {
		doubleSize();
	}
	if (key == 'M' || key == 'm') {
		halfSize();
	}
	if (key == 'T' || key == 't') {
		doubleVelocity();
	}
	if (key == 'S' || key == 's') {
		halfVelocity();
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
void ofApp::doubleSize(){ // <--------------------------- When is called duplicates the size of the Particles
	for(unsigned int i = 0; i < p.size(); i++) {
			p[i].scale = p[i].scale * 2;
		}
}

void ofApp::halfSize() { // <--------------------------- When is called half the size of the Particles
	if(p[1].scale >= 0.5) {
		for(unsigned int i = 0; i < p.size(); i++) {
			p[i].scale = p[i].scale / 2;
		}
	}

}

void ofApp::doubleVelocity() { // <--------------------------- When is called duplicates the velocity of the Particles
	for(unsigned int i = 0; i < p.size(); i++) {
			p[i].vel.x = p[i].vel.x * 2;
			p[i].vel.y = p[i].vel.y * 2;
		}

}

void ofApp::halfVelocity() { // <--------------------------- When is called half the velocity of the Particles
	for(unsigned int i = 0; i < p.size(); i++) {
			p[i].vel.x = p[i].vel.x / 2;
			p[i].vel.y = p[i].vel.y / 2;
		}

}