#pragma once
#include "Figure.h"
class Point :public Figure
{
protected:
	char TypeOfFigure[10] = "Point";
	int r;
public:
	Point();
	Point(int x1, int y1, int color, int r);
	void move(int dx, int dy, bool state);
	void write(std::ofstream &out);
protected:
	void show();
	void draw(int color);
	void changeColor();
	void changeSize();
};

