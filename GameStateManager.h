#pragma once

#include <vector>
using namespace std;

class GameState;

class GameStateManager {
	private:
	GameStateManager();
	static GameStateManager *_gameStateMgr;
	


public: 
	vector<GameState*> states;

	static GameStateManager *getInstance();
	void changeState(GameState *gState);
	void draw();
	void update();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
};
