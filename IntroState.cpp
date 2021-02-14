#include "IntroState.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "PlayState.h"
#include"GameStateManager.h"
#include"GameOverState.h"
#include "ofxAssets.h"


void IntroState::setup()
{
	introFont.load("CHILLER.TTF", 80);
	introMusic.load("8-bit Aerodynamic.mp3");
	pressKey = false;
	introMusic.setLoop(true);
	introMusic.play();
	y = ofGetHeight();
}

void IntroState::update()
{
	if (y > 200) {
		y -= 0.5;
		}
	else {
		pressKey = true;
	}
}

void IntroState::draw()
{
	ofDrawBitmapString("Intro State",ofGetWidth()/2,40);
	ofDrawCircle (ofGetWidth() / 2, ofGetHeight() / 2, 50);

}

void IntroState::exit()
{
	delete this;
}

void IntroState::keyPressed(int key)
{
	if (key == 'a' || key == 'A') {
		PlayState *playState = new PlayState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(playState, stateMgr);
	}
	if (key == 'c' || key == 'C') {
		GameOverState *gameOverState = new GameOverState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(gameOverState, stateMgr);
	}
}

void IntroState::keyReleased(int key)
{
}

void IntroState::mouseMoved(int x, int y)
{
}

void IntroState::mouseDragged(int x, int y, int button)
{
}

void IntroState::mousePressed(int x, int y, int button)
{
}

void IntroState::mouseReleased(int x, int y, int button)
{
}
