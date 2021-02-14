#include "Card.h"


void Card::init(float x, float y, float w, float h, int value, string suit)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->value=value;
	this->suit=suit;

	
	faceUp = true;
	active = true;
	loadSprites();
}

void Card::loadSprites()
{
	string name;
	if (value == 11) {
		name = suit + "J";
	}
	else if (value == 12) {
		name = suit + "Q";
	}
	else if (value == 13) {
		name = suit + "K";
	}
	else {
		name = suit + ofToString(value);
	}
	front.init(x, y, w, h, name);
	back.init(x, y, w, h, "back");
	cout << name << endl;
}

void Card::draw()
{
	if (active) {
		if (faceUp) {
			front.draw();
		}
		else {
			back.draw();
		}
	}
}

bool Card::inside(float x, float y){
	//calcula si el punto donde tocas está en la carta

	//cout << "si se llama" << endl;
	if (x > this->x && x < this->x + w) {
		if (y > this->y && y < this->y + h) {
		//	cout << "dentro" << endl;
			return true;
		}
	}
	return false;
}

void Card::flip() {
	faceUp = !faceUp;
	cout << "flip" << endl;
}

void Card::setPosition(float x, float y){
	//asocia la carta en memoria con la carta en pantalla

	this->x = x;
	this->y = y;
	front.x = x;
	front.y = y;
	back.x = x;
	back.y = y;

}


