#include "Line.h"
#include"graphics.h"
#include<fstream>
using namespace Grfx;
Graphics grLine;
const int length = 100;
int Lchanger = 1;
Line::Line(): Figure()
{
	x2 = x1 + length;
	y2 = x1 + length;
	show();
}
Line::Line(int x2, int y2):Figure()
{
	this->x2 = x2;
	this->y2 = y2;
}
void Line::show()
{
	draw(color);
}
void Line::draw(int color)
{
	grLine.setcolor(color);
	grLine.line(x1, y1, x2, y2);
}
void Line::changeColor()
{
	this->color = color + 1;
	show();
}
void Line::changeSize()
{
	hide();
	this->x2 = x2 + Grow * Lchanger;
	this->y2 = y2 + Grow * Lchanger;
	if (x2 - x1 > 150)
		Lchanger = -1;
	else if (x2 - x1 < 100)
		Lchanger = 1;
	show();
}
void Line::returnToDefault()
{
	hide();
	x1 = def_x1;
	y1 = def_y1;
	x2 = x1 + 100;
	y2 = y1 + 100;
	color = def_Color;
	show();
}
void Line::move(int dx, int dy, bool state)
{
	if (state == true)
		hide();
	else
		;

	x1 += dx;
	y1 += dy;
	x2 += dx;
	y2 += dy;
	show();
}

void Line::write(std::ofstream & out)
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
	out << std::endl;
}

void Line::read(std::ifstream & in)
{
	in >> this->TypeOfFigure;
	in >> this->x1;
	in >> this->y1;
	in >> this->color;
	in >> this->x2;
	in >> this->y2;
}

