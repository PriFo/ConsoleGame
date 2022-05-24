#include "functions.h"

using namespace std;

int main()
{
	setlocale(0, "");
	int symbol;
	bool flag = false;
	cout << "Are you developer? y - yes or n - no\n";
	symbol = _getch();
	symbol = toupper(symbol);
	while (!flag)
	{
		switch (symbol)
		{
		case 'Y':
		case 164:
			system("cls");
			if (dev_menu())
				flag = true;
			break;
		case 'N':
		case 173:
			system("cls");
			if (menu())
				flag = true;
			break;
		default:
			system("cls");
			print_error();
			cout << "\nAre you developer? y - yes or n - no\n";
			symbol = _getch();
			symbol = toupper(symbol);
			break;
		}
	}
	cout << "\n\tPause...\n\n";
	cout << "Окончание работы программы...\nНажмите любую клавишу...\n";
	system("pause>null");
	return 0;
}