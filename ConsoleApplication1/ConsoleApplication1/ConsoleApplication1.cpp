#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const char* MENU[] =
{
	"1. Start Game",
	"2. Load Game",
	"3. Options",
	"4. Exit"

};
static int NUM_MENU_ITEMS = sizeof(MENU) / sizeof(MENU[0]);


void printColored(const char* text, bool IS_IT_COSORED)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Сохраняем текущий цвет
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD oldColor = csbi.wAttributes;
	if (!IS_IT_COSORED)
	{
		cout << text << endl;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << text << endl;
		SetConsoleTextAttribute(hConsole, oldColor);
	}
}


void darwMenu(int ACTIVE_MENU_ITEM)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD menuPos = { 0, 0 }; // координаты начала меню
	SetConsoleCursorPosition(hConsole, menuPos);

	for (int i = 0; i < NUM_MENU_ITEMS; i++)
	{
		printColored(MENU[i], i == ACTIVE_MENU_ITEM);
	}
}

void selectedItem(int ACTIVE_MENU_ITEM)
{
	system("cls");
	cout << "You selected: " << MENU[ACTIVE_MENU_ITEM] << endl;
	system("pause");
}


int main()
{	
	int ACTIVE_MENU_ITEM = 0;
	bool MENU_ACTIVE = true;

	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE; // скрыть курсор
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	darwMenu(ACTIVE_MENU_ITEM);

	while (MENU_ACTIVE)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
				case 80: // стрелка вниз
					ACTIVE_MENU_ITEM++;
					if (ACTIVE_MENU_ITEM >= NUM_MENU_ITEMS) ACTIVE_MENU_ITEM = 0;
					darwMenu(ACTIVE_MENU_ITEM);
					break;
				case 72: // стрелка вверх
					ACTIVE_MENU_ITEM--;
					if (ACTIVE_MENU_ITEM < 0) ACTIVE_MENU_ITEM = NUM_MENU_ITEMS-1;
					darwMenu(ACTIVE_MENU_ITEM);
					break;
				case 13: // Enter
					selectedItem(ACTIVE_MENU_ITEM);
					MENU_ACTIVE = false;
					break;
					
			}
		}
	}



}