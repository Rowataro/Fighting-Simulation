#pragma once
#include "Creature.h"
#include "EntityType.h"
#include "DialogueType.h"

class Player;

class Monster : public Creature
{
public:

	struct MonsterData
	{
		//no string needed because it's constant data
		const char * name;
		const char symbol;
		int health;
		int maxHealth;
		int damage;
		int gold;
	};

	static const MonsterData monsterData[MAX_MONSTER_TYPES];

	Monster(MonsterType type);
	
	MonsterType getMonsterType() const;

	//random monster generated based on player level
	static Monster getRandomMonster(const Player &p);

	//takes parameter of INTRO, HIT, or DEFEAT for creature
	void printDialogue(CombatDialogue dialogueType) const;

private:
	MonsterType m_monsterType;
};