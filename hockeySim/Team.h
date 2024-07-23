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
	int currentLine;
	std::string name;
	std::vector<Player> team;
	std::vector<Player> LineOne;
	std::vector<Player> LineTwo;
	std::vector<Player> LineThree;
	std::vector<Player> centerVector;
	std::vector<Player> leftVector;
	std::vector<Player> rightVector;
	std::vector<Player> defenseVector;
	std::vector<Player> goalieVector;
public:
	Team();
	~Team();
	std::string getName();
	void generatePlayers();
	void viewPlayers();
	Player cutPlayer();
	bool compareByRating(Player& p1, Player& p2);
	void autoGenLines();
	void setCurrentLine(int newLine);
	int getCurrentLine();
	void shiftChange();
	Player CurrentLineCenter();
};

