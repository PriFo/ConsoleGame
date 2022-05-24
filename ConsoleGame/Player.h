#pragma once
#include "Inventory.h"
#include <string>

/*
Class that contains information about player
*/

class Player
{
private:
	unsigned short int hp;
	std::string name;
	Item weapon;
	Inventory inventory;
public:
	Player();
	Player(std::string new_name);
	
	//Getters
	unsigned short int get_hp() { return this->hp; };
	std::string get_name() { return this->name; };
	Item get_weapon() { return this->weapon; };
	Inventory get_inventory() { return this->inventory; };

	//Setters
	void set_hp(int new_hp) { this->hp = new_hp; };
	void set_name(std::string new_name) { this->name = new_name; };
	void set_weapon(Item new_weapon) { this->weapon = new_weapon; };
	void set_inventory(Inventory new_inventory) { this->inventory = new_inventory; };

protected:
};