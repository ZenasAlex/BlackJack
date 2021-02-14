#include "sprite.h"

void Sprite::init(float x, float y, float w, float h, string imgName)
{
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h ;
	imageName = imgName;
	img = &image(imageName);
	img->resize(w, h);
}

void Sprite::draw()
{
	img->draw(x, y);
}

string Sprite::GetName()
{
	return imageName;
}

void Sprite::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}
