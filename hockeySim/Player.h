#pragma once
#include <string>
#include "Stat.h"
class Player
{
public:
	enum class PositionPossible { offense, defense, goalie };
private:
	PositionPossible position;
	Stat stat;
	int shootingRating;
	int passingRating;
	int checkingRating;
	int goalieRating;
	int overallRating;
	int potientalRating;
	int age;
	int contractLength;
	int contractCost;
	std::string firstName;
	std::string lastName;
public:
	Player(std::string first, std::string last, PositionPossible positionNew);
	std::string getName();
	PositionPossible getPosition();
	std::string getDisplayPosition();
	void cutContract();
};

