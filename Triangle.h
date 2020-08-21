#pragma once
#include"Line.h"
class Triangle : public Figure
{
protected:
	char TypeOfFigure[10] = "Triangle";
	int x2,x3;
	int y2,y3;
public:
	Triangle();
	Triangle(int x2, int y2, int x3, int y3, int color);
	void move(int dx, int dy, bool state);
	void write(std::ofstream &out);
protected:
	void show();
	void draw(int color);
	void changeColor();
	void changeSize();
	void returnToDefault();
};

