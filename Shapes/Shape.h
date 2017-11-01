#pragma once
#include"Coordinate.h"
#include"RGBTriple.h"
#include"Picture.h"
#include<string>

using std::string;

class Shape
{
	public:
		virtual void initialize(string) = 0;
		virtual void draw(Picture&) = 0;
	protected:
		Coordinate location;
		RGBTriple color;
		int size;
};