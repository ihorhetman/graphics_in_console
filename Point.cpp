#include "Point.h"
#include"graphics.h"
using namespace Grfx;
Graphics grPoint;
const int radius = 7;
Point::Point()
{
	r = radius;
	show();
}
Point::Point(int x1, int y1, int color, int r)
{
}
void Point::move(int dx, int dy, bool state)
{
	if (state == true)
		hide();
	else
		;
	x1 += dx;
	y1 += dy;
	show();
}
void Point::show()
{
	draw(color);
}
void Point::draw(int color)
{
	grPoint.setcolor(color);
	grPoint.circle(x1, y1, r);
}
void Point::changeColor()
{
	this->color = color + 1;
	show();
}
void Point::changeSize()
{
	;
}
void Point::write(std::ofstream & out)
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
