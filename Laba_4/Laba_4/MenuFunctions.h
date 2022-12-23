#pragma once
#include <iostream>
#include <windows.h>
struct SettingsStruct;
struct SortFunction;
bool FileExists(std::string fname);
std::string SplitFilename(const std::string& str);
void CreateSettingsConsoleForMenu(SettingsStruct* set);
void MainMenuShow(SettingsStruct* set);
void ExperimentsMenuShow(SettingsStruct* set);
void AlgMenuShow(SettingsStruct* set);
void SettingsMenuShow(SettingsStruct* set);
void SearchMenuShow(SettingsStruct* set);
void SortMenuShow(SettingsStruct* set);
void PrintArray(SettingsStruct* set);
void InputArray(SettingsStruct* set);
void InputRandomArray(SettingsStruct* set);
void InputPartToFile(SettingsStruct* set);
void InputArrayFromFile(SettingsStruct* set);
void InputArrayMenuShow(SettingsStruct* set);
int SimpleSearch(int* Mass, int MassSize, int key);
int BinarySearch(int* Mass, int MassSize, int key);
void SortArrayByHoarMetod(SortFunction* Tmp, int First, int Last);
void SortArrayBySelectionMethod(SortFunction* Tmp, int First, int Last);
void SortArrayByInsertMethod(SortFunction* Tmp, int First, int Last);
void SortArrayByBubbleMetod(SortFunction* Tmp, int First, int Last);
void SortArrayByUserMetod(SettingsStruct* set);
void SortComparison(SettingsStruct* set);
void EfficiencyComparison(SettingsStruct* set);

struct SettingsStruct {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string MainMenu[4] = {"Эксперементальный режим", "Алгоритмы", "Настройки", "Выход"};
	short MainMenuSize = 4;
	void(*MainMenuFucntions[3])(SettingsStruct* set) = { ExperimentsMenuShow,AlgMenuShow,SettingsMenuShow };

	std::string ExperimentsMenu[3] = { "Сравнение сортИроваок", "Эффективность", "Выход" };
	short ExperimentsMenuSize = 3;
	void(*ExperimentsMenuFucntions[2])(SettingsStruct* set) = { SortComparison,EfficiencyComparison };


	std::string AlgMenu[3] = { "Поиск", "СортИровки", "Взад" };
	short AlgMenuSize = 3;
	void(*AlgMenuFucntions[2])(SettingsStruct* set) = { SearchMenuShow,SortMenuShow };

	std::string SortMenu[5] = { "Пузырьковая сортировка", "Сортировка выбором","Сортировка вставками","Сортировка Хоара", "Взад" };
	short SortMenuSize = 5;
	void(*SortMenuFucntions[4])(SortFunction* Tmp, int First, int Last) =
	{ SortArrayByBubbleMetod,SortArrayByInsertMethod ,SortArrayBySelectionMethod ,SortArrayByHoarMetod };

	std::string SerchMenu[3] = { "Наивный поиск", "Бинартный поиск", "Взад" };
	short SerchMenuSize = 3;
	int(*SerchMenuFucntions[2])(int* Mass, int MassSize, int key) = { SimpleSearch,BinarySearch };

	std::string SettingMenu[5] = { "Задать массив", "Посмотреть текущий массив","Изменить путь","Пользовательская сортИровка", "Взад"};
	short SettingMenuSize = 5;
	void(*SettingsMenuFucntions[4])(SettingsStruct* set) = { InputArrayMenuShow,PrintArray,InputPartToFile, SortArrayByUserMetod};

	std::string InputArrayMenu[4] = { "Задать вручную","Сгенерировать случайно","Прочитать из файла","Взад" };
	short InputArrayMenuSize = 4;
	void(*InputArrayMenuFunctions[3])(SettingsStruct* set) = { InputArray,InputRandomArray,InputArrayFromFile};

	int* array;
	int arraySize;
	bool SortMass = 0;

	std::string PartToFile;
	std::string PartToPythonCompiler; 
};
struct SortFunction {
	int TimeSec;
	int TimeTakt;
	int SwapCounter;
	int ComparisonCounter;
	std::string SortName;
	int SlowdownSwap;
	int SlowdownComparison;
	int SlowdownTime;
	
	int ArraySize;
	int* Array;
};
