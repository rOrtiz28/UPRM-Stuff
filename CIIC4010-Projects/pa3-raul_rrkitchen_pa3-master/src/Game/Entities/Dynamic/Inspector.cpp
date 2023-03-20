#include "Inspector.h"

Inspector::Inspector(int x, int y,int width,int height,ofImage sprite, Burger* burger):Client(x, y, width,  height, sprite, burger){
    this->burger = burger;
}
Inspector::~Inspector(){
   burger->~Burger();
}
void Inspector::render(){
    ofSetColor (255,0,0);
    ofDrawBitmapString("<----------------------------INSPECTOR", x + 150 , y);
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