#pragma once
#include "stdafx.h"
#include "Inventory.h"
#include "Item.h"
#include <vector>

class Player;

class Shop
{
public:
	Shop();
	
	void printInventory();

	void setUpInventory();

	void haveTransaction(Item &item, Player &p);
	
	bool hasConfirmedPurchase() const;
	
	int getTotalCost() const;
	

	Inventory inventory;
private:
	int totalCost = 0;
	bool confirmedPurchase;
};

void enterShop(Player &p);