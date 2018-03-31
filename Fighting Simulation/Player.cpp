#include "stdafx.h"
#include "Player.h"
#include "Item.h"
#include "CombatDialogue.h"
#include <algorithm>
#include <cassert>
#include <iostream>

Player::Player(const std::string &name)
	:
	Creature(name, '@', 10, 10, 1, 0),
	m_level(0),
	m_escChance(33),
	inventory(0)
{
	m_originalEscChance = m_escChance;
}

void Player::levelUp()
{
	++m_level;
	if (m_level % 2 == 0)
	{
		++m_damage;
	}
	++m_maxHealth;
}

int Player::getLevel() const { return m_level; }

bool Player::hasFullHealth() { return (m_health == m_maxHealth); }

void Player::addGold(int gold) { m_gold += gold; }
void Player::reduceGold(int gold) { m_gold -= gold; }
bool Player::hasGold() const { return  (m_gold > 0); }

void Player::addEscChance(int escapeChance) { m_escChance += escapeChance; }
int Player::getEscChance() const { return m_escChance; }

bool Player::hasWon() { return (m_level >= 20); }

void Player::printInvent()
{
	for (auto it = inventory.vec.begin(); it != inventory.vec.end(); ++it)
	{
		int index = std::distance(inventory.vec.begin(), it);
		if (inventory.getItem(index).isCollectable())
		{
			std::cout << std::endl << inventory.getItem(index).getName() << ": " <<
				inventory.getItem(index).getAmount() << std::endl;
		}
	}
}

//refers to certain combat dialogue from player when it encounters a certain monster
void Player::printDialogue(const Monster &m, CombatDialogue dialogueType) const
{
	std::cout << std::endl << monsterPlayerInteraction[PLAYER][m.getMonsterType()][dialogueType] << std::endl;

}

void Player::applyEffect(const Item &item)
{
	 if (item.getEffect() == Item::ADD_DAMAGE)
	{
		addDamage(3);
		return;
	}

	else if (item.getEffect() == Item::ADD_MAX_HEALTH)
	{
		addMaxHealth(3);
		return;
	}

	else if (item.getEffect() == Item::RESTORE_HEALTH)
	{
		//if current health is >= 75% of max health
		//then restore the rest (25%)
		if (hasFullHealth())
		{
			std::cout << std::endl << "Health is already full." << std::endl;
			return;
		}

		else if (static_cast<float>(m_health)/m_maxHealth > 0.75)
		{
			restoreFullHealth();
			std::cout << std::endl << "Health maxed out!" << std::endl;
			return;
		}

		else if (static_cast<float>(m_health) / m_maxHealth < 0.75)
		{
			int lostHealth = m_maxHealth * 0.25;
			addHealth(lostHealth);
			std::cout << std::endl << "Health increased by " << lostHealth << " !" << std::endl;
		}
	}

	else if (item.getEffect() == Item::RESTORE_FULL_HEALTH)
	{
		if (m_health <= static_cast<int>(0.25*m_maxHealth))
		{
			std::cout << std::endl << "Health fully restored!" << std::endl;
			restoreFullHealth();
			return;
		}

		else
		{
			std::cout << std::endl << "Nothing happens..." << std::endl;
			return;
		}
	}

	else if (item.getEffect() == Item::REPEL)
	{
		//to prevent item stacking
		if (m_escChance >= m_originalEscChance + 33)
		{
			std::cout << std::endl << "This item is not stackable" << std::endl;
			return;
		}

		std::cout << std::endl << "You're more likely to escape!" << std::endl;
			addEscChance(33);
	}
}

bool Player::hasStatus()
{
	//when any status is not equal to its original
	return (m_escChance != m_originalEscChance);
}

void Player::resetStatus()
{
	m_escChance = m_originalEscChance;
}