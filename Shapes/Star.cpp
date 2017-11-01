#include"Star.h"
#include<sstream>

using std::istringstream;

void Star::initialize(string stbFileInput)
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

	this->sideLength = atoi(sideLength.c_str());
}

void Star::draw(Picture& bitmapImage)
{
	const double COS_SEVENTY_TWO = 0.309017;
	const double SIN_SEVENTY_TWO = 0.951057;
	const double ISOCELES_BASE_FACTOR = 2 * COS_SEVENTY_TWO;

	Coordinate secondPoint;
	secondPoint.x = location.x + sideLength;
	secondPoint.y = location.y;

	Coordinate thirdPoint; 
	thirdPoint.x = location.x + (ISOCELES_BASE_FACTOR * COS_SEVENTY_TWO * sideLength);
	thirdPoint.y = location.y - (SIN_SEVENTY_TWO * ISOCELES_BASE_FACTOR * sideLength);

	Coordinate fourthPoint;
	fourthPoint.x = location.x + 0.5 * sideLength;
	fourthPoint.y = location.y + sqrt((pow(ISOCELES_BASE_FACTOR * sideLength, 2) - pow(0.5 * sideLength, 2)));

	Coordinate fifthPoint;
	fifthPoint.x = secondPoint.x - (ISOCELES_BASE_FACTOR * COS_SEVENTY_TWO * sideLength);
	fifthPoint.y = location.y - (SIN_SEVENTY_TWO * ISOCELES_BASE_FACTOR * sideLength);

	bitmapImage.AddLine(location.x, location.y, secondPoint.x, secondPoint.y, color);
	bitmapImage.AddLine(secondPoint.x, secondPoint.y, thirdPoint.x, thirdPoint.y, color);
	bitmapImage.AddLine(thirdPoint.x, thirdPoint.y, fourthPoint.x, fourthPoint.y, color);
	bitmapImage.AddLine(fourthPoint.x, fourthPoint.y, fifthPoint.x, fifthPoint.y, color);
	bitmapImage.AddLine(fifthPoint.x, fifthPoint.y, location.x, location.y, color);
}
