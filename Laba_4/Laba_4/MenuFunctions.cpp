#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "MenuFunctions.h"


void CreateSettingsConsoleForMenu(SettingsStruct* set) {
	SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода\
	// отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(set->hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(set->hStdOut, &structCursorInfo);
	// задаЄм серый фон дл¤ окна консоли
	SetConsoleTextAttribute(set->hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// очищаем экран, чтобы настройка цвета применилась
	system("cls");
}
void CreateSettingsConsoleForUser(SettingsStruct* set) {
	SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода\
	// отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(set->hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(set->hStdOut, &structCursorInfo);
	// задаЄм серый фон дл¤ окна консоли
	SetConsoleTextAttribute(set->hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// очищаем экран, чтобы настройка цвета применилась
	system("cls");
}

void InputArray(SettingsStruct* set)
{
	set->SortMass = 0;
	CreateSettingsConsoleForUser(set);
	system("cls");
	printf("ВВедите длинну массива: ");
	scanf_s("%d", &set->arraySize);
	if (set->arraySize > 0) {
		set->array = (int*)malloc(sizeof(int) * (set->arraySize));
		int tmp;
		for (int i = 0;i < set->arraySize;i++)
		{
			std::cout << "ВВедите элемент [" << i << "]: ";
			std::cin >> tmp;
			set->array[i] = tmp;
		}
		system("pause");
		system("cls");
	}else {
		std::cout << "Вышей гениальности нет предела!!" << std::endl;
		system("pause");
		set->arraySize = 0;
	}
}
void InputRandomArray(SettingsStruct* set)
{
	set->SortMass = 0;
	srand(time(NULL));
	CreateSettingsConsoleForUser(set);
	system("cls");
	printf("ВВедите длинну массива: ");
	scanf_s("%d", &set->arraySize);
	if (set->arraySize > 0) {
		set->array = (int*)malloc(sizeof(int) * (set->arraySize));
		for (int i = 0;i < set->arraySize;i++)
		{
			set->array[i] = 1 + rand() % 4000;
			std::cout << set->array[i] << " ";
		}
		system("pause");
		system("cls");
	}else {
		std::cout << "Вышей гениальности нет предела!!" << std::endl;
		system("pause");
		set->arraySize = 0;
	}
}
//-
void InputPartToFile(SettingsStruct* set)
{
	std::cout << "InputPartToFile" << std::endl;
	system("pause");
}
//-
void InputArrayFromFile(SettingsStruct* set)
{
	std::cout << "InputArrayFromFile" << std::endl;
	system("pause");
}
void PrintArray(SettingsStruct* set) {
	system("cls");
	for (int i = 0; i < set->arraySize; i++) {
		printf("%d, ", set->array[i]);
	}
	system("pause");
	system("cls");
}
int SimpleSearch(int* Mass, int MassSize, int key) {
	for (int i = 0; i < MassSize; i++)
		if (Mass[i] == key)
			return i;
	return -1;
}
int BinarySearch(int * Mass,int MassSize, int key) {
	int First = 0, Last = MassSize - 1;
	while (Last > First) 
	{
		int tmp = (First + Last) / 2;
		if (Mass[tmp] < key) { First = tmp + 1;}
		else if (Mass[tmp] > key) { Last = tmp - 1;}
		else {return tmp;}
	}
	if (Mass[First] == key) {return First;}
	else {return -1;}
}
void SortArrayByBubbleMetod(SortFunction *Tmp, int First, int Last) {
	int temp;
	for (int i = 0; i < Tmp->ArraySize - 1; i++) {
		for (int j = 0; j < Tmp->ArraySize - i - 1; j++) {
			if (Tmp->Array[j] > Tmp->Array[j + 1]) {
				temp = Tmp->Array[j];
				Tmp->Array[j] = Tmp->Array[j + 1];
				Tmp->Array[j + 1] = temp;
				Tmp->SwapCounter++;
			}
		}
	}
}
void SortArrayByHoarMetod(SortFunction* Tmp,int First, int Last)
{
	int i = First, j = Last;
	int tmp, x = Tmp->Array[(First + Last) / 2];
	do {
		while (Tmp->Array[i] < x)
			i++;
		while (Tmp->Array[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = Tmp->Array[i];
				Tmp->Array[i] = Tmp->Array[j];
				Tmp->Array[j] = tmp;
				(Tmp->SwapCounter)++;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < Last) {

		SortArrayByHoarMetod(Tmp,i,Last);
	}
	if (First < j) {
		
		SortArrayByHoarMetod(Tmp,First,j);
	}
}
void SortArrayBySelectionMethod(SortFunction* Tmp, int First, int Last) {
	int minPosition,tmp;
	for (int i = 0; i < Tmp->ArraySize; i++)
	{
		minPosition = i;
		for (int j = i + 1; j < Tmp->ArraySize; j++)
			if (Tmp->Array[minPosition] > Tmp->Array[j])
				minPosition = j;
		tmp = Tmp->Array[minPosition];
		Tmp->Array[minPosition] = Tmp->Array[i];
		Tmp->Array[i] = tmp;
		Tmp->SwapCounter++;
	}
}
void SortArrayByInsertMethod(SortFunction* Tmp, int First, int Last) {
	for (int i = 0 + 1;i < Tmp->ArraySize;i++) {
		for (int j = i; j > 0 && Tmp->Array[j - 1] > Tmp->Array[j];j--) {
			Tmp->SwapCounter++;
			int tmp = Tmp->Array[j - 1];
			Tmp->Array[j - 1] = Tmp->Array[j];
			Tmp->Array[j] = tmp;
		}
	}
}
//-
void SortComparison(SettingsStruct* set)
{
	SortFunction Tmp;
	Tmp.ArraySize = set->arraySize;

	
	    memmove(&(Tmp.Array),&(set->array),sizeof(set->array));
		Tmp.Array[0] = 0;
		for (int j = 0;j < Tmp.ArraySize ;j++) {
			std::cout << set->array[j] << std::endl;
			
		}system("pause");
		set->SortMenuFucntions[0](&Tmp,0,Tmp.ArraySize-1);
		
		std::cout << Tmp.SwapCounter<<std::endl;
		system("pause");
		Tmp.SwapCounter = 0;

	system("pause");
}

//-
void EfficiencyComparison(SettingsStruct* set)
{
	std::cout << "EfficiencyComparison" << std::endl;
	system("pause");
}

int constractMenu(HANDLE hStdOut, std::string* menu_names, int menu_size) {
	int iKey = 67;
	COORD cursorPos;
	int choose_pos = 0;
	system("cls");
	//iKey = 67;
	cursorPos.X = 0; cursorPos.Y = 0;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	while (iKey != 27 && iKey != 13) {
		switch (iKey) {
		case 72:
			(choose_pos)--;
			break;
		case 80:
			(choose_pos)++;
			break;
		}
		system("cls");
		if (choose_pos < 0) { choose_pos = menu_size - 1; }
		if (choose_pos > menu_size - 1) { choose_pos = 0; }
		for (int i = 0; i < menu_size; i++) {
			cursorPos.X = 3; cursorPos.Y = i;
			SetConsoleCursorPosition(hStdOut, cursorPos);
			std::cout << menu_names[i] << " " << std::endl;
		}
		cursorPos.X = 0; cursorPos.Y = choose_pos;
		SetConsoleCursorPosition(hStdOut, cursorPos);
		std::cout << "<<" << std::endl;
		cursorPos.X = menu_names[choose_pos].size() + 3 + 1; cursorPos.Y = choose_pos;

		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		iKey = _getch();
	}
	system("cls");
	return choose_pos;
}

void ExperimentsMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index = 0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->ExperimentsMenu, set->ExperimentsMenuSize);
		if (Index < set->ExperimentsMenuSize - 1) {
			set->ExperimentsMenuFucntions[Index](set);
		}
		else {
			flag = 0;
		}
	}
}

void AlgMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index = 0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->AlgMenu, set->AlgMenuSize);
		if (Index < set->AlgMenuSize-1) {
			set->AlgMenuFucntions[Index](set);
		}
		else {
			flag = 0;
		}
	}
}

void SettingsMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index = 0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->SettingMenu, set->SettingMenuSize);
		if (Index < set->SettingMenuSize - 1) {
			set->SettingsMenuFucntions[Index](set);
		}
		else {
			flag = 0;
		}
	}
}

void SearchMenuShow(SettingsStruct* set)  {
	bool flag = 1;
	int Index = 0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->SerchMenu, set->SerchMenuSize);
		if (Index < set->SerchMenuSize - 1) {
			if (set->arraySize>0) {
				CreateSettingsConsoleForUser(set);
				int key;
				system("cls");
				std::cout << "Искомый элемент: ";
				std::cin >> key;
				if (Index == 1) {
					std::cout <<"Бинарный поиск работает только при отсортированном массиве, "
						<<"поэтому он обдут отсортирован метотом Хоара" << std::endl;
					system("pause");
					int SwapCounter;
					//set->SortMenuFucntions[3](set->array, set->arraySize, 0, set->arraySize - 1, &SwapCounter);
					set->SortMass = 1;
				};
				int tmp = set->SerchMenuFucntions[Index](set->array, set->arraySize, key);
				if (tmp > -1) {
					std::cout << "Искомый элемент в массиве под индексом: " << tmp << std::endl;
				}
				else { std::cout << "Искомый элемент в массиве не обнаружен" << std::endl; }
				system("pause");
				CreateSettingsConsoleForMenu(set);
			}
			else {
				std::cout << "Было бы славно если бы массив был задан, прежде чем что-либо искать" << std::endl;
				system("pause");
			}
		}
		else {
			flag = 0;
		}
	}
}

void SortMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index = 0;

	while (flag) {
		Index = constractMenu(set->hStdOut, set->SortMenu, set->SortMenuSize);
		if (Index < set->SortMenuSize - 1) {
			SortFunction Tmp;
			Tmp.ArraySize = set->arraySize;
			int First = 0;
			int Last = Tmp.ArraySize - 1;
			//memcpy(Tmp.Array, set->array, set->arraySize * sizeof(int));
			Tmp.Array = set->array;
			if (set->SortMass) {
				std::cout << "Массив уже отсортирован" << std::endl;
				system("pause");
			}
			else {
				if (set->arraySize >0) {
					int SwapCounter = 0;
					unsigned __int64 TaktFirst, TaktLast;
					unsigned int start_time = clock();
					TaktFirst = __rdtsc();
					set->SortMenuFucntions[Index](&Tmp,First, Last);
					TaktLast = __rdtsc();
					unsigned int stop_time = clock();
					PrintArray(set);
					std::cout << std::endl;
					std::cout << "Количество перестановок: " << Tmp.SwapCounter << std::endl;
					std::cout << "Количество тактов процессора: " << TaktLast - TaktFirst << std::endl;
					std::cout << "Количество времени: " << stop_time - start_time << std::endl;
					set->SortMass = 1;
					system("pause");
				}
				else {
					std::cout << "Было бы славно если бы массив был задан, прежде чем его сортировать" << std::endl;
					system("pause");
				}
			}
		}
		else {
			flag = 0;
		}
	}
}

void MainMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index=0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->MainMenu, set->MainMenuSize);
		if (Index < set->MainMenuSize-1){
			set->MainMenuFucntions[Index](set);
		}
		else {
			flag = 0;
		}
	}
}

void InputArrayMenuShow(SettingsStruct* set) {
	bool flag = 1;
	int Index = 0;
	while (flag) {
		Index = constractMenu(set->hStdOut, set->InputArrayMenu, set->InputArrayMenuSize);
		if (Index < set->InputArrayMenuSize - 1) {
			set->InputArrayMenuFunctions[Index](set);
		}
		else {
			flag = 0;
		}
	}
}
