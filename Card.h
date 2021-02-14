#pragma once

#include "Sprite.h"
#include "ofImage.h"

class Card {
public:
	float x;
	float y;
	float w;
	float h;

	string suit;
	int value;
	Sprite front;
	Sprite back;
	
	bool active;
	bool faceUp;

	void init(float x, float y, float w, float h, int value, string suit);
	void loadSprites();
	void draw();

	bool inside(float x, float y);
	void flip();
	void setPosition(float x, float y);
};