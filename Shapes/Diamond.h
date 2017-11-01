#pragma once
#include"Shape.h"

class Diamond : public Shape
{
	public:
		virtual void draw(Picture&);
		virtual void initialize(string);
	private:
		int size;
}; 
