#include "Deck.h"


void Deck::init(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
	loadCards("c");
	loadCards("d");
	loadCards("h");
	loadCards("s");
	shuffle();
	//faceDownCard();
	}

void Deck::loadCards(string suit)
{
	for (int i = 1; i < 14; i++) {
		Card card;
		card.init(x + i * 10, y, w, h, i, suit);
		cards.push_back(card);
	}
	y += 50;
}

void Deck::draw()
{
	for (Card &c : cards) {
		c.draw();
	}
}

void Deck::shuffle()
{
	std::random_shuffle(cards.begin(), cards.end());
	actualCardIndex = 0;
}

void Deck::faceDownCard()
{
	for (Card &c : cards) {
		c.faceUp = false;
	}
}

Card * Deck::getNextCard()
{
	Card *card = NULL;
	if (actualCardIndex < cards.size()) {
		card =&cards[actualCardIndex];
		actualCardIndex++;
	}
	return card;
}
