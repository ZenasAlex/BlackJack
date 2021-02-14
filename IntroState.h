#pragma once
#include "GameState.h"
#include "ofSoundPlayer.h"
#include "ofTrueTypeFont.h"

class IntroState : public GameState {
public:
	ofSoundPlayer introMusic;
	ofTrueTypeFont introFont;
	bool pressKey;
	int y;

	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

};