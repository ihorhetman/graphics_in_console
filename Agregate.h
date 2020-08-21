#pragma once
#include "Figure.h"
const int N = 20;
class Agregate: public Figure
{
protected:
	char TypeOfFigure[15] = "Agregate";
	Figure**agregate = new Figure*[N];
	int AmountOfFiguresInAgregate = 0;
public:
	Agregate();
	void AddToAgregate(Figure*figure);
	void makeInvisible(bool state);
	void show_all();
	void write(std::ofstream &out);
protected:
	void move(int dx, int dy, bool state);
	void changeColor();
	void changeSize();
};

