#include "Player.h"
#include "functions.h"

Player::Player()
{
	this->name = new_name();
	this->hp = 100;
	this->weapon = Item();
	this->inventory = Inventory();
}

Player::Player(std::string new_name)
{
	this->name = new_name;
	this->hp = 100;
	this->weapon = Item();
	this->inventory = Inventory();
}
