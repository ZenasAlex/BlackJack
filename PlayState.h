#pragma once
#include "GameState.h"
#include "ofxAssets.h"
#include "ofxGui.h"
#include "ofxButton.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

class PlayState : public GameState {
public:
	ofxPanel gui;
	ofxButton backButton;
	ofxPanel hitGUI;
	ofxButton hitButton;
	ofxButton passButton;

	Deck deck;
	//Card *card;
	Hand player;
	Hand dealer;
	bool gameOver;
	string gameResult;

	void hit();
	void pass();
	void loadGame();
	void initGame();
	void endGame();
	void checkBlackJack();
	void setup();
	void update();
	void draw();
	void exit();

	void goToIntro();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

};