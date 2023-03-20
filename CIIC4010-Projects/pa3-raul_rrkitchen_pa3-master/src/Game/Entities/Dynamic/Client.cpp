#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}
void Client::render(){
    ofSetColor (255,255,255);
    burger->render();

    if(patience > 1700) {
        ofSetColor (255,255,255);
    }
    else if(patience <= 1700 && patience >= 1400){
        ofSetColor (255,205,205);
    }
    else if(patience <= 1399 && patience >= 1000){
        ofSetColor (255,155,155);
    }
    else if(patience <= 999 && patience >= 500){
        ofSetColor (255,105,105);
    }
    else if(patience < 500){
        ofSetColor (255,0,0);
    }
    
    sprite.draw(x, y, width, height);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y + 10);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    isLeaving = true;
    return 10;
}

int Client::getPatience(){
    return patience;
}