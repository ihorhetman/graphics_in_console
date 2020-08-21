#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<ctime>
#include"Type of figures.h"
using namespace std;
const char LARROW = 'K';
const char RARROW = 'M';
const char UARROW = 'H';
const char DARROW = 'P';

const char LINE = '1';
const char TRIANGLE = '2';
const char RECTANGLE = '3';
const char CIRCLE = '4';
const char POINT = '5';
const char NEWAGREGATE = '9';

const char MoveWithoutHide = 'v';
const char ClearScreen = 'c';
const char AddToAgregate = 'a';
const char CreateAgregate = 's';
const char ChangeColor = 'q';
const char ChangeSize = 'w';
const char ChangeFigureCounter = 'z';
const char AutoMove = 'x';
const char MakeInvisible = 'i';
const char ReturnToDefault = 'r';
const char SaveToFile = 'b';
const char ReadFromFile = 'n';

const char HELP = ';';
const int  STEP = 10;
const int TAB = 9;
const int SizeOfArray = 10;

void timer(int ms)
{
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC;  // время завершения 
	while (clock() < end_time)
	{
	}
}
void push_back(Figure**&array, int &AmountOfFigures, Figure *newFigure)
{
	Figure**newArray = new Figure*[AmountOfFigures + 1];
	for (int i = 0; i < AmountOfFigures; i++)
	{
		newArray[i] = array[i];
	}
	newArray[AmountOfFigures] = newFigure;
	AmountOfFigures++;
	delete[] array;
	array = newArray;
}
void pop(Figure**&array, int &AmountOfFigures, int NowIndex)
{
	for (int i = NowIndex; i < AmountOfFigures; i++)
	{
		array[i] = array[i + 1];
	}
	AmountOfFigures--;
}
void changefigurecounter(int AmountOfFigures, int &NowIndex)
{
	if (NowIndex == AmountOfFigures - 1 || NowIndex == AmountOfFigures)
		NowIndex = 0;
	else
		NowIndex++;
	cout << "Now # " << NowIndex << "AofF = " << AmountOfFigures << endl;
}
void help()
{
	cout << "1 - Line" << endl;
	cout << "2 - Triangle" << endl;
	cout << "3 - Rectangle" << endl;
	cout << "4 - Circle" << endl;
	cout << "5 - Point" << endl;
	cout << "9 - Initialize agregate" << endl;
	cout << "a - add to agregate" << endl;
	cout << "s - create an agregate" << endl;
	cout << "z - next figure" << endl;
	cout << "w - change size" << endl;
	cout << "q - change color" << endl;
	cout << "r - return to default" << endl;
	cout << "i - hide figure" << endl;
	cout << "x - auto move" << endl;
	cout << "c - to clean screen" << endl;
	cout << "n - load from file" << endl;
	cout << "b - load all figures to file" << endl;
	cout << "To continue press any key" << endl;
	system("PAUSE>NULL");
	system("cls");
}
void show_all(Figure**array, int AmountOfFigures)
{
	for (int i = 0; i < AmountOfFigures; i++)
	{
		array[i]->show_all();
	}
}
bool change_state(bool state)
{
	if (state == true)
		state = false;
	else
		state = true;
	return state;
}
void auto_move(Figure**array, int NowIndex, bool move_mode)
{
	char esc=' ';
	while(esc!=27)
	{
		if (_kbhit())
			esc = _getch();
		if (esc == 27)
			return;
		array[NowIndex]->move(+STEP, +STEP, true);
		timer(500);

		if (_kbhit())
			esc = _getch();
		if (esc == 27)
			return;
		array[NowIndex]->move(+STEP, -STEP, true);
		timer(500);

		if (_kbhit())
			esc = _getch();
		if (esc == 27)
			return;
		array[NowIndex]->move(-STEP, -STEP, true);
		timer(500);

		if (_kbhit())
			esc = _getch();
		if (esc == 27)
			return;
		array[NowIndex]->move(-STEP, +STEP, true);
		timer(500);
	}

}
Figure* Create_type_of_figure(char *TypeOfFigure)
{
	Figure* new_fig = nullptr;
	if (strcmp(TypeOfFigure, "L") == 1)
		new_fig = new Circle;
	else if (strcmp(TypeOfFigure, "T") == 1)
		new_fig = new Triangle;
	else if (strcmp(TypeOfFigure, "R") == 1)
		new_fig = new Rectangle;
	else if (strcmp(TypeOfFigure, "C") == 1)
		new_fig = new Circle;
	else if (strcmp(TypeOfFigure, "P") == 1)
		new_fig = new Point;
	return new_fig;
}

void read_file(Figure**array, int &AmountOfFigures, int&NowIndex, char*argv[], int argc)
{
	ifstream file_in;
	string FileNameRead;
	char FigureName[15];
		FileNameRead = argv[1];
	cout << FileNameRead << endl;
	file_in.open(FileNameRead);
	if (!file_in.is_open())
	{
		cout << "Error in opening file!" << endl;
		system("pause");
		system("cls");
	}
	int size_in;
	file_in >> size_in;
	file_in >> FigureName;
	Figure*ptr_fig = nullptr;
	for (int i = 0; i<size_in; i++)
	{
		ptr_fig = Create_type_of_figure(FigureName);
		ptr_fig->read(file_in);
		push_back(array, AmountOfFigures, ptr_fig);
	}
	file_in.close();
}

void write_file(Figure**array, int AmountOfFigures, char *argv[], int argc)
{
	ofstream file_out;
	string FileNameRead;
	FileNameRead = argv[1];
	file_out.open(FileNameRead);
	file_out << AmountOfFigures << endl;
	for (int i = 0; i < AmountOfFigures; i++)
	{
		array[i]->write(file_out);
	}
	file_out.close();
	cout << "Figures saved to " << FileNameRead << endl;
}
int main(int argc, char*argv[])
	{
	int counter = 0;
	int NowIndex = -1;
	int Amount_of_figures = 0;
	int num_of_agregate = -1;
	bool state = true;
	bool move_mode = false;
	bool hide_mode = false;
	char key;

	cout << "Hello user" << endl;
	cout << "Here is short tutorial. To call it later, press F1" << endl;
	help();

	Figure**array = new Figure*[Amount_of_figures];
	Agregate agr[SizeOfArray];

	while (key = _getch(), key != 27)
	{
		if (key == '\xe0'&& Amount_of_figures != 0)
		{
			key = _getch();

			switch (key)
			{

			case LARROW:
				array[NowIndex]->move(-STEP, 0, state);
				break;
			case RARROW:
				array[NowIndex]->move(+STEP, 0, state);
				break;
			case UARROW:
				array[NowIndex]->move(0, -STEP, state);
				break;
			case DARROW:
				array[NowIndex]->move(0, +STEP, state);
				break;

			default:
			{};
			}

		}
		else
		{
			switch (key)
			{
			case MoveWithoutHide:
				state = change_state(state);
				break;

			case AutoMove:
				cout << "To stop auto move press Escape" << endl;
				timer(700);
				system("cls");
				show_all(array, Amount_of_figures);
				auto_move(array, NowIndex, move_mode);
				cout << "Auto move is stopped" << endl;
				timer(500);
				system("cls");
				show_all(array, Amount_of_figures);
				break;

			case MakeInvisible:
				hide_mode = change_state(hide_mode);
				array[NowIndex]->makeInvisible(hide_mode);
				break;

			case ReturnToDefault:
				array[NowIndex]->returnToDefault();
				break;

			case LINE:
				push_back(array, Amount_of_figures, new Line);
				NowIndex++;
				break;

			case TRIANGLE:
				push_back(array, Amount_of_figures, new Triangle);
				NowIndex++;
				break;

			case RECTANGLE:
				push_back(array, Amount_of_figures, new Rectangle);
				NowIndex++;
				break;

			case CIRCLE:
				push_back(array, Amount_of_figures, new Circle);
				NowIndex++;
				break;

			case POINT:
				push_back(array, Amount_of_figures, new Point);
				NowIndex++;
				break;

			case NEWAGREGATE:
				cout << "Agregate initialized" << endl;
				num_of_agregate++;
				break;

			case AddToAgregate:
				if (num_of_agregate == -1)
					cout << "Initialize an Agregate with 9" << endl;
				else
				{
					agr[num_of_agregate].AddToAgregate(array[NowIndex]);
					pop(array, Amount_of_figures, NowIndex);
					cout << "Figure # " << NowIndex << " added to agr" << endl;
				}
				break;

			case CreateAgregate:
				if (num_of_agregate == -1)
				{
					cout << "Add 2 figures first" << endl;
					timer(700);
					system("cls");
					show_all(array, Amount_of_figures);
				}
				else
				{
					push_back(array, Amount_of_figures, &agr[num_of_agregate]);
					cout << "Agregate created" << endl;
					cout << "Press any key to continue" << endl;
					system("PAUSE>NULL");
					system("cls");
					show_all(array, Amount_of_figures);
				}
				break;

			case ChangeFigureCounter:
				changefigurecounter(Amount_of_figures, NowIndex);
				show_all(array, Amount_of_figures);
				break;

			case ChangeColor:
				array[NowIndex]->changeColor();
				break;

			case ChangeSize:
				array[NowIndex]->changeSize();
				break;

			case ClearScreen:
				system("cls");
				show_all(array, Amount_of_figures);
				break;

			case SaveToFile:
				write_file(array, Amount_of_figures, argv, argc);
				break;

			case ReadFromFile:
				read_file(array, Amount_of_figures, NowIndex, argv, argc);
				show_all(array, Amount_of_figures);
				break;
			case ';':
				help();
				show_all(array, Amount_of_figures);
				break;

			default:
			{
				
			};
			}
		}
	}
	cout << "BYE:)" << endl;
	timer(1000);
	return 0;
}
