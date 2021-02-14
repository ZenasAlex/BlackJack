#include "GameStateManager.h"
#include "GameState.h"

GameStateManager *GameStateManager::_gameStateMgr = new GameStateManager();



GameStateManager * GameStateManager::getInstance()
{
	return _gameStateMgr;
}
GameStateManager::GameStateManager() {

}

void GameStateManager::changeState(GameState * gState)
{
	if (!states.empty()) {
		states.back()->exit();
		states.pop_back();
	}
	states.push_back(gState);
	states.back()->setup();
}

void GameStateManager::draw()
{
	if (!states.empty()) {
		states.back()->draw();
	}
}

void GameStateManager::update()
{
	if (!states.empty()) {
		states.back()->update();
	}
}


void GameStateManager::keyPressed(int key)
{
	if (!states.empty()) {
		states.back()->keyPressed(key);
	}
}

void GameStateManager::keyReleased(int key)
{
	if (!states.empty()) {
		states.back()->keyReleased(key);
	}
}

void GameStateManager::mouseMoved(int x, int y)
{
	if (!states.empty()) {
		states.back()->mouseMoved(x,y);
	}
}

void GameStateManager::mouseDragged(int x, int y, int button)
{
	if (!states.empty()) {
		states.back()->mouseDragged(x,y,button);
	}
}

void GameStateManager::mousePressed(int x, int y, int button)
{
	if (!states.empty()) {
		states.back()->mousePressed(x, y, button);
	}

}

void GameStateManager::mouseReleased(int x, int y, int button)
{
	if (!states.empty()) {
		states.back()->mouseReleased(x, y, button);
	}
}


