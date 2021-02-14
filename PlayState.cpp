#include "PlayState.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include"GameStateManager.h"
#include "IntroState.h"
#include "GameOverState.h"

void PlayState::hit()
{
	Card *newCard = deck.getNextCard();
	newCard->flip();
	player.addCard(newCard);

	Card *card = dealer.cards.at(0);
	card->flip();
	if (dealer.getPoints() < 17) {
		Card*nCard = deck.getNextCard();
		nCard->flip();
		dealer.addCard(nCard);
	}
}

void PlayState::pass()
{
}

void PlayState::loadGame()
{
	gui.setup();
	gui.add(backButton.setup("Regresar"));
	backButton.addListener(this, &PlayState::goToIntro);
	hitGUI.setup();
	hitGUI.setPosition(0, 350);
	hitGUI.add(hitButton.setup("Carta"));
	hitGUI.add(passButton.setup("Pasar"));
	hitButton.addListener(this, &PlayState::hit);
	hitButton.addListener(this, &PlayState::pass);
	deck.init(30, 50, 100, 150);
	player.init(20, 500, 10);
	dealer.init(20, 50, 10);
}

void PlayState::initGame()
{
	gameOver = false;
	player.clear();
	dealer.clear();
	deck.faceDownCard();
	deck.shuffle();
	Card *CardOne = deck.getNextCard();
	CardOne->flip();
	player.addCard(CardOne);
	Card *CardTwo= deck.getNextCard();
	dealer.addCard(CardTwo);
	Card *CardThree = deck.getNextCard();
	CardThree->flip();
	player.addCard(CardThree);
	Card *CardFour = deck.getNextCard();
	dealer.addCard(CardFour);
	CardFour->flip();
	checkBlackJack();
}

void PlayState::endGame()
{
	gameOver = true;

}

void PlayState::checkBlackJack()
{
	//evaluar caso jugador tiene Black Jack
	//evaluar caso jugador y dealer tienen Black Jack
	//evaluar caso jugador o dealer tienen tengan mas de 21 puntos
	//evaluar caso solo Dealer tiene Black Jack
	//evaluar caso jugador y dealer tienen menos de 21 puntos

	int dealerPts = dealer.getPoints();
	int playerPts = player.getPoints();

	if (playerPts == 21) {
		if (dealerPts == 21) {
			//empate
			gameResult = "Empate";
			endGame();
		}
		else { //gana jugador
			gameResult = "Ganaste";
			endGame();
		}
	}else if (dealerPts == 21) {
		gameResult = "Perdiste";
		endGame();
		}else if (playerPts > 21) {
			if (dealerPts > 21) {
				//empate
				gameResult = "Empate";
				endGame();
			}
			else if (playerPts > 21) {
				gameResult = "Perdiste";
				endGame();
			}
			else if(dealerPts <21&&playerPts<21){
				//juego continua 
			}
	}

}

void PlayState::setup()
{
	loadGame();
	initGame();
}

void PlayState::update()
{
}

void PlayState::draw()
{
	ofDrawBitmapString("Play State", ofGetWidth() / 2, 40);
	gui.draw();
	//deck.draw();
	//ofDrawCircle(10, 10, 30);
	player.draw();
	dealer.draw();
	ofSetColor(255, 0, 0);
	ofDrawBitmapString	("Play Score:"+ ofToString(player.getPoints()),70, 500);
	ofSetColor(255);

	if (gameOver){
		ofDrawBitmapString("gameResult",ofGetWidth() / 2,10);

	}
}

void PlayState::exit()
{
	delete this;
}

void PlayState::goToIntro()
{
	changeState(new IntroState(), GameStateManager::getInstance());
}

void PlayState::keyPressed(int key)
{
	if (key == 'b' || key == 'B') {
		IntroState *introState = new IntroState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(introState, stateMgr);
	}
	if (key == 'c' || key == 'C') {
		GameOverState *gameOverState = new GameOverState();
		GameStateManager *stateMgr = GameStateManager::getInstance();
		changeState(gameOverState, stateMgr);
	}
}

void PlayState::keyReleased(int key)
{
}

void PlayState::mouseMoved(int x, int y)
{
}

void PlayState::mouseDragged(int x, int y, int button)
{
	//card.setPosition(x, y);
}

void PlayState::mousePressed(int x, int y, int button)
{
	//card.flip();
}

void PlayState::mouseReleased(int x, int y, int button)
{

	//hand.addCard(deck.getNextCard());  (servia cuando habia un objeto Hand)
	/*Card *c= deck.getNextCard();

	if (c !=NULL) {
		card = c;
	card->setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
}*/
}
