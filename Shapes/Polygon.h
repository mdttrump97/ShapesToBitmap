#pragma once
#include"Shape.h"
#include<list>

class Polygon : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		list<Coordinate> coordinateList;
};