#pragma once
#include"ofImage.h"
#include "ofxAssets.h"

using namespace ofxAssets;
class Sprite {

public:
	float x;
	float y;
	float width;
	float height;
	ofImage *img;
	string imageName;

	void init(float x, float y, float w, float h, string imgName);
	void draw();
	string GetName();
	void setPosition(float x, float y);

}; 