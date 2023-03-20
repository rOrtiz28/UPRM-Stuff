#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	img1.load("images/BurguerT2.png"); //Reference: http://playerschoicegames.com/2012/06/15/burgertime-review-for-intellivision/
	img2.load("images/white.jpeg");
	music.load("music/David-Bisbal-Buleria.mp3");

	/************************************************************************************************
	Copyright of the music
	UMG (en representación de Universal Music Spain S.L.); 
	Sony ATV Publishing, UNIAO BRASILEIRA DE EDITORAS DE MUSICA - UBEM
	,UMPG Publishing, SOLAR Music Rights Management, 
	LatinAutor - SonyATV, CMRRA, LatinAutor - 
	UMPG y 13 sociedades de derechos musicales

	*Important*
	All the credits of this music belongs to the author and the discographics mentioned above, the music was only used with testing purposes. 
	**************************************************************************************************/
	
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(255);
	img1.draw(0,0,ofGetWidth(),ofGetHeight());
	img2.draw(ofGetWidth()/2 + 22, ofGetHeight()/2 + 9, 60, 20);
	startButton->render();
	music.setLoop(true);
	music.play();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}