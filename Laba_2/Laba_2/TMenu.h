/* TMenu.h */
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
//#include "TMenu.cpp"
#pragma once
using namespace std;

class TMenuItem {
public:
    void enabled();
    void create(string name1, string caption1);

private:
    // ���      
    string name = "";
    // ���������
    string caption= "";
};


class TMenu {
public:
    void (*show)(TMenu &Menu);
    void create(TMenuItem* listMenuItem, int countMenuItem, string objectName);
    string GetName() { return name; };
    int GetCount() { return count; };
private:
    //������� �������
    int itemIndex=0;
    //����������� ��������� � �������
    int count=0;
    // ��� �������
    string name="";
    // ������ ����������
    TMenuItem* menuItem;
    
};

class TSettings {
public:
    HANDLE hStdOut=0;



};
void CreateSettingsConsole(TSettings set);