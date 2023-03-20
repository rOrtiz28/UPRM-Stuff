#include "LooseState.h"

/* _______________________________________________________________________________________________________________________
Este spect fue completamente realizado por Ricardo Santigo Padin aunque por problemas con Git fue sometido desde mi cuenta
________________________________________________________________________________________________________________________*/

LooseState::LooseState() {
	restartButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Play Again");
	img1.load("images/RestCerrado.jpeg"); //Reference: https://www.periodicocentral.mx/2020/gobierno/item/6801-ya-son-400-los-restaurantes-cerrados-en-puebla-por-la-emergencia-sanitaria-de-coronavirus
    img2.load("images/white.jpeg");
    img3.load("images/Closed.png"); //Reference: https://www.sestl.org/events/building-closed-this-saturday-and-sunday-brief-shabbat-evening-services-to-be-held-tonight-at-6-p-m/
}

void LooseState::tick() {
	restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("Game");
        setFinished(true);
        restaurant->getEntityManager()->Lives == true;
        

	}
}
void LooseState::render() {
	ofSetColor(255);
	img1.draw(0,0,ofGetWidth(),ofGetHeight());
    img2.draw(ofGetWidth()/2 + 22, ofGetHeight()/2 + 9, 100, 30);
    img3.draw( 0, 0, 500, 100);
	restartButton->render();
	
}

void LooseState::keyPressed(int key){
	
}

void LooseState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void LooseState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}