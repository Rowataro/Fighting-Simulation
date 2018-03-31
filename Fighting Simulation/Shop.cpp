#include "stdafx.h"
#include "Shop.h"
#include "Player.h"
#include "Utility.h"
#include <algorithm>
#include <chrono>
#include <thread>
#include <iostream>

Shop::Shop() :
	inventory(Item::MAX_ITEMS)
{
}

//prints inventory of the shop
//format = item name: description -- cost
void Shop::printInventory()
{
	std::cout << std::endl;

	for (auto it = inventory.vec.begin(); it != inventory.vec.end(); ++it)
	{
		int index = std::distance(inventory.vec.begin(), it);
		std::cout << inventory.getItem(index).getName() << " " << 
			inventory.getItem(index).getDescript() << " -- "
			<< inventory.getItem(index).getCost() << " gold" << std::endl;
	}
}

void Shop::setUpInventory()
{
	inventory.vec =
	{
		Item('W', "Weapon Upgrade", 50, false, Item::ADD_DAMAGE, "(+3 damage)"),
		Item('A', "Armor Upgrade", 40, false, Item::ADD_MAX_HEALTH, "(+3 max health)"),
		Item('P', "Potion", 50, true, Item::RESTORE_HEALTH, "(+25% health)"),
		Item('U', "Ultimate Elixir", 120, true, Item::RESTORE_FULL_HEALTH, "(max health if <= 25% health)"),
		Item('R', "Repellent", 30, true, Item::REPEL, "(+33% flee chance)")
	};
}

void Shop :: haveTransaction(Item &item, Player &p)
{
	if (p.getGold() < item.getCost())
	{
		std::cout << std::endl << "You cannot afford this upgrade." << std::endl;
		confirmedPurchase = false;
		return;
	}

	p.reduceGold(item.getCost());
	totalCost += item.getCost();

	confirmedPurchase = true;
}

bool Shop::hasConfirmedPurchase() const { return (confirmedPurchase); }

int Shop::getTotalCost() const { return totalCost; }

void enterShop(Player &p)
{
	std::cout << std::endl << "Shop Keeper available! Open every 5 level ups." << std::endl;

	if (!p.hasGold())
	{
		std::cout << std::endl << "Come back next time when you have money!" << std::endl;
		return;
	}
		std::cout << std::endl << "(L)eave whe(N)ever you want." << std::endl;

		std::cout << std::endl << "(E)nter the shop?:";
		char entry;
		std::cin >> entry;


		if (isChoice(entry, 'E'))
		{
			Shop shop;

			shop.setUpInventory();

			//current health not being taken acount for
			int prevAttribute[MAX_ATTRIBUTES]{ p.getDamage(), p.getHealth(), p.getMaxHealth() };
						
			auto cheapest_it = std::min_element
			(
				shop.inventory.vec.begin(), shop.inventory.vec.end(), 
			[](Item element1, Item element2)
			{
				return (element1.getCost() < element2.getCost());
			}
			);


			int cheapest_in = std::distance(shop.inventory.vec.begin(), cheapest_it);
			

			while (p.getGold() >= shop.inventory.vec[cheapest_in].getCost())
			{
				std::cout << std::endl << "You have " << p.getGold() << " gold." << std::endl;

				std::cout << std::endl << "Upgrades available: " << std::endl;
				
				shop.printInventory();

				std::cout << std::endl << "Choice (first letter for each):";

				char symbol;
				std::cin >> symbol;

				if (isChoice(symbol, 'L') || isChoice(symbol, 'N'))
				{
					break;
				}

				shop.inventory.findItem(symbol);

				if (shop.inventory.hasFoundItem())
				{
					shop.haveTransaction(shop.inventory.getReqItem(), p);
				
					//if the requested item from the shop inventory is just an upgrade
					// then apply effect immediately
					
					if (shop.hasConfirmedPurchase() && !shop.inventory.getReqItem().isCollectable())
					{
						p.applyEffect(shop.inventory.getReqItem());
					}

					//if the requested item from the shop inventory is just a collectable
					//then just add the item to the player's inventory
					//purchase counter excludes upgrades (as inventory prints collectables based on item amounts)
					
					else if (shop.hasConfirmedPurchase() && shop.inventory.getReqItem().isCollectable())
					{
						p.inventory.addItem(shop.inventory.getReqItem());
					}

					//Important note: amount increment to item is done after item
					//is added to player inventory. otherwise the item would get passed and 
					//and already have 1 more in amount than usual in player inventory.
					if (shop.inventory.getReqItem().isCollectable())
					{
						shop.inventory.getReqItem().addAmount(1);
					}

				}

				else if (isChoice(symbol, 'L') || isChoice(symbol, 'N'))
				{
					break;
				}

				else
				{
					continue;
				}

					std::cout << std::endl << "(M)ore purchases?:";
					char more;
					std::cin >> more;

					if (isChoice(more, 'M'))
					{
						continue;
					}

					else if (isChoice(more, 'L') || isChoice(more, 'N'))
					{
						break;
					}

					else
					{
						continue;
					}
			}
			
			if (prevAttribute[DAMAGE] < p.getDamage())
			{
				std::cout << std::endl << "You can hit harder!" << std::endl;
				std::cout << "Damage increased from " << prevAttribute[DAMAGE] <<
					" to " << p.getDamage() << std::endl;
			}

			if (prevAttribute[MAX_HEALTH] < p.getMaxHealth())
			{
				std::cout << std::endl << "You've become tougher!" << std::endl;
				std::cout << "Max health increased from " << prevAttribute[MAX_HEALTH] <<
					" to " << p.getMaxHealth() << std::endl;
			}

			std::cout << std::endl << "Collectables purchased: " << std::endl;

			//if there were no items purchased from the shop
			if (std::all_of(shop.inventory.vec.begin(), shop.inventory.vec.end(), [](Item i1) {return (i1.getAmount() == 0); }))
			{
				std::cout << std::endl << "None." << std::endl;
			}

			//otherwise print out sold items
			else
			{
				for (auto it = shop.inventory.vec.begin(); it != shop.inventory.vec.end(); ++it)
				{
					int index = std::distance(shop.inventory.vec.begin(), it);

					//if they alread had the item before entering the shop and bought more
					if (shop.inventory.getItem(index).getAmount() > 0)
					{
						//print out item name and how many were bought
						std::cout << std::endl << shop.inventory.getItem(index).getName() << ": " <<
							shop.inventory.getItem(index).getAmount() << std::endl;
						shop.inventory.getItem(index).resetAmount();
					}
				}
			}


			std::cout << std::endl << "You spent " << shop.getTotalCost() << " gold." << std::endl;
			std::cout << std::endl <<"Come again (5 more levels needed)." << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}

		else
		{	
			std::cout << std::endl << "You have exited the shop." << std::endl;
			std::cout << "5 more levels needed." << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(1200));
			
			return;
		}
}