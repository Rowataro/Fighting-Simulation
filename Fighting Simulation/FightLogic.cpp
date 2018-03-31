
#include "stdafx.h"
#include "FightLogic.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "DialogueType.h"
#include "Utility.h"
#include <chrono>
#include <thread>
#include <algorithm>
#include <iostream>

void printActionScreen(Player &p)
{
	//if the player inventory is empty or the player is dead, then don't show this
	if (p.inventory.vec.empty() || p.isDead())
	{
		return;
	}
	
		//while inventory still has usable items
		while (!p.inventory.vec.empty() && std::all_of(p.inventory.vec.begin(), p.inventory.vec.end(), [](Item i1) {return (i1.isCollectable()); }))
		{
			std::cout << std::endl << "Do you want to use an item from your inventory? (Y/N)" << std::endl;
			char choice;
			std::cin >> choice;

			if (isChoice(choice, 'Y'))
			{
				p.printInvent();
				std::cout << std::endl << "Get an item by entering its first letter:";
				char symbol;
				std::cin >> symbol;
				p.inventory.findItem(symbol);

				if (p.inventory.hasFoundItem())
				{
					p.applyEffect(p.inventory.getReqItem());

					//reduce item amount by 1 (item amounts are handled appropriately)
					p.inventory.removeItem(p.inventory.getReqItem());
				}
				else
				{
					continue;
				}
			}

			else if (isChoice(choice, 'N'))
			{
				return;
			}

			else
			{
				continue;
			}
	}
	std::cout << std::endl << "You have run out of usable items." << std::endl;
}

void playerAttacks(Player &p, Monster &m)
{
	if (p.isDead())
	{
		p.printDialogue(m, DEATH);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(400));

		return;
	}

	p.printDialogue(m, HIT);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(400));

	m.reduceHealth(p.getDamage());

	if (!m.isDead())
	{
		std::cout << std::endl << "The " << m.getName() << "'s health: " <<
			m.getHealth() << std::endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}

	if (m.isDead())
	{
		m.printDialogue(DEATH);

		std::this_thread::sleep_for(std::chrono::milliseconds(400));

		p.levelUp();
		std::cout << std::endl << "You are now level " << p.getLevel() << "." << std::endl;
		std::cout << "You found " << m.getGold() << " gold." << std::endl;
		p.addGold(m.getGold());

		std::this_thread::sleep_for(std::chrono::milliseconds(400));
	}
}

void monsterAttacks(Player &p, const Monster &m)
{
	if (m.isDead())
	{
		return;
	}

	m.printDialogue(HIT);

	std::this_thread::sleep_for(std::chrono::milliseconds(400));

	p.reduceHealth(m.getDamage());

}

void fightMonster(Player &p) 
{

	Monster m = Monster::getRandomMonster(p);
	
	p.printDialogue(m, INTRO);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	m.printDialogue(INTRO);

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	while (!m.isDead() && !p.isDead())
	{
		std::cout << std::endl << "Your health: " << p.getHealth() << std::endl;
		std::cout << "Your gold: " << p.getGold() << std::endl;
		std::cout << "(R)un or (F)ight: ";

		char input;
		std::cin >> input;
		if (isChoice(input, 'R'))
		{
			if (doProbability(p.getEscChance()))
			{
				std::cout << std::endl << "You successfully flee the battle." << std::endl;
				return;
			}

			else
			{
				if (!p.isDead())
				{
					std::cout << std::endl << "You failed to flee. Time for another round." << std::endl;
				}

				monsterAttacks(p, m);
				continue;
			}
		}

		if (isChoice(input, 'F'))
		{
			playerAttacks(p, m);
			monsterAttacks(p, m);
		}

	}

}  