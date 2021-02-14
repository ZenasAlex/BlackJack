#pragma once

#include "ofMain.h"
#include "IntroState.h"
#include "GameOverState.h"
#include "PlayState.h"
#include "GameStateManager.h"

class ofApp : public ofBaseApp{

	public:
		GameStateManager *gStateMgr;
		IntroState* intro;
		PlayState* play;
		GameOverState* gameOverState;
		
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
