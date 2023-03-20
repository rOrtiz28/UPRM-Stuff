#pragma once

#include "State.h"
#include "Button.h"
#include "Restaurant.h"

class WinState : public State {
private:
	ofImage img1;
    ofImage img2;
    ofImage img3;
	Button *restartButton;
	ofSoundPlayer musicTest;
    Restaurant *restaurant;

public:
	WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
