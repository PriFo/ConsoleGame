#pragma once
#include <random>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Player.h"

#pragma comment(lib, "Winmm.lib")
#define _INDEX(some) int i = 0; i < some; i++

//Game logic

std::string new_name();
bool new_game();
bool continue_game();
int check_cheat(std::string cheat);
bool cheats();
bool dev_menu();
bool menu();
bool game_menu(); //todo
void getPath();

//Console print

void print_menu();
void print_dev_menu();
void print_game_menu(); //todo
void print_error();
void print_struct_player(Player player);
void print_all_items(Player player);
void print_all_lines();

//Function for files

void save_progress(Player player);
Player read_file();
int somekey(char sym);
int returnkey(char sym);
std::string encryption(std::string sometext);
std::string decryption(std::string sometext);


//Main function

int main();