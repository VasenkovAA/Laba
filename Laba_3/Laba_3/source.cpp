

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define MAIN_MENU_SIZE 3
#define ALG_MENU_SIZE 3
#define SEARCH_MENU_SIZE 3
#define SORT_MENU_SIZE 2
#define SETTINGS_MENU_SIZE 3

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

using namespace std;

int constractMenu(HANDLE hStdOut, string *menu_names, int menu_size) {
	int iKey = 67;
	COORD cursorPos;
	int choose_pos = 0;
	system("cls");
	//iKey = 67;
	cursorPos.X = 0; cursorPos.Y = 0;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(choose_pos)++;
			break;
		}
		system("cls");
		if (choose_pos < 0) { choose_pos = menu_size - 1; }
		if (choose_pos > menu_size - 1) { choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos.X = 3; cursorPos.Y = i;
			SetConsoleCursorPosition(hStdOut, cursorPos);
			cout << menu_names[i] << " " << endl;
			//printf("%s \n", menu_names[i]);
		}
		cursorPos.X = 3; cursorPos.Y = choose_pos;
		SetConsoleCursorPosition(hStdOut, cursorPos);
		cout << "<<" << endl;
		//printf("<<", iKey);
		cursorPos.X = menu_names[choose_pos].size() + 3 + 1; cursorPos.Y = choose_pos;

		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		iKey = _getch();
	}
	return 0;
	//return choose_pos;
}


