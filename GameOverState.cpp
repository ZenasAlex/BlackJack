#include "GameOverState.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "PlayState.h"
#include "IntroState.h"
#include "GameStateManager.h"

void GameOverState::setup()
{
}

void GameOverState::update()
{
}

void GameOverState::draw()
{
	ofDrawBitmapString("Game Over State", ofGetWidth() / 2, 40);
	ofDrawTriangle(200, 100, 100, 300, 500, 200);
}

void GameOverState::exit()
{
	delete this;
}

void GameOverState::keyPressed(int key)
{
	if (key == 'a' || key == 'A') {
		PlayState *playState = new PlayState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(playState, stateMgr);
	}
	if (key == 'b' || key == 'B') {
		IntroState *introState = new IntroState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(introState, stateMgr);
	}
}

void GameOverState::keyReleased(int key)
{
}

void GameOverState::mouseMoved(int x, int y)
{
}

void GameOverState::mouseDragged(int x, int y, int button)
{
}

void GameOverState::mousePressed(int x, int y, int button)
{
}

void GameOverState::mouseReleased(int x, int y, int button)
{
}
