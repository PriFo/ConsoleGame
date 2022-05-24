#pragma once
#include "Item.h"
#include <map>

/*
Class that contains information about player's inventory
*/

class Inventory
{
private:
	Item* items;
	unsigned short int max_inv_size;
	unsigned short int cur_inv_size;
public:

	std::map <std::string, unsigned short int> types_of_items = 
	{
		{"Pistol", 2},
		{"Shotgun", 6},
		{"Rifle", 6},
		{"Sniper rifle", 6},
		{"Pistol Ammo", 1},
		{"Shotgun Ammo", 1},
		{"Rifle Ammo", 1},
	};

	Inventory();
	//~Inventory();

	//Getters
	unsigned short int get_max_inv_size() { return max_inv_size; };
	unsigned short int get_cur_inv_size() { return cur_inv_size; };
	Item* get_items() { return items; };
	void pop_item(std::string name);

	//Setters
	void set_max_inv_size(int new_max_inv_size) { this->max_inv_size = new_max_inv_size; };
	void set_cur_inv_size(int new_cur_inv_size) { this->cur_inv_size = new_cur_inv_size; };
	void add_item(Item tmp_item);
};