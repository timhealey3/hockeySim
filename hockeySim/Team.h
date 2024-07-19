#pragma once
#include <cstdint> 
#include <string>
#include "Player.h"
#include <vector>
#include <iostream>
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
public:
	Team();
	~Team();
	std::string getName();
	void generatePlayers();
	void viewPlayers();
	Player cutPlayer();
};

