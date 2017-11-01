#include"Point.h"
#include<sstream>

using std::istringstream;

void Point::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, xLocation, yLocation, rValue, gValue, bValue, syntax;
	sin >> shapeName >> syntax >> xLocation >> syntax >> yLocation >> syntax >> syntax >> rValue >> gValue >> bValue;

	this->location.x = atoi(xLocation.c_str());
	this->location.y = atoi(yLocation.c_str());

	int rValueInt = atoi(rValue.c_str());
	int gValueInt = atoi(gValue.c_str());
	int bValueInt = atoi(bValue.c_str());

	this->color.Red = rValueInt;
	this->color.Blue = bValueInt;
	this->color.Green = gValueInt;
}

void Point::draw(Picture& bitmapImage)
{
	bitmapImage.AddLine(this->location.x, this->location.y, this->location.x, this->location.y, this->color);
}
