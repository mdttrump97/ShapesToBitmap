#include"RightTriangle.h"
#include<sstream>

using std::istringstream;

void RightTriangle::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, xLocation, yLocation, rValue, gValue, bValue, baseWidth, baseHeight, syntax;
	sin >> shapeName >> syntax >> xLocation >> syntax >> yLocation >> syntax >> syntax >> rValue >> gValue
		>> bValue >> syntax >> baseWidth >> syntax >> baseHeight;

	this->location.x = atoi(xLocation.c_str());
	this->location.y = atoi(yLocation.c_str());

	int rValueInt = atoi(rValue.c_str());
	int gValueInt = atoi(gValue.c_str());
	int bValueInt = atoi(bValue.c_str());

	this->color.Red = rValueInt;
	this->color.Blue = bValueInt;
	this->color.Green = gValueInt;

	this->baseWidth = atoi(baseWidth.c_str());
	this->baseHeight = atoi(baseHeight.c_str());
}

void RightTriangle::draw(Picture& bitmapImage)
{
	bitmapImage.AddLine(location.x, location.y, location.x + baseWidth, location.y, color);
	bitmapImage.AddLine(location.x, location.y, location.x, location.y + baseHeight, color);
	bitmapImage.AddLine(location.x, location.y + baseHeight, location.x + baseWidth, location.y, color);
}
