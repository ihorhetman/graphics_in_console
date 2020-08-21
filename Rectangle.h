#pragma once
#include"Figure.h"
class Rectangle:public Figure
{
protected:
	char TypeOfFigure[12] = "Rectangle";
	int x2;
	int y2;
public:
	Rectangle();
	Rectangle(int x2, int y2, int color);
	void move(int dx, int dy, bool state);
	void write(std::ofstream &out);
protected:
	void show();
	void draw(int color);
	void changeColor();
	void changeSize();
};

