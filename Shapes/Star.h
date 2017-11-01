#pragma once
#include"Shape.h"

class Star : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		int sideLength;
};