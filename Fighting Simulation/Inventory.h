#pragma once
#include "stdafx.h"
#include <vector>

class Item;

class Inventory 
{
public:
	Inventory(int size);

	//if vector operation is wanted, use vector vec of object inventory
	//e.g. player.inventory.vec.begin(), etc
	std::vector<Item> vec;

	// findItem should be user for when a user requests something
	//changes m_RequestedIndex accordingly
	void findItem(const char symbol);

	//to be used in conjuction with findItem
	bool hasFoundItem();

	Item& getReqItem();

	//to be used with getRequestedItem
	void addItem(Item &item);

	//to be used with getRequestedItem
	void removeItem(Item &item);

	//instead of being based on the requested index
	//this function just finds an item for any index
	Item& getItem(int index);
	
private:

	//indicates the location of an item in the inventory
	int m_RequestedIndex;

	bool foundItem;
};