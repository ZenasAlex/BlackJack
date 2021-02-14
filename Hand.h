#pragma once
#include "Card.h"

class Hand{
public:
	//posicion de la primera carta en mano
	float x;
	float y;
	float offset; // distancia entre cartas
	vector < Card*>cards; //apuntadores a cartas en el deck que an sido asignados a la mano


	void init(float x, float y, float offset);// inicializa la mano
	void draw(); //Dibuja el conjunto de cartas
	void addCard(Card *card); //Guarda una carta en mano
	void clear();  //Limpia la mano
	void setPosition();  //coloca todas las cartas en una nueva posicion
	int getPoints();
	void faceUpCards();
};