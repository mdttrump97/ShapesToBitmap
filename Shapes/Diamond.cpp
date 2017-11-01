#include"Diamond.h"
#include<sstream>

using std::istringstream;

void Diamond::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, xLocation, yLocation, rValue, gValue, bValue, sideLength, syntax;
	sin >> shapeName >> syntax >> xLocation >> syntax >> yLocation >> syntax >> syntax >> rValue >> gValue >> bValue
		>> syntax >> sideLength;

	this->location.x = atoi(xLocation.c_str());
	this->location.y = atoi(yLocation.c_str());

	int rValueInt = atoi(rValue.c_str());
	int gValueInt = atoi(gValue.c_str());
	int bValueInt = atoi(bValue.c_str());

	this->color.Red = rValueInt;
	this->color.Blue = bValueInt;
	this->color.Green = gValueInt;

	this->size = atoi(sideLength.c_str());
}

void Diamond::draw(Picture& bitmapImage)
{
	bitmapImage.AddLine(location.x, location.y, location.x + size / 2, location.y - size / 2, color);
	bitmapImage.AddLine(location.x + size / 2 , location.y - size /2 , location.x, location.y - size, color);
	bitmapImage.AddLine(location.x, location.y - size, location.x - size / 2, location.y - size / 2, color);
	bitmapImage.AddLine(location.x - size / 2, location.y - size / 2, location.x, location.y, color);
}
