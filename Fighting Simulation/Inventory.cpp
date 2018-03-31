#include "stdafx.h"
#include "Inventory.h"
#include "Item.h"
#include "Utility.h"
#include <iostream>
#include <algorithm>

//for reserving how many items you want for the vector
Inventory::Inventory(int size) : m_RequestedIndex(0)
{
	vec.reserve(size);
}

void Inventory::findItem(char symbol)
{
	//finds item in vector, according to letter entered
	auto itemIterator = std::find_if
	(
		vec.begin(), vec.end(),
		[symbol](Item element)
	{
		return (isChoice(symbol, element.getSymbol()));
	}
	);
	//if there is a symbol match, set the index from the beginning of the vector to the iterator
	if (itemIterator != vec.end())
	{
		m_RequestedIndex = std::distance(vec.begin(), itemIterator);
		foundItem = true;
	}

	else
	{
		std::cout << std::endl << "Requested item not found." << std::endl;
		foundItem = false;
	}
}

bool Inventory::hasFoundItem() { return (foundItem); }

//to be used in conjuction with foundItem
//not const because it will be used with addItem
Item& Inventory::getReqItem() 
{

	return vec[m_RequestedIndex];
	
}

//to be used in conjuction with getRequestedItem
//adds item from another inventory to the player inventory,
//so m_RequestedIndex won't work.
void Inventory::addItem(Item &item1)
{
	//checks if item is already in the inventory
	auto it = std::find_if
	(

		vec.begin(), vec.end(),
		[item1](Item item2)
	{
		return (item1 == item2);
	}
	);

	int index = std::distance(vec.begin(), it);
	
	//if item is already there, then just add 1 to the item amount
	if (it != vec.end())
	{
		vec[index].addAmount(1);
		return;
	}

	//otherwise push back this item to the end of the inventory
	vec.push_back(item1);
	vec[index].addAmount(1);
}

//to be used when player uses something from their inventory
void Inventory::removeItem(Item &item1)
{
	if (item1.getAmount() == 1)
	{
		//erase based on where the requested index is
	
		vec.erase(vec.begin() + m_RequestedIndex);

		std::cout << std::endl << "Out of these items." << std::endl;
		return;
	}

	else if (item1.getAmount() > 1)
	{
		vec[m_RequestedIndex].reduceAmount(1);
		return;
	}


}


Item& Inventory::getItem(int index)
{
	return vec[index];
}