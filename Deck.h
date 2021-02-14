#pragma once
#include "Card.h"
#include <vector>


class Deck{
public:
	//Lista de cartas
	vector <Card> cards;
	int actualCardIndex;//Guarda el indice de la ultima carta repartida
	float x;
	float y;
	float h;
	float w;



	//Carga las cartas en memoria
		void init(float x, float y, float w, float h);
		void loadCards(string suit);
		void draw();
		void shuffle();
		void faceDownCard();
		Card *getNextCard();

};