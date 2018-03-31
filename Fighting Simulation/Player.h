#pragma once

#include "stdafx.h"
#include "Creature.h"
#include "Monster.h"
#include "Inventory.h"
#include "DialogueType.h"


class Player : public Creature
{
public:
	Player(const std::string &name);

	void levelUp();
	int getLevel() const;

	bool hasFullHealth();

	void addGold(int gold);
	void reduceGold(int gold);
	bool hasGold() const;

	void addEscChance(int escapeChance);
	int getEscChance() const;

	bool hasWon();

	Inventory inventory;

	//player is taking to monster, so it needs to know correct monster type
	void printDialogue(const Monster &m, CombatDialogue dialogueType) const;

	void printInvent();

	void applyEffect(const Item &item);

	bool hasStatus();
	void resetStatus();
		
private:
	int m_originalEscChance;
	int m_escChance;
	int m_level;
};