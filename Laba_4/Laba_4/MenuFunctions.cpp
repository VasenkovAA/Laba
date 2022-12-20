#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "MenuFunctions.h"
#include <string>
#include <string.h>
#include <io.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

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
bool FileExists(std::string fname)
{
	return not(_access(fname.c_str(), 0));
}
std::string SplitFilename(const std::string& str)
{
	std::size_t found = str.find_last_of("/\\");
	return str.substr(0, found);
}
void PrintArrayToFile(int* Array, int ArraySize,std::string PartToFile) {
	FILE *S1;
	S1 = fopen(PartToFile.c_str(), "w");
	for (int i = 0; i < ArraySize;i++) {
		fprintf(S1, "%d\n", Array[i]);
	}
	fclose(S1);
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
		{set->array[i] =rand();}
		if (set->arraySize < 1000) { PrintArray(set); }
		system("pause");
		system("cls");
	}else {
		std::cout << "Вышей гениальности нет предела!!" << std::endl;
		system("pause");
		set->arraySize = 0;
	}
}
void InputPartToFile(SettingsStruct* set)
{
	CreateSettingsConsoleForUser(set);
	std::cout << "ВВедите путь к рабочей директории:" << std::endl;
	std::cin >> set->PartToFile;
	std::cout << "Путь успешно задан" << std::endl; 
	CreateSettingsConsoleForMenu(set);
}
void InputArrayFromFile(SettingsStruct* set)
{
	CreateSettingsConsoleForUser(set);
	if (FileExists(set->PartToFile+"\input.txt")) {
		std::cout << "ВВедите количество элементов, которое будет прочитано из файла" << std::endl;
		std::cout << "Ичпользуется файл:" << set->PartToFile + "\input.txt" << std::endl;
		std::cin >> set->arraySize;
		int i = 0;
		if (set->arraySize > 0) {
			try {
				set->array = (int*)malloc(set->arraySize * sizeof(int));
				for (int j = 0;j < set->arraySize;j++) {
					set->array[j] = 0;
				}
				std::ifstream f(set->PartToFile + "\input.txt");
				bool TmpFlag = 0;
				while (f >> set->array[i]) {
					i++;
					if (i > set->arraySize) 
					{ 
						TmpFlag = 1;
						break;
					}
				}
				f.close();
				if (i < set->arraySize) {
					std::cout << "Колличество элементов в файле не соответствует требуемому количеству элементов массива." << std::endl;
					std::cout << "Иными словами - в файле меньше чисел чем размерность массива, которую вы задали." << std::endl;
					std::cout << "Поэтому все недостающие значения заменены на 0." << std::endl;
				}
				if (TmpFlag) {
					std::cout << "В файле значений больше чем задан массив. Считаны только "<<set->arraySize
						<< " значения(элемента)" << std::endl;
				}
			}
			catch (const char* msg)
			{
				std::cout << msg << std::endl;
			}

		}
		else {
			std::cout << "Я ценю твою гениальность, многоуважаемый пользователь,но всеже ты мне уже изрядно надоел." << std::endl;
			std::cout << "ВВеди длинну массива > 0" << std::endl;
		}
	}else{
		std::cout << "Некоректный путь до файла "<< set->PartToFile + "\input.txt" << std::endl;
	}
	system("pause");
	CreateSettingsConsoleForMenu(set);
	
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
	Tmp->SortName = "Bubble";

	int temp;
	for (int i = 0; i < Tmp->ArraySize - 1; i++) {
		for (int j = 0; j < Tmp->ArraySize - i - 1; j++) {
			Tmp->ComparisonCounter++;
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
	Tmp->SortName = "Hoar";
	int i = First, j = Last;
	int tmp, x = Tmp->Array[(First + Last) / 2];
	do {
		while (Tmp->Array[i] < x) 
			i++;
		while (Tmp->Array[j] > x)
			j--;
		Tmp->ComparisonCounter++;
		if (i <= j)
		{
			Tmp->ComparisonCounter++;
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
	Tmp->SortName = "Selection";
	int minPosition,tmp;
	for (int i = 0; i < Tmp->ArraySize; i++)
	{
		minPosition = i;
		for (int j = i + 1; j < Tmp->ArraySize; j++) {
			if (Tmp->Array[minPosition] > Tmp->Array[j])
				minPosition = j;
			Tmp->ComparisonCounter++;
		}
		tmp = Tmp->Array[minPosition];
		Tmp->Array[minPosition] = Tmp->Array[i];
		Tmp->Array[i] = tmp;
		Tmp->SwapCounter++;
	}
}
void SortArrayByInsertMethod(SortFunction* Tmp, int First, int Last) {
	Tmp->SortName = "Insert";
	for (int i = 0 + 1;i < Tmp->ArraySize;i++) {
		for (int j = i; j > 0 && Tmp->Array[j - 1] > Tmp->Array[j];j--) {
			Tmp->SwapCounter++;
			Tmp->ComparisonCounter++;
			int tmp = Tmp->Array[j - 1];
			Tmp->Array[j - 1] = Tmp->Array[j];
			Tmp->Array[j] = tmp;
		}
		Tmp->ComparisonCounter++;
	}
}

void SortComparison(SettingsStruct* set)
{
	if (set->arraySize > 1) {
		SortFunction* SettingsSortFunctionMass;
		unsigned __int64 TaktFirst, TaktLast;
		unsigned int stop_time, start_time;
		SettingsSortFunctionMass = new SortFunction[10];
		for (int j = 0; j < set->SortMenuSize - 1; j++) {
			SettingsSortFunctionMass[j].ArraySize = set->arraySize;
			SettingsSortFunctionMass[j].Array = (int*)malloc(SettingsSortFunctionMass[j].ArraySize * sizeof(int));
			SettingsSortFunctionMass[j].SwapCounter = 0;
			SettingsSortFunctionMass[j].ComparisonCounter = 0;
			memcpy((SettingsSortFunctionMass[j].Array), (set->array), set->arraySize * sizeof(int));
			start_time = clock();
			TaktFirst = __rdtsc();
			set->SortMenuFucntions[j](&SettingsSortFunctionMass[j], 0, SettingsSortFunctionMass[j].ArraySize - 1);
			TaktLast = __rdtsc();
			stop_time = clock();
			SettingsSortFunctionMass[j].TimeTakt = TaktLast - TaktFirst;
			SettingsSortFunctionMass[j].TimeSec = stop_time - start_time;
			std::cout << SettingsSortFunctionMass[j].SortName << " - Sorted - "
				<< SettingsSortFunctionMass[j].TimeSec<<"мСек" << std::endl;
		}
		int minSwap = SettingsSortFunctionMass[0].SwapCounter,
			minComparsion = SettingsSortFunctionMass[0].ComparisonCounter,
			minTime = SettingsSortFunctionMass[0].TimeSec;
		for (int j = 0; j < set->SortMenuSize - 1;j++) {
			if (SettingsSortFunctionMass[j].SwapCounter < minSwap) minSwap = SettingsSortFunctionMass[j].SwapCounter;
			if (SettingsSortFunctionMass[j].ComparisonCounter < minComparsion) minComparsion = SettingsSortFunctionMass[j].ComparisonCounter;
			if ((SettingsSortFunctionMass[j].TimeSec < minTime) && (set->arraySize > 1500))
			{
				minTime = SettingsSortFunctionMass[j].TimeSec;
			}
			else
			{
				if (SettingsSortFunctionMass[j].TimeTakt < minTime) { minTime = SettingsSortFunctionMass[j].TimeTakt; }
			}
		}
		for (int i = 0; i < set->SortMenuSize - 1;i++) {
			if (set->arraySize < 1500) {
				if (minTime != 0) {
					SettingsSortFunctionMass[i].SlowdownTime = SettingsSortFunctionMass[i].TimeTakt / minTime;
				}
				else { SettingsSortFunctionMass[i].SlowdownTime = -1; }
			}
			else {
				SettingsSortFunctionMass[i].SlowdownTime = SettingsSortFunctionMass[i].TimeSec / minTime;
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::left << std::setw(12) << "Sort name" << std::setw(12)
			<< std::setw(12) << "Takt"
			<< std::setw(5) << "Sec"
			<< std::setw(8) << "Sl time"
			<< std::setw(9) << "Swap"
			<< std::setw(8) << "Sl swap"
			<< std::setw(11) << "Comparison"
			<< std::setw(9) << "Sl comparison"
			<< std::endl;
		for (int i = 0;i < set->SortMenuSize - 1; i++) {
			std::cout << std::left << std::setw(12) << SettingsSortFunctionMass[i].SortName << std::setw(12)
				<< std::setw(12) << SettingsSortFunctionMass[i].TimeTakt
				<< std::setw(5) << SettingsSortFunctionMass[i].TimeSec
				<< std::setw(8) << SettingsSortFunctionMass[i].SlowdownTime
				<< std::setw(9) << SettingsSortFunctionMass[i].SwapCounter
				<< std::setw(8) << SettingsSortFunctionMass[i].SwapCounter / minSwap
				<< std::setw(11) << SettingsSortFunctionMass[i].ComparisonCounter
				<< std::setw(9) << SettingsSortFunctionMass[i].ComparisonCounter / minComparsion
				<< std::endl;

		}
		std::cout << std::endl;
		system("pause");
	}
	else {
		std::cout << "Думаю, прежде чем сортировать массив его нужно создать, нет?" << std::endl;
		system("pause");
	}
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

void EfficiencyComparison(SettingsStruct* set)
{
	bool flag = 1;
	int Index = 0;

	while (flag) {
		Index = constractMenu(set->hStdOut, set->SortMenu, set->SortMenuSize);
		if (Index < set->SortMenuSize - 1) {
			SortFunction Tmp;
			CreateSettingsConsoleForUser(set);
			std::cout << "Какое число элементов должно быть в массиве, сударь(сударыня)?" << std::endl;
			std::cin >> Tmp.ArraySize;
			CreateSettingsConsoleForMenu(set);
			int First = 0;
			int Last = Tmp.ArraySize - 1;
			if (Tmp.ArraySize > 0) {
				Tmp.Array = (int*)malloc(sizeof(int)*Tmp.ArraySize);
				for (int i = 0;i < Tmp.ArraySize;i++)
				{
					Tmp.Array[i] = rand();
				}
				Tmp.SwapCounter = 0;
				Tmp.ComparisonCounter = 0;
				unsigned __int64 TaktFirst, TaktLast;
				unsigned int start_time = clock();
				TaktFirst = __rdtsc();
				set->SortMenuFucntions[Index](&Tmp, First, Last);
				TaktLast = __rdtsc();
				unsigned int stop_time = clock();
				std::cout << std::endl;
				std::cout << "Количество перестановок: " << Tmp.SwapCounter << std::endl;
				std::cout << "Количество тактов процессора: " << TaktLast - TaktFirst << std::endl;
				std::cout << "Количество времени: " << stop_time - start_time << std::endl;
				std::cout << "Количество сравнений: " << Tmp.ComparisonCounter << std::endl;
				system("pause");
			}
			else {
				std::cout << "Было бы славно если бы длина массива была больше 0, прежде чем его сортировать" << std::endl;
				system("pause");
			}
		}
		else {
			flag = 0;
		}
	
	}
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
			Tmp.Array = set->array;
			if (set->SortMass) {
				std::cout << "Массив уже отсортирован" << std::endl;
				system("pause");
			}
			else {
				if (set->arraySize >0) {
					Tmp.SwapCounter = 0;
					unsigned __int64 TaktFirst, TaktLast;
					if (set->arraySize < 21) { PrintArray(set); }
					else {
						PrintArrayToFile(set->array, set->arraySize, set->PartToFile + "\Input.txt");
					}//-----------------
					unsigned int start_time = clock();
					TaktFirst = __rdtsc();
					set->SortMenuFucntions[Index](&Tmp,First, Last);
					TaktLast = __rdtsc();
					unsigned int stop_time = clock();
					if (set->arraySize < 21) { PrintArray(set); }
					else {
						PrintArrayToFile(set->array, set->arraySize, set->PartToFile + "\Output.txt");
					}//-----------------
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
