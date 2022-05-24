#include "functions.h"
using namespace std;

string new_name()
{
	srand(time(0));
	int choice_name = rand() % 26;
	string new_name;
	new_name.clear();
	new_name += (choice_name + 65);
	for (int i = 1; i < 7; i++)
	{
		new_name += (choice_name + 97);
		choice_name = rand() % 26;
	}
	return new_name;
}

bool new_game()
{
	Player player;
	print_struct_player(player);
	save_progress(player);
	return true;
}

bool continue_game()
{
	Player player = read_file();
	print_struct_player(player);
	return true;
}

int check_cheat(string cheat)
{
	if (cheat == "DEVMODE")
		return 0;
	return -1;
}

bool cheats()
{
	string cheat;
	cout << "\nEnter your cheat code here: ";
	cin >> cheat;
	switch (check_cheat(cheat))
	{
	case 0:
		system("cls");
		return dev_menu();
	}
	return false;
}

bool dev_menu()
{
	int choice;
	bool flag = false;
	while (!flag)
	{
		print_dev_menu();
		choice = _getch();
		choice = toupper(choice);
		switch (choice)
		{
		case '1':
			system("cls");
			cout << "Новое имя: " << new_name() << endl;
			break;
		case '2':
			system("cls");
			getPath();
			break;
		case '3':
		{
			system("cls");
			string cheat;
			cout << "Введи чит-код:\n";
			cin >> cheat;
			if (check_cheat(cheat) >= 0)
				cout << "\nЧит-код " << cheat << " соответствует номеру " << check_cheat(cheat) << endl;
			else cout << "Номер равен -1. Чит-код не верен\n";
			break;
		}
		case '4':
			system("cls");
			print_all_lines();
			break;
		case '5':
			flag = true;
			break;
		default:
			system("cls");
			print_error();
			break;
		}
	}
	cout << "\n\tPause...\n\n";
	std::system("pause>null");
	return flag;
}

bool menu()
{
	int choice;
	bool flag = false;
	while (!flag)
	{
		print_menu();
		choice = _getch();
		choice = toupper(choice);
		switch (choice)
		{
		case '1':
			system("cls");
			return continue_game();
			break;
		case '2':
			system("cls");
			return new_game();
			break;
		case '3':
			system("cls");
			if (!cheats())
				print_error();
			break;
		case '4':
			flag = true;
			break;
		default:
			system("cls");
			print_error();
			break;
		}
	}
	return flag;
}

bool game_menu()
{
	
	return false;
}

void getPath()
{
	wchar_t* buffer;
	if ((buffer = _wgetcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else
	{
		wprintf(L"%s \n", buffer);
		free(buffer);
	}
	return;
}

void print_menu()
{
	cout << "Введите необходимый пункт меню:\n\n";
	cout << "\t1. Продолжить игру;\n";
	cout << "\t2. Новая игра;\n";
	cout << "\t3. Чит-код;\n";
	cout << "\t4. Выход.\n";
}

void print_dev_menu()
{
	cout << "Введите необходимый пункт меню:\n\n";
	cout << "\t1. Вывод работы функции нового имени;\n";
	cout << "\t2. Вывод работы функции получения директории;\n";
	cout << "\t3. Вывод номера чит-кода;\n";
	cout << "\t4. Вывод инфы из файла сохранения;\n";
	cout << "\t5. Выход.\n";
}

void print_game_menu()
{
}

void print_error()
{
	cout << "\nERROR! CHECK YOUR INPUT!\n";
}

void print_struct_player(Player player)
{
	cout << " ================================================\n";
	cout << "|| Name: " << player.get_name() << "\t||\t1. Изменить имя\t||\n";
	cout << "|| HP: " << player.get_hp() << "\t\t||\t\t\t||\n";
	if (player.get_weapon().get_name() != "")
		cout << "|| Weapon: " << player.get_weapon().get_name() << "\t\t||\t\t\t||\n";
	else cout << "|| Weapon: Hands\t||\t\t\t||\n";
	cout << "|| Max size: " << player.get_inventory().get_max_inv_size() << "\t\t||\t\t\t||\n";
	cout << "|| Current size: " << player.get_inventory().get_cur_inv_size() << "\t||\t\t\t||\n";
	cout << " ================================================\n\n";
	print_all_items(player);
}

void print_all_items(Player player)
{
	cout << "Items: \n";
	int index = 1;
	for (int i = 0; i < player.get_inventory().get_max_inv_size(); i++)
	{
		if (player.get_inventory().get_items()[i].get_name() != "")
		{
			cout << index << ". " << player.get_inventory().get_items()[i].get_name() << endl;
		}
	}
	cout << endl;
}

void print_all_lines()
{
	ifstream save_file("saved_game.txt");
	string cur_line;
	while (save_file >> cur_line)
	{
		cout << decryption(cur_line) << endl;
	}
	save_file.close();
}

void save_progress(Player player)
{
	ofstream save_file("saved_game.txt");
	save_file << encryption("SKREBNEV.PriFo\n");
	save_file << encryption("Check YourSelf\n");
	save_file << encryption("Name: " + player.get_name() + "\n");
	save_file << encryption("HP: " + to_string(player.get_hp()) + "\n");
	save_file << encryption("Weapon name: " + player.get_weapon().get_name() + "\n");
	save_file << encryption("Weapon weight: " + to_string(player.get_weapon().get_weight()) + "\n");
	save_file << encryption("Max inventory size: " + to_string(player.get_inventory().get_max_inv_size()) + "\n");
	save_file << encryption("Current inventory size: " + to_string(player.get_inventory().get_cur_inv_size()) + "\n");
	save_file << encryption("Items: \n");
	for (int i = 0; i < player.get_inventory().get_max_inv_size(); i++)
	{
		if (player.get_inventory().get_items()[i].get_name() != "")
		{
			save_file << encryption(player.get_inventory().get_items()[i].get_name() + "\n");
		}
	}
	save_file.close();
}

Player read_file()
{
	Player new_player;
	ifstream save_file("saved_game.txt");
	string cur_line;
	bool items = false;
	int i = 0;
	Item item;
	while (getline(save_file, cur_line))
	{
		i++;
		cur_line = decryption(cur_line);
		switch (i)
		{
		case 1:
		case 2:
			continue;
		case 3:
			new_player.set_name(cur_line.substr(cur_line.find(":") + 2, cur_line.length()));
			break;
		case 4:
			new_player.set_hp(stoi(cur_line.substr(cur_line.find(":") + 2, cur_line.length())));
			break;
		case 5:
			item.set_name(cur_line.substr(cur_line.find(":") + 2, cur_line.length()));
			break;
		case 6:
			item.set_weight(stoi(cur_line.substr(cur_line.find(":") + 2, cur_line.length())));
			new_player.set_weapon(item);
			break;
		case 7:
			new_player.get_inventory().set_max_inv_size(stoi(cur_line.substr(cur_line.find(":") + 2, cur_line.length())));
			break;
		case 8:
			new_player.get_inventory().set_cur_inv_size(stoi(cur_line.substr(cur_line.find(":") + 2, cur_line.length())));
			break;
		case 9:
			continue;
		default:
			break;
		}
	}
	save_file.close();
	return new_player;
}

int somekey(char sym)
{
	if (sym == '\n')
		return (sym);
	sym += 200;
	sym = ((sym xor 0x0) xor 0x5f) xor 0xff;
	return (sym);
}

int returnkey(char sym)
{
	if (sym == '\n')
		return (sym);
	sym = ((sym xor 0x0) xor 0x5f) xor 0xff;
	sym -= 200;
	return (sym);
}

string encryption(string sometext)
{
	string endtext;
	for (_INDEX(sometext.size()))
	{
		endtext += char(somekey(sometext[i]));
	}
	return endtext;
}

string decryption(string sometext)
{
	string endtext;
	for (_INDEX(sometext.size()))
	{		endtext += char(returnkey(sometext[i]));
	}
	return endtext;
}