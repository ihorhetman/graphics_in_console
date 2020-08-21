#include "Agregate.h"
#include<fstream>
Agregate::Agregate()
{
	Figure**agregate = new Figure*[N];
}

void Agregate::AddToAgregate(Figure * figure)
{
	agregate[AmountOfFiguresInAgregate] = figure;
	AmountOfFiguresInAgregate++;
}

void Agregate::makeInvisible(bool state)
{
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->makeInvisible(state);
}

void Agregate::show_all()
{
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->show_all();
}

void Agregate::write(std::ofstream & out)
{
	out << this->TypeOfFigure <<';' << ' ' << "Amount Of Figures In Agregate = " << AmountOfFiguresInAgregate << std::endl;
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->write(out);
}

void Agregate::move(int dx, int dy, bool state)
{
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->move(dx, dy, state);
}

void Agregate::changeColor()
{
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->changeColor();
}

void Agregate::changeSize()
{
	for (int i = 0; i < AmountOfFiguresInAgregate; i++)
		agregate[i]->changeSize();
}

