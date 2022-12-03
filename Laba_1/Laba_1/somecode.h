#pragma once
#include "somecode.h"

#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>
#include <conio.h>
struct TSettings {
	HANDLE hStdOut;
	char* ProgrammName;
	int (*CreateSetting)(struct TSettings*);
	void (*ShowSettings)(struct TSettings*);
	int (*SettingConsole)(HANDLE hStdOut);
};
struct TMenu {
	HANDLE hStdOut;
	char** MenuNames;
	int Length;
	int* ItemIndex;
	void (*Show)();

};

int CreateSettings(struct TSettings* config);
void Show();
int setting_console(HANDLE hStdOut);
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
int sort_mass();
