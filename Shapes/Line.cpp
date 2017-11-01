#include"Line.h"
#include<sstream>

using std::istringstream;

void Line::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, xStartLocation, yStartLocation, xEndLocation, yEndLocation, rValue, gValue, bValue, syntax;
	sin >> shapeName >> syntax >> xStartLocation >> syntax >> yStartLocation >> syntax >> syntax >> xEndLocation >> syntax
		>> yEndLocation >> syntax >> syntax >> rValue >> gValue >> bValue;

	this->location.x = atoi(xStartLocation.c_str());
	this->location.y = atoi(yStartLocation.c_str());
	this->endLocation.x = atoi(xEndLocation.c_str());
	this->endLocation.y = atoi(yEndLocation.c_str());

	int rValueInt = atoi(rValue.c_str());
	int gValueInt = atoi(gValue.c_str());
	int bValueInt = atoi(bValue.c_str());

	this->color.Red = rValueInt;
	this->color.Blue = bValueInt;
	this->color.Green = gValueInt;
}

void Line::draw(Picture& bitmapImage)
{
	bitmapImage.AddLine(this->location.x, this->location.y, this->endLocation.x, this->endLocation.y, this->color);
}
