#pragma once
#include <iostream>
#include <windows.h>
struct SettingsStruct;
struct SortFunction;
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
void SortComparison(SettingsStruct* set);
void EfficiencyComparison(SettingsStruct* set);

struct SettingsStruct {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string MainMenu[4] = {"����������������� �����", "���������", "���������", "�����"};
	short MainMenuSize = 4;
	void(*MainMenuFucntions[3])(SettingsStruct* set) = { ExperimentsMenuShow,AlgMenuShow,SettingsMenuShow };

	std::string ExperimentsMenu[3] = { "��������� �����������", "�������������", "�����" };
	short ExperimentsMenuSize = 3;
	void(*ExperimentsMenuFucntions[2])(SettingsStruct* set) = { SortComparison,EfficiencyComparison };


	std::string AlgMenu[3] = { "�����", "����������", "����" };
	short AlgMenuSize = 3;
	void(*AlgMenuFucntions[2])(SettingsStruct* set) = { SearchMenuShow,SortMenuShow };

	std::string SortMenu[5] = { "����������� ����������", "���������� �������","���������� ���������","���������� �����", "����" };
	short SortMenuSize = 5;
	void(*SortMenuFucntions[4])(SortFunction* Tmp, int First, int Last) =
	{ SortArrayByBubbleMetod,SortArrayByInsertMethod ,SortArrayBySelectionMethod ,SortArrayByHoarMetod };

	std::string SerchMenu[3] = { "������� �����", "��������� �����", "����" };
	short SerchMenuSize = 3;
	int(*SerchMenuFucntions[2])(int* Mass, int MassSize, int key) = { SimpleSearch,BinarySearch };

	std::string SettingMenu[4] = { "������ ������", "���������� ������� ������","�������� ����", "����"};
	short SettingMenuSize = 4;
	void(*SettingsMenuFucntions[3])(SettingsStruct* set) = { InputArrayMenuShow,PrintArray,InputPartToFile };

	std::string InputArrayMenu[4] = { "������ �������","������������� ��������","��������� �� �����","����" };
	short InputArrayMenuSize = 4;
	void(*InputArrayMenuFunctions[3])(SettingsStruct* set) = { InputArray,InputRandomArray,InputArrayFromFile};

	int* array;
	int arraySize;
	bool SortMass = 0;

	std::string PartToFile;

};
struct SortFunction {
	int TimeSec = 0;
	int TimeTakt = 0;
	int SwapCounter = 0;
	int ComparisonCounter = 0;
	std::string SortName = "";
	int SlowdownSwap = 0;
	int SlowdownComparison = 0;
	int SlowdownTime = 0;


	int* Array;
	int ArraySize;
};
