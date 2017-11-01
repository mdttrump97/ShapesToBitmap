#pragma once
#include"Shape.h"

class Line : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		Coordinate endLocation;
};