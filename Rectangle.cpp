#include "Rectangle.h"
#include"graphics.h"
using namespace Grfx;
Graphics grRectangle;
const int length = 150;
int Rchanger = 1;
Rectangle::Rectangle()
{
	x2 = x1 + 150;
	y2 = y1 + 150;
	show();
}
Rectangle::Rectangle(int x2, int y2, int color)
{
}
void Rectangle::show()
{
	draw(color);
}
void Rectangle::draw(int color)
{
	grRectangle.setcolor(color);
	grRectangle.rectangle(x1, y1, x2, y2);
}
void Rectangle::move(int dx, int dy, bool state)
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
void Rectangle::changeColor()
{
	this->color = color + 1;
	show();
}
void Rectangle::changeSize()
{
	hide();
	this->x1 = x1 - Grow*Rchanger;
	this->y1 = y1 - Grow * Rchanger;
	this->x2 = x2 + Grow * Rchanger;
	this->y2 = y2 + Grow * Rchanger;
	if (x2 - x1 > 200)
		Rchanger = -1;
	else if (x2 - x1 < 100)
		Rchanger = 1;
	show();
}
void Rectangle::write(std::ofstream & out)
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
