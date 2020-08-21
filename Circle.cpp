#include "Circle.h"
#include"graphics.h"
using namespace Grfx;
Graphics grCircle;
const int radius = 80;
int Cchanger = 1;
Circle::Circle()
{
	r = radius;
	show();
}
Circle::Circle(int x1, int y1, int color, int r)
{
}
void Circle::move(int dx, int dy, bool state)
{
	if (state == true)
		hide();
	else
		;
	x1 += dx;
	y1 += dy;
	show();
}
void Circle::show()
{
	draw(color);
}
void Circle::draw(int color)
{
	grCircle.setcolor(color);
	grCircle.circle(x1, y1, r);
}
void Circle::changeColor()
{
	this->color = color + 1;
	show();
}
void Circle::changeSize()
{
	hide();
	this->r = r + Grow*Cchanger;
	if (x1 - r > 170)
		Cchanger = 1;
	else if (x1 - r < 70)
		Cchanger = -1;
	show();
}
void Circle::write(std::ofstream & out)
{
	out << this->TypeOfFigure;
	out << ' ';
	out << this->x1;
	out << ' ';
	out << this->y1;
	out << ' ';
	out << this->color;
	out << ' ';
	out << this->r;
	out << std::endl;
}
