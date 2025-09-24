#include <iostream>
#include <windows.h>
#include <conio.h>
#include "main_menu.h"

using namespace std;

int main()
{	
	int ACTIVE_MENU_ITEM = 0;
	bool MENU_ACTIVE = true;
	int NUM_MENU_ITEMS = numMenuItems();

	CONSOLE_CURSOR_INFO cursorInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE; // скрыть курсор
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	drawMenu(ACTIVE_MENU_ITEM);

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
					drawMenu(ACTIVE_MENU_ITEM);
					break;
				case 72: // стрелка вверх
					ACTIVE_MENU_ITEM--;
					if (ACTIVE_MENU_ITEM < 0) ACTIVE_MENU_ITEM = NUM_MENU_ITEMS-1;
					drawMenu(ACTIVE_MENU_ITEM);
					break;
				case 13: // Enter
					selectedItem(ACTIVE_MENU_ITEM);
					MENU_ACTIVE = false;
					break;
					
			}
		}
	}



}