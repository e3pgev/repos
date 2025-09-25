#include "main_menu.h"
#include <iostream>
#include <windows.h>
#include "cursor_DVD.h"

using namespace std;

const char* MENU[] =
{
	"1. Start Game",
	"2. Load Game",
	"3. Options",
	"4. Exit"

};
static int NUM_MENU_ITEMS = sizeof(MENU) / sizeof(MENU[0]);

int numMenuItems()
{
	return NUM_MENU_ITEMS;
}

void drawMenu(int ACTIVE_MENU_ITEM)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD menuPos = { 0, 0 }; // координаты начала меню
	SetConsoleCursorPosition(hConsole, menuPos);

	for (int i = 0; i < NUM_MENU_ITEMS; i++)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		WORD oldColor = csbi.wAttributes;

		if (i == ACTIVE_MENU_ITEM)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << MENU[i] << endl;
			SetConsoleTextAttribute(hConsole, oldColor);
		}
		else
		{
			cout << MENU[i] << endl;
		}
	}
}

void selectedItem(int ACTIVE_MENU_ITEM)
{
	system("cls");
	cout << "Press Esc to escape" << endl;
	cursorDVD();
	system("cls");
}
