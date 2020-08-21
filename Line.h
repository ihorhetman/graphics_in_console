#pragma once
#include"Figure.h"
class Line :public Figure 
{
protected:
	char TypeOfFigure[10] = "Line";
	int x2;
	int y2;
public:
	Line();
	Line(int x2, int y2);
	void move(int dx, int dy, bool state);
	void write(std::ofstream &out);
	void read(std::ifstream &in);
protected:
	void show();
	void draw(int color);
	void changeColor();
	void changeSize();
	void returnToDefault();
};