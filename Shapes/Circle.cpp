#include"Circle.h"
#include<sstream>

using std::istringstream;

void Circle::initialize(string stbFileInput)
{
	istringstream sin(stbFileInput);
	string syntax, xCoordinate, yCoordinate, rValue, gValue, bValue, radiusInput;
	sin >> syntax >> syntax >> xCoordinate >> syntax >> yCoordinate >> syntax >> syntax >> rValue >> gValue >> bValue >> syntax >> radiusInput;

	location.x = atoi(xCoordinate.c_str());
	location.y = atoi(yCoordinate.c_str());
	radius = atoi(radiusInput.c_str());

	this->color.Red = atoi(rValue.c_str());
	this->color.Green = atoi(gValue.c_str());
	this->color.Blue = atoi(bValue.c_str());
}

void Circle::draw(Picture& bitmapImage)
{
	int x = radius;
	int y = 0;
	int midPointError = 1 - radius;
	while (x >= y)
	{
		y++;
		if (midPointError <= 0)
		{
			midPointError = midPointError + 2 * y + 1;
		}
		else
		{
			x--;
			midPointError = midPointError + 2 * y - 2 * x + 1;
		}
		bitmapImage.AddLine(x + location.x, y + location.y, x + location.x, y + location.y, color);
		bitmapImage.AddLine(y + location.y, x + location.x, y + location.y, x + location.x, color);
		bitmapImage.AddLine(-x + location.x, y + location.y, -x + location.x, y + location.y, color);
		bitmapImage.AddLine(-y + location.y, x + location.x, -y + location.y, x + location.x, color);
		bitmapImage.AddLine(x + location.x, -y + location.y, x + location.x, -y + location.y, color);
		bitmapImage.AddLine(y + location.y, -x + location.x, y + location.y, -x + location.x, color);
		bitmapImage.AddLine(-x + location.x, -y + location.y, -x + location.x, -y + location.y, color);
		bitmapImage.AddLine(-y + location.y, -x + location.x, -y + location.y, -x + location.x, color);

		bitmapImage.AddLine(location.x + radius, location.y, location.x + radius, location.y, color);
		bitmapImage.AddLine(location.x - radius, location.y, location.x - radius, location.y, color);
		bitmapImage.AddLine(location.x, location.y + radius, location.x, location.y + radius, color);
		bitmapImage.AddLine(location.x, location.y - radius, location.x, location.y - radius, color);
	}
}

int Circle::getRadiusError(int x, int y)
{
	return abs(pow(x, 2) + pow(y, 2) - pow(radius, 2));
}
