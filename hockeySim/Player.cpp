#include "Player.h"

Player::Player(std::string first, std::string last, PositionPossible positionNew, Potiental potientalNew)
	: firstName(first), lastName(last), position(positionNew), potiental(potientalNew)
{
    // random number gen
    std::mt19937 rng(std::time(nullptr));
    potientalRating = 0;
    contractCost = 1;
    contractLength = 1;
    genPotientalRating();
    genCurrentRating();
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

void Player::genPotientalRating()
{
    switch (potiental)
    {
    case Player::Potiental::high:
        potientalRating = 100;
        break;
    case Player::Potiental::medium:
        potientalRating = 85;
        break;
    case Player::Potiental::low:
        potientalRating = 75;
        break;
    }
}

void Player::genCurrentRating()
{
    switch (position)
    {
    case Player::PositionPossible::center:
        faceOffRating = 100;
        shootingRating = 100;
        checkingRating = 50;
        passingRating = 100;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::left:
        faceOffRating = 100;
        shootingRating = 100;
        checkingRating = 50;
        passingRating = 100;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::right:
        faceOffRating = 100;
        shootingRating = 100;
        checkingRating = 50;
        passingRating = 100;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::defense:
        faceOffRating = 10;
        shootingRating = 100;
        checkingRating = 100;
        passingRating = 75;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::goalie:
        faceOffRating = 0;
        shootingRating = 100;
        checkingRating = 0;
        passingRating = 50;
        goalieRating = 100;
        overallRating = goalieRating;
        break;
    default:
        faceOffRating = 0;
        shootingRating = 100;
        checkingRating = 0;
        passingRating = 0;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    }
}

int Player::getFaceOffSkill()
{
    return faceOffRating;
}

int Player::getOverallRating() const
{
    return overallRating;
}
