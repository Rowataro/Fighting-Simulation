#include "stdafx.h"
#include "Creature.h"
#include "Item.h"
#include <iostream>

Creature::Creature
(
	const std::string &name,
	char symbol,
	int health,
	int maxHealth,
	int damage,
	int gold
)
	:
	m_name(name),
	m_symbol(symbol),
	m_health(health),
	m_maxHealth(maxHealth),
	m_damage(damage),
	m_gold(gold)
{
}

const std::string & Creature::getName() const { return m_name; }

char Creature::getSymbol() const { return m_symbol; }

int Creature::getDamage() const { return m_damage; }
void Creature::addDamage(int damage) { m_damage += damage; }

int Creature::getHealth() const { return m_health; }
void Creature::addHealth(int health) { m_health += health; }
void Creature::restoreFullHealth() { m_health = m_maxHealth; }

int Creature::getMaxHealth() const { return m_maxHealth; }
int Creature::addMaxHealth(int maxHealth) { return m_maxHealth += maxHealth; }

int Creature::getGold() const { return m_gold; }

void Creature::reduceHealth(int health) { m_health -= health; }
bool Creature::isDead() const { return (m_health <= 0); }