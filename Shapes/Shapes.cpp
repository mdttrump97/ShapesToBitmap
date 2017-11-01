#include<fstream>
#include<sstream>
#include<string>
#include<list>
#include"Point.h"
#include"Line.h"
#include"Rectangle.h"
#include"RightTriangle.h"
#include"Star.h"
#include"Diamond.h"
#include"Polygon.h"
#include"Circle.h"
#include"Picture.h"
#include"RGBTriple.h"

using std::string;
using std::ifstream;
using std::list;
using std::istringstream;

void main()
{
	list<Shape*> shapeList;
	ifstream fin("Shapes.stb");
	string stbInput;
	getline(fin, stbInput);
	istringstream sin(stbInput);
	string initialWord;
	sin >> initialWord;
	int imageHeight = 100, imageWidth = 100;
	RGBTriple backgroundColor(255, 255, 255);

	if (initialWord == "Window:")
	{
		string syntax, imageWidthInput, imageHeightInput, rValue, gValue, bValue;
		sin >> syntax >> imageWidthInput >> syntax >> imageHeightInput >> syntax >> rValue >> gValue >> bValue;

		int rValueInt = atoi(rValue.c_str());
		int gValueInt = atoi(gValue.c_str());
		int bValueInt = atoi(bValue.c_str());
		backgroundColor.Red = rValueInt;
		backgroundColor.Green = gValueInt;
		backgroundColor.Blue = bValueInt;

		imageWidth = atoi(imageWidthInput.c_str());
		imageHeight = atoi(imageHeightInput.c_str());
	}

	do
	{
		getline(fin, stbInput);
		sin.clear();
		sin.str(stbInput);
		sin >> initialWord;
		Shape* newShape;
		if (initialWord == "Point:")
		{
			newShape = new Point;
		}
		else if (initialWord == "Line:")
		{
			newShape = new Line;
		}
		else if (initialWord == "Rectangle:")
		{
			newShape = new Rectangle;
		}
		else if (initialWord == "RightTriangle:")
		{
			newShape = new RightTriangle;
		}
		else if (initialWord == "Star:")
		{
			newShape = new Star;
		}
		else if (initialWord == "Diamond:")
		{
			newShape = new Diamond;
		}
		else if (initialWord == "Polygon:")
		{
			newShape = new Polygon;
		}
		else if (initialWord == "Circle:")
		{
			newShape = new Circle;
		}
		else
		{
			newShape = nullptr;
		}
		(*newShape).initialize(stbInput);
		shapeList.push_back(newShape);
	} while (!fin.eof());

	Picture bitmapImage(imageWidth, imageHeight, backgroundColor);
	for (auto i = shapeList.begin(); i != shapeList.end(); i++)
	{
		(*i)->draw(bitmapImage);
	}
	bitmapImage.WriteToFile("Shapes.bmp");
}

