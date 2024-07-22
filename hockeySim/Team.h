#pragma once
#include <cstdint> 
#include <string>
#include "Player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
class Team
{
private:
	uint8_t maxAmountPlayers;
	uint8_t amountPlayers;
	int overallRating;
	int offenseRating;
	int defenseRating;
	int goalieRating;
	int budget;
	int budgetAllocated;
	int nextYearBudget;
	std::string name;
	std::vector<Player> team;
	std::set<Player> LineOne;
	std::set<Player> LineTwo;
	std::set<Player> LineThree;
public:
	Team();
	~Team();
	std::string getName();
	void generatePlayers();
	void viewPlayers();
	Player cutPlayer();
	bool compareByRating(Player& p1, Player& p2);
	void autoGenLines();
};

