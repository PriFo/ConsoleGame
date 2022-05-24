#include "Inventory.h"

Inventory::Inventory()
{
	this->max_inv_size = 20;
	this->cur_inv_size = 0;
	items = new Item[max_inv_size];
}

void Inventory::pop_item(std::string name)
{
	Item* new_items = new Item[this->max_inv_size];
	unsigned short int new_i = 0;
	for (int i = 0; i < this->cur_inv_size; 0)
	{
		if (&items[i])
		{
			if (!(items[i].get_name() == name))
			{
				new_items[new_i] = items[i];
				i += items[i].get_weight();
				new_i += items[i].get_weight();
			}
		}
	}
	delete items;
	items = new_items;
}

void Inventory::add_item(Item tmp_item)
{
	items[cur_inv_size] = tmp_item;
	cur_inv_size += tmp_item.get_weight();
}

/*
Inventory::~Inventory()
{
	if(*items)
		delete[] items
}
*/