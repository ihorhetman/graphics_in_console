#pragma once
#include"Figure.h"
class Circle : public Figure
{
protected:
	char TypeOfFigure[10] = "Circle";
	int r;
public:
	Circle();
	Circle(int x1, int y1, int color, int r);
	void move(int dx, int dy, bool state);
	void write(std::ofstream &out);
protected:
	void show();
	void draw(int color);
	void changeColor();
	void changeSize();
};
