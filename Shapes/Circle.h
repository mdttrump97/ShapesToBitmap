#pragma once
#include"Shape.h"

class Circle : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		int radius;
		int getRadiusError(int, int);
};
