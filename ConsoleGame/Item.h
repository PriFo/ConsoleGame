#pragma once
#include <string>

/*
Class that contains information about inventory item
*/

class Item
{
private:
	std::string name;
	unsigned short int weight;
public:
	Item();
	Item(std::string new_name, unsigned short int weight);

	//Getters
	std::string get_name() { return this->name; };
	unsigned short int get_weight() { return weight; };

	//Setters
	void set_name(std::string new_name) { this->name = new_name; };
	void set_weight(unsigned short int new_weight) { this->weight = new_weight; };

};