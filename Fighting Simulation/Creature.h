#pragma once
#include "stdafx.h"
#include <string>

class Item;

enum Attributes
{
	DAMAGE,
	HEALTH,
	MAX_HEALTH,
	MAX_ATTRIBUTES
};


class Creature
{
public:

	Creature
	(
		const std::string &name,
		char symbol,
		int health,
		int maxHealth,
		int damage,
		int gold
	);
	
	const std::string &getName() const;
	char getSymbol() const;

	int getDamage() const;
	void addDamage(int damage);

	int getHealth() const;
	void addHealth(int health);
	void restoreFullHealth();

	int getMaxHealth() const;
	int addMaxHealth(int maxHealth);

	int getGold() const;
	
	void reduceHealth(int health);
	bool isDead() const;

protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	//m_maxHealth tracks the maximum (not current) health of the creature.
	//that is m_Health's job
	int m_maxHealth;
	int m_damage;
	int m_gold;
};
