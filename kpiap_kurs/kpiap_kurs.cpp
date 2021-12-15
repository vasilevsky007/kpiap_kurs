#include "Menu.h"

int main()
{
	setlocale(LC_ALL, "russian");
	bool continuee=true;
	while (continuee) {
        Menu mainmenu;
        continuee = mainmenu.WantToContinue();
}
    return 0;
}