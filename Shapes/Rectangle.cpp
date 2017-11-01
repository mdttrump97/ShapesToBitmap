#include"Rectangle.h"
#include<sstream>

using std::istringstream;

void Rectangle::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, xLocation, yLocation, rValue, gValue, bValue, width, height, syntax;
	sin >> shapeName >> syntax >> xLocation >> syntax >> yLocation >> syntax >> syntax >> rValue >> gValue 
		>> bValue >> syntax >> width >> syntax >> height;

	this->location.x = atoi(xLocation.c_str());
	this->location.y = atoi(yLocation.c_str());

	int rValueInt = atoi(rValue.c_str());
	int gValueInt = atoi(gValue.c_str());
	int bValueInt = atoi(bValue.c_str());

	this->color.Red = rValueInt;
	this->color.Blue = bValueInt;
	this->color.Green = gValueInt;

	this->height = atoi(height.c_str());
	this->width = atoi(width.c_str());
}

void Rectangle::draw(Picture& bitmapImage)
{
	bitmapImage.AddLine(location.x, location.y, location.x + width, location.y, color);
	bitmapImage.AddLine(location.x, location.y, location.x, location.y + height, color);
	bitmapImage.AddLine(location.x + width, location.y, location.x + width, location.y + height, color);
	bitmapImage.AddLine(location.x, location.y + height, location.x + width, location.y + height, color);
}
