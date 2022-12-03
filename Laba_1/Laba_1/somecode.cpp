#include "somecode.h"

#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>
#include <conio.h>

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






void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
	int iKey; 
	COORD cursorPos; 
	*choose_pos = 0;
	system("cls");
	iKey = 67;
	cursorPos = (COORD) { 0, 0 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
		switch (iKey) {
		case KEY_ARROW_UP:
			(*choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			(*choose_pos)++;
			break;
		}
		system("cls");
		if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
		if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos = (COORD) { 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("%s \n", menu_names[i]);
		}
		cursorPos = (COORD) { 0, * choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<", iKey);
		cursorPos = (COORD) { strlen(menu_names[*choose_pos]) + 3 + 1, * choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		iKey = _getch();
	}
}
//-----------------------------------------------
//TMenu
void Show(){
	printf("ShowMenu\n");
};
//-----------------------------------------------
//TSettings
int CreateSettings(struct TSettings* config)
{
	printf("CreateSettings\n");
	config->hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("%s\n",__argv[0]);
	config->ProgrammName = (char)malloc(sizeof(char) * (12));
//	config->ProgrammName 
	//memcpy(config->ProgrammName, __argv[0], strlen(__argv[0]));


	char str[12]="0123456789";

	config->ProgrammName = "1234567890";
	strcpy_s(config->ProgrammName,10, "Finish");
	printf(" % s\n", config->ProgrammName);

}   










void input(int* arr, int* size)
{
	system("cls");
	printf("������� ������ ������: ");
	scanf_s("%d", size);

	arr = (int)malloc(sizeof(int) * *size);
	for (int i = 0;i < *size;i++)
	{
		printf("\n������� ����� �%d\n");
		scanf_s("%d", &arr[i]);
	}
	system("pause");
	system("cls");
}
void PrintArray(int* f[], int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		printf("%d\n", f[i]);
	}
	system("pause");
	system("cls");
}
void EaseSearch(int* array, int ArraySize) {
	int SerchItem = 0;
	int i = 0;
	int SearchFlag = 0;
	system("cls");
	printf("������� ������� �������\n");
	scanf_s("%d", &SerchItem);



	for (i = 0;i < ArraySize;i++) {
		if (array[i] == SerchItem) {
			//printf("%d\n", array[i]);
			SearchFlag = 1;
			break;
		}
	}
	if (SearchFlag == 1) {
		printf("������� ������� ��� �������� %d(������� � 0)\n", i);
	}
	else {
		printf("������� ������� �� ������\n");
	}
	system("pause");
	system("cls");
}
void SortArray(int* num, int size)
{
	// ��� ���� ���������
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			if (num[j - 1] > num[j]) // ���� ������� ������� ������ �����������
			{
				int temp = num[j - 1]; // ������ �� �������
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}
int binarysearch(int a, int mass[], int n)
{
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
			high = middle - 1;
		else if (a > mass[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
}
int BinSearch(int* Array, int ArraySize)
{
	int SearchItem = 0, ItemIndex = 0;
	system("cls");
	printf("������� ������� �����\n");
	scanf_s("%d", &SearchItem);
	ItemIndex = binarysearch(SearchItem, Array, ArraySize);
	if (ItemIndex > -1) {
		printf("������� ������� ��� �������� %d(������� � 0)", ItemIndex);
	}
	else {
		printf("������� ������� �� ������");
	}
	system("pause");
	system("cls");
}
int sort_mass() {
	//constractMenu();
	system("pause");
	return 100;
}

int setting_console(HANDLE hStdOut) {
	system("title ������");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	
	char color[] = "color F5";
	system(color);
	
	system("cls");
}


