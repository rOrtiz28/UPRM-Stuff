#pragma once

#include "State.h"
#include "Button.h"
#include "Restaurant.h"

class LooseState : public State {
private:
	ofImage img1;
    ofImage img2;
    ofImage img3;
	Button *restartButton;
	ofSoundPlayer musicTest;
    Restaurant *restaurant;

public:
	LooseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
