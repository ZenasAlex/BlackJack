#include "Hand.h"

void Hand::init(float x, float y, float offset)
{
	this->x = x;
	this->y = y;
	this->offset;
}

void Hand::draw()
{
	for (Card *c : cards) {
		c->draw();
	}
}

void Hand::addCard(Card *card)
{
	if (card != NULL) {
		int cardNum = cards.size();
		int posX = card->w*cardNum + cardNum*offset;
		card->setPosition(posX, y);
		cards.push_back(card);
	}
}

void Hand::clear()
{
	cards.clear();
}

void Hand::setPosition()
{
	this->x = x;
	this->y = y;
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->setPosition(x+(cards[i]->w+offset)*i,y);
	}
}

int Hand::getPoints()
{
	int totalPoints=0;
	for (Card *c : cards) {
		if (c->value > 10) {
			totalPoints += 10;
		}
		else { totalPoints += c->value;
			}
		}
	bool hasAce=false;
	for (Card *c : cards) {
		if (c->value == 1){
			hasAce = true;
		}
	}
	if (hasAce) {
		if (totalPoints <= 11) {
			totalPoints += 10;
		}
	}
	return totalPoints;
}
void Hand::faceUpCards()
{
	for (Card *c : cards) {
		c->faceUp = true;
	}
	
}
;

