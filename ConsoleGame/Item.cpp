#include "Item.h"
#include "functions.h"

Item::Item()
{
	this->name = "";
	this->weight = 0;
}

Item::Item(std::string new_name, unsigned short int new_weight)
{
	this->name = new_name;
	this->weight = new_weight;
}
