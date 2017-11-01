#pragma once
#include"Shape.h"

class Rectangle : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		int height;
		int width;
};