// Fi0ghting Simulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "FightLogic.h"
#include "Shop.h"
#include "Utility.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>


int main()
{
	//so introduction isn't printed out when player starts over

	bool firstTime = true; 
	
	srand(static_cast<unsigned int>(time(0)));
	//set initial seed value to system clock

	rand();
	//get rid of first result

	while (1)
	{
		std::cout << "Enter your name (no spaces): ";
		std::string playerName;
		std::cin >> playerName;
		Player p(playerName);

		if (firstTime)
		{
			std::cout << std::endl << "Welcome, " << p.getName() << '.' << std::endl;
			
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			
			std::cout << std::endl << "The goal of this game is to reach level 20. To level up, fight monsters." << std::endl;
			
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			
			std::cout << std::endl << "You have an inventory system." << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}

		while (!p.isDead() && !p.hasWon())
		{
			fightMonster(p);

			if (p.hasStatus())
			{
				p.resetStatus();
			}

			//Player must progress 5 levels before entering and only enters every 5 levels
			if (p.getLevel() > 0 && p.getLevel() % 5 == 0)
			{
				enterShop(p);
			}

			//every two levels player can access their inventory after entering the shop
			else if (p.getLevel() > 5 && p.getLevel() % 2 == 0)
			{
				printActionScreen(p);
			}

		}

		if (p.isDead())
		{
			std::cout << std::endl << "You died at level " << p.getLevel() << " and with " <<
				p.getGold() << " gold." << std::endl;
			std::cout << "You were " << 20 - p.getLevel() << " levels away from winning." << std::endl;
			std::cout << "Game over!" << std::endl;
		}

		else
		{
			std::cout << std::endl << "You won the game with " << p.getGold() << " gold!" << std::endl;
			std::cout << "Live to fight another day!" << std::endl;
		}

		std::cout << std::endl << "Play again? (Y/N):";
		char choice;
		std::cin >> choice;
		std::cout << std::endl;

		if (isChoice(choice, 'Y'))
		{
			firstTime = false;
			continue;
		}

		else if (isChoice(choice, 'N'))
		{
			break;
		}

		else
		{
			firstTime = false;
			continue;
		}
	}
	return 0;
}
