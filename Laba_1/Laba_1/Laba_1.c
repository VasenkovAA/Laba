#include <stdio.h>
#include <string.h>

#include"somecode.h"


int main()
{	
	struct TSettings config;
	struct TMenu MainMenu;
	MainMenu.Show=&Show;
	config.CreateSetting = &CreateSettings;
	config.CreateSetting(&config);

}
