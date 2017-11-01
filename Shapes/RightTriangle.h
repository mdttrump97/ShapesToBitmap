#pragma once
#include"Shape.h"

class RightTriangle : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		int baseWidth;
		int baseHeight;
}; 
