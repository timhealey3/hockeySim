#pragma once
#include <string>
#include "Stat.h"
#include <random>
#include <ctime>
#include <cstdlib>

class Player
{
public:
	enum class PositionPossible { center, left, right, defense, goalie };
	enum class Potiental { high, medium, low};
private:
	PositionPossible position;
	Potiental potiental;
	Stat stat;
	int shootingRating;
	int passingRating;
	int checkingRating;
	int goalieRating;
	int faceOffRating;
	int overallRating;
	int potientalRating;
	int age;
    int happyScore;
    int wearTearMultiplier;
    int injuryChance;
	int contractLength;
	int contractCost;
	std::string firstName;
	std::string lastName;
public:
	Player(std::string first, std::string last, PositionPossible positionNew, Potiental potientalNew);
	~Player();
	std::string getName();
	PositionPossible getPosition();
	std::string getDisplayPosition();
	void cutContract();
	void genPotientalRating();
    void setShootingRating(int newRating);
    void setPassingRating(int newRating);
    void setCheckingRating(int newRating);
    void setGoalieRating(int newRating);
    void setFaceOffRating(int newRating);
    void setOverallRating(int newRating);
    void setAge(int newAge);
	int getAge();
	int getPotientalRating();
    int getFaceOffSkill();
    int getShootingSkill();
	int getGoalieSkill();
	int getOverallRating() const;
    int getPassingRating();
    int getCheckingRating();
	void generateSkillsCreation();
};

