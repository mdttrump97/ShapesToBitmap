#include"Polygon.h"
#include<sstream>

using std::istringstream;

void Polygon::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string shapeName, initialCharacter;
	sin >> shapeName >> initialCharacter;
	do
	{
		string syntax, xCoordinate, yCoordinate;
		sin >> xCoordinate >> syntax >> yCoordinate >> syntax;
		Coordinate newCoordinate;
		newCoordinate.x = atoi(xCoordinate.c_str());
		newCoordinate.y = atoi(yCoordinate.c_str());
		coordinateList.push_back(newCoordinate);
		sin >> initialCharacter;
	} while (initialCharacter == "(");

	string rValue, gValue, bValue;
	sin >> rValue >> gValue >> bValue;

	this->color.Red = atoi(rValue.c_str());
	this->color.Green = atoi(gValue.c_str());
	this->color.Blue= atoi(bValue.c_str());
}

void Polygon::draw(Picture& bitmapImage)
{
	Coordinate pastCoordinate = coordinateList.front();
	for (auto i = ++coordinateList.begin(); i != coordinateList.end(); i++)
	{
		bitmapImage.AddLine(pastCoordinate.x, pastCoordinate.y, (*i).x, (*i).y, color);
		pastCoordinate = (*i);
	}
}
