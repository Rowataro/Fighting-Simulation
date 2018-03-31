#pragma once

class Player;

class Monster;

void printActionScreen(Player &p);

void playerAttacks(Player &p, Monster &m);

void monsterAttacks(Player &p, const Monster &m);

void fightMonster(Player &p);
