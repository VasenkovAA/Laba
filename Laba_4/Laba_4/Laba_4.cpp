
#include <iostream>
#include "MenuFunctions.h"
int main()
{
    std::cout << "Hello World!\n";
    
    SettingsStruct set;
    CreateSettingsConsoleForMenu(&set);
    MainMenuShow(&set);
    
}
