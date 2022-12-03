/* TMenu.cpp */
#include <string>
#include "TMenu.h"

// Обработка нажатия на элемент
void (show)();



//

void CreateMenuItems() {
//
	TMenu MainMenu;

	int countMenuItem = 3;
	TMenuItem MeinMenuItem1, MeinMenuItem2, MeinMenuItem3;

	MeinMenuItem1.create("NAME1", "Caption1");
	MeinMenuItem2.create("NAME2", "Caption2");
	MeinMenuItem3.create("NAME3", "Caption3");
	TMenuItem listMenuItem[3] = { MeinMenuItem1 ,MeinMenuItem2 ,MeinMenuItem3 };

	MainMenu.create(listMenuItem, countMenuItem, "MainMenu");
	MainMenu.show = show;
	MainMenu.show(MainMenu);

}


void TMenuItem::enabled()
{
	//
}

// Создание элемента
void TMenuItem::create(string name1,string caption1 )
{
	//
	//it.name = name1;
	//it.caption = caption1;
	name = name1;
	caption = caption1;
	
}

void TMenu::create(TMenuItem *listMenuItem, int countMenuItem, string objectName) 
{
	name = objectName;

}

void (show)(TMenu &Menu)
{
	//cout << Menu.GetName;

}

void CreateSettingsConsole(TSettings set) {
	system("title Application");
	set.hStdOut= GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(set.hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(set.hStdOut, &structCursorInfo);
	SetConsoleTextAttribute(set.hStdOut, 100101);

	system("cls");
	CreateMenuItems();

};

