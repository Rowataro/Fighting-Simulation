#pragma once

class Item
{
public:
	enum StatusEffect
	{
		ADD_DAMAGE,
		ADD_MAX_HEALTH,
		RESTORE_HEALTH,
		RESTORE_FULL_HEALTH,
		REPEL,
		MAX_STATUS_EFFECTS
	};

	enum AllItems
	{
		WEAPON_UPGRADE,
		ARMOR_UPGRADE,
		POTION,
		ULTIMATE_ELIXIR,
		REPELLENT,
		MAX_ITEMS
	};

	Item();

	Item
	(
		char symbol,
		const char * name,
		int cost,
		//to differentiate from collectable items from upgrades
		bool collectable,
		StatusEffect effect,
		const char *description
	);

	char getSymbol() const;

	const char * getName() const;

	int getCost() const;

	bool isCollectable() const;

	StatusEffect getEffect() const;

	const char * getDescript() const;

	int getAmount() const;
	void addAmount(int amount);
	void reduceAmount(int amount);
	
	//for tracking purposes
	void resetAmount();

	friend bool operator==(const Item &i1, const Item &i2);

protected:
	char m_symbol;
	const char * m_name;
	int m_cost;
	bool m_collectable;
	StatusEffect m_effect;
	const char * m_description;
	int m_amount;
};