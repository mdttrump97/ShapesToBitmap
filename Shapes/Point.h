#pragma once
#include"Shape.h"

class Point: public Shape
{
	public:	
		virtual void draw(Picture&);
		virtual void initialize(string);
};