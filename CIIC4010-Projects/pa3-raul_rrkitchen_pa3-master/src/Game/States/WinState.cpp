#include "WinState.h"

/* _______________________________________________________________________________________________________________________
Este spect fue completamente realizado por Ricardo Santigo Padin aunque por problemas con Git fue sometido desde mi cuenta
________________________________________________________________________________________________________________________*/

WinState::WinState() {
	restartButton = new Button(ofGetWidth()/2 - 50, ofGetHeight()/2 - 50, 64, 50, "Play Again");
	img1.load("images/WinState.jpeg"); //Reference: https://mcmoutletonline.com/compilation/burger-time-online-game-free.php
    img2.load("images/white.jpeg");
    img3.load("images/YouWin.jpeg"); //Reference: http://www.dreamstime.com/stock-footage-led-screen-you-win-loop-huge-color-shows-video-stars-text-video39756057
}

void WinState::tick() {
	restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("Game");
        setFinished(true);
        restaurant->getEntityManager()->Lives == true;
        

	}
}
void WinState::render() {
	ofSetColor(255);
	img1.draw(0,0,ofGetWidth(),ofGetHeight());
    img2.draw(ofGetWidth()/2 -30, ofGetHeight()/2 -45, 100, 30);
    img3.draw(ofGetWidth()/2 - 80, ofGetHeight()/2, 165, 125);
	restartButton->render();
	
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}