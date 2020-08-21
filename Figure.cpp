#include"Figure.h"
#include"graphics.h"
#include<fstream>
using namespace Grfx;
Graphics gr;
Figure::Figure()
{
	x1 = 200;
	y1 = 200;
	color = 2;
}
Figure::Figure(int x1, int y1, int color)
{
	this->x1 = x1;
	this->y1 = y1;
	this->color = color;
}

void Figure::draw(int color)
{
	gr.setcolor(color);
} 
void Figure::show()
{
	draw(color);
}
void Figure::hide()
{
	draw(0);
}
void Figure::move(int dx, int dy, bool state)
{
	if (state == true)
		hide();
	else
		;

	x1 += dx;
	y1 += dy;
	show();
}
void Figure::changeColor()
{
	gr.setcolor(color + 1);
	draw(color);
}
void Figure::changeSize()
{
	
}
void Figure::makeInvisible(bool state)
{
	if (state == true)
	{
		tmpColor = color;
		color = 0;
	}
	else
		color = tmpColor;
	draw(color);
}
void Figure::returnToDefault()
{
	hide();
	this->x1 = def_x1;
	this->y1 = def_y1;
	this->color = def_Color;
	show();
}
void Figure::show_all()
{
	show();
}

void Figure::write(std::ofstream & out)
{
	out << this->TypeOfFigure;
	out << ' ';
	out << this->x1;
	out << ' ';
	out << this->y1;
	out << ' ';
	out << this->color;
	out << std::endl;
}

void Figure::read(std::ifstream &in)
{
	in >> this->TypeOfFigure;
	in >> this->x1;
	in >> this->y1;
	in >> this->color;
}
