
#include <iostream>
#include "MenuFunctions.h"

int main(int argc, char* argv[])
{
    SettingsStruct set;
    set.PartToFile = SplitFilename(argv[0]);
    CreateSettingsConsoleForMenu(&set);
    MainMenuShow(&set);
}
 