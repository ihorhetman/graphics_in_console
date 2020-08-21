#pragma once
#include<fstream>
const int Grow = 10;
class Figure
{
protected:
	char TypeOfFigure[15] = "Figure";
	int x1; int y1;
	int def_x1=200; int def_y1=200;
	int color; int tmpColor;
	int def_Color = 2;
public:
	Figure();
	Figure(int x1, int y1, int color);
	virtual void move(int dx, int dy, bool state);
	virtual void changeColor();
	virtual void changeSize();
	virtual void makeInvisible(bool state);
	virtual void returnToDefault();
	virtual	void show_all();
	virtual void read(std::ifstream &in);
	virtual void write(std::ofstream &out);
protected:
	virtual void draw(int color);
	void show();
	void hide();
};


