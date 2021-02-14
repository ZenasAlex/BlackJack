#include "GameState.h"
#include "GameStateManager.h"

void GameState::changeState(GameState * gameState, GameStateManager * stateMgr)
{
	stateMgr->changeState(gameState);
}
