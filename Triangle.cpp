#include "Triangle.h"
#include"graphics.h"
using namespace Grfx;
Graphics grTriangle;
const int length = 100;
int Tchanger = 1;
Triangle::Triangle():Figure()
{
	x2 = x1 + length;
	y2 = y1 + length;
	x3 = x1 - length;
	y3 = y1 + length;
	show();
}
Triangle::Triangle(int x2, int y2, int x3, int y3, int color)
{
}
void Triangle::show()
{
	draw(color);
}
void Triangle::draw(int color)
{
	grTriangle.setcolor(color);
	grTriangle.triangle(x1, y1, x2, y2, x3, y3);
}
void Triangle::changeColor()
{
	this->color = color + 1;
	show();
}
void Triangle::changeSize()
{
	hide();
	this->y1 = y1 - Grow * Tchanger;
	this->x2 = x2 + Grow * Tchanger;
	this->y2 = y2 + Grow * Tchanger;
	this->x3 = x3 - Grow * Tchanger;
	this->y3 = y3 + Grow * Tchanger;
	if (x2 - x1 > 140)
		Tchanger = -1;
	else if (x2 - x1 < 100)
		Tchanger = 1;
	show();
}
void Triangle::returnToDefault()
{
	hide();
	x1 = def_x1;
	y1 = def_y1;
	x2 = x1 + 50;
	y2 = y1 + 50;
	x3 = x1 - 50;
	y3 = y1 + 50;
	color = def_Color;
	show();
}
void Triangle::move(int dx, int dy, bool state)
{
	if (state == true)
		hide();
	else
		;
	x1 += dx;
	y1 += dy;
	x2 += dx;
	y2 += dy;
	x3 += dx;
	y3 += dy;
	show();
}

void Triangle::write(std::ofstream & out)
{
	out << this->TypeOfFigure;
	out << ' ';
	out << this->x1;
	out << ' ';
	out << this->y1;
	out << ' ';
	out << this->color;
	out << ' ';
	out << this->x2;
	out << ' ';
	out << this->y2;
	out << ' ';
	out << this->x3;
	out << ' ';
	out << this->y3;
	out << std::endl;
}
