
#include <iostream>
#include "MenuFunctions.h"

int main(int argc, char* argv[])
{
    SettingsStruct set;
    set.PartToFile = SplitFilename(argv[0]);
    set.PartToPythonCompiler = SplitFilename(SplitFilename(argv[0])) + "\\Scripts\\python";
    CreateSettingsConsoleForMenu(&set);
    MainMenuShow(&set);
}
 