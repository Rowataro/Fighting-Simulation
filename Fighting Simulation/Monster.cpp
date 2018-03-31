#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "CombatDialogue.h"
#include "Utility.h"
#include <cstdlib>
#include <iostream>

//refers to combat dialogue of monster between it and player
void Monster::printDialogue(CombatDialogue dialogueType) const
{
	std::cout << std::endl << monsterPlayerInteraction[MONSTER][getMonsterType()][dialogueType] << std::endl;
}

//Look-up table for predefined values
//Initalization of an array of monsters
//monsters are listed from easiest to hardest
const Monster::MonsterData Monster::monsterData[MAX_MONSTER_TYPES]
{
	{ "slime", 's', 1, 1, 1, 15 },
	{ "imp", 'i', 2, 2, 2, 15 },
	{ "leprechaun", 'l', 4, 4, 2, 45},
	{ "golem", 'm', 4, 4, 2, 20 },
	{ "ghost", 'G', 14, 14, 1, 25 },
	{ "demon", 'd', 14, 14, 3, 25 },
	{ "goblin", 'g', 10, 10, 2, 35 },
	{ "pixie", 'p', 10, 10, 2, 25 },
	{ "mutant", 'M', 16, 16, 2, 30 },
	{"vampire", 'v', 16, 16, 3, 30},
	{"werewolf", 'w', 16, 16, 4, 35},
	{"zombie", 'z', 22, 22, 1, 35},
	{"cyclops", 'c', 24, 24, 3, 40 },
	{"sasquatch", 'S', 24, 24, 3, 40},
	{"phoenix", 'P', 30, 30, 4, 100},
	{ "dragon", 'D', 30, 30, 4, 100 }
};

Monster::Monster(MonsterType type)
	:
	Creature
	(
		monsterData[type].name,
		monsterData[type].symbol,
		monsterData[type].health,
		monsterData[type].maxHealth,
		monsterData[type].damage,
		monsterData[type].gold
	),
	m_monsterType(type)
{
}

MonsterType Monster::getMonsterType() const { return m_monsterType; }

Monster Monster::getRandomMonster(const Player &p)
{
	int num; 
	//monsters scale accordingly with the player
	/*Level 1-5
		Slime
		Imp
		Leprechaun (extra gold)
		Golem
	*/
	if (p.getLevel() >= 0 && p.getLevel() <= 5)
	{
		num = getRandomNumber(SLIME, GOLEM);
	}
	/*Level 6-10
		Ghost
		Demon
		Goblin
		Pixie (extra gold)
	*/
	else if (p.getLevel() >= 6 && p.getLevel() <= 10)
	{
		num = getRandomNumber(GHOST, PIXIE);
	}

	/*Level 11-19
		Mutant
		Vampire
		Werewolf
		Zombie
		Cyclops
		Sasquatch
	*/

	else if (p.getLevel() >= 11 && p.getLevel() <= 18)
	{
		num = getRandomNumber(MUTANT, SASQUATCH);
	}

	/*Final boss
		Pheonix
		Dragon
	*/
	else if (p.getLevel() == 19)
	{
		num = getRandomNumber(PHOENIX, MAX_MONSTER_TYPES-1);
	}

	getRandomNumber(0, MAX_MONSTER_TYPES - 1);
	return Monster(static_cast<MonsterType>(num));
}