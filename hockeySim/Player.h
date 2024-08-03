#pragma once
#include <string>
#include "Stat.h"
#include "Trainingcamp.h"
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
	void genCurrentRating();
    int setShootingRating(int newRating);
    int setPassingRating(int newRating);
    int setCheckingRating(int newRating);
    int setGoalieRating(int newRating);
    int setFaceOffRating(int newRating);
    int setOverallRating(int newRating);
    int setAge(int newAge);
    int getFaceOffSkill();
    int getShootingSkill();
	int getGoalieSkill();
	int getOverallRating() const;
	void generateSkillsCreation();
	int trainingCampImprovement(Trainingcamp* trainingcamp);
};

