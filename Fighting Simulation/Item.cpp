#include "stdafx.h"
#include "Item.h"

Item::Item () {}

Item::Item
	(
		char symbol,
		const char * name,
		int cost,
		bool collectable,
		StatusEffect effect,
		const char * description
	)
:
	m_symbol(symbol),
	m_name(name),
	m_cost(cost),
	m_collectable(collectable),
	m_effect(effect),
	m_description(description),
	m_amount(0)

	{

	}

char Item::getSymbol() const { return m_symbol; }

const char * Item::getName() const { return m_name; }

int Item::getCost() const { return m_cost; }

bool Item::isCollectable() const { return (m_collectable); }

Item::StatusEffect Item::getEffect() const { return m_effect; }

const char * Item::getDescript() const { return m_description; }

int  Item::getAmount() const { return m_amount; }
void Item::addAmount(int amount) { m_amount += amount; }
void Item::reduceAmount(int amount) { m_amount -= amount; }

void Item::resetAmount()
{
	int m_amount = 0;
}

bool operator==(const Item &i1, const Item &i2) 
{
	return (i1.getSymbol() == i2.getSymbol());
}
