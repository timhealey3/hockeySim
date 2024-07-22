#include "Player.h"

Player::Player(std::string first, std::string last, PositionPossible positionNew)
	: firstName(first), lastName(last), position(positionNew)
{
    contractCost = 1;
    contractLength = 1;
}

Player::~Player()
{
}


std::string Player::getName()
{
	std::string fullName = firstName + " " + lastName;
	return fullName;
}

Player::PositionPossible Player::getPosition()
{
	return position;
}

std::string Player::getDisplayPosition()
{
    switch (position)
    {
    case Player::PositionPossible::center:
        return "Offense - Center";
    case Player::PositionPossible::left:
        return "Offense - Left";
    case Player::PositionPossible::right:
        return "Offense - Right";
    case Player::PositionPossible::defense:
        return "Defense";
    case Player::PositionPossible::goalie:
        return "Goalie";
    default:
        return "Unknown";
    }
}

void Player::cutContract()
{
    contractCost = 0;
    contractLength = 0;
}

int Player::getFaceOffSkill()
{
    return faceOffRating;
}

int Player::getOverallRating()
{
    return overallRating;
}
