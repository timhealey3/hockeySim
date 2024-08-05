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
    generateSkillsCreation();
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
        potientalRating = 50;
        break;
    case Player::Potiental::medium:
        potientalRating = 40;
        break;
    case Player::Potiental::low:
        potientalRating = 30;
        break;
    }
}

void Player::setShootingRating(int newRating)
{
    shootingRating = newRating;
}

void Player::setPassingRating(int newRating)
{
    passingRating = newRating;
}

void Player::setCheckingRating(int newRating)
{
    checkingRating = newRating;
}

void Player::setGoalieRating(int newRating)
{
    goalieRating = newRating;
}

void Player::setFaceOffRating(int newRating)
{
    faceOffRating = newRating;
}

void Player::setOverallRating(int newRating)
{
    overallRating = newRating;
}

void Player::setAge(int newAge)
{
    age = newAge;
}


int Player::getAge()
{
    return age;
}

int Player::getPotientalRating()
{
    return potientalRating;
}

int Player::getFaceOffSkill()
{
    return faceOffRating;
}

int Player::getShootingSkill()
{
    return shootingRating;
}

int Player::getGoalieSkill()
{
    return goalieRating;
}

int Player::getOverallRating() const
{
    return overallRating;
}

int Player::getPassingRating() {
    return passingRating;
}

int Player::getCheckingRating() {
    return checkingRating;
}

void Player::generateSkillsCreation()
{
    
    int random_number = std::rand() % 51;
    if (std::rand() % 100 < 70) {
        random_number = 40 + (std::rand() % 11);
    }
    else {
        random_number = std::rand() % 51;
    }
    int random_potiental = std::rand() % potientalRating;
    int random_decrease = (std::rand() % 4) + 1;
    switch (position)
    {
    case Player::PositionPossible::center:
        faceOffRating = random_number + random_potiental;
        shootingRating = random_number + random_potiental;
        checkingRating = random_number + (random_potiental / random_decrease);
        passingRating = random_number + (random_potiental / random_decrease);
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::left:
        faceOffRating = random_number + random_potiental;
        shootingRating = random_number + random_potiental;
        checkingRating = random_number + (random_potiental / random_decrease);
        passingRating = random_number + (random_potiental / random_decrease);
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::right:
        faceOffRating = random_number + random_potiental;
        shootingRating = random_number + random_potiental;
        checkingRating = random_number + (random_potiental / random_decrease);
        passingRating = random_number + (random_potiental / random_decrease);
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::defense:
        faceOffRating = random_number + (random_potiental / random_decrease);
        shootingRating = random_number + (random_potiental / random_decrease);
        checkingRating = random_number + random_potiental;
        passingRating = random_number + random_potiental;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    case Player::PositionPossible::goalie:
        faceOffRating = 0;
        shootingRating = 0;
        checkingRating = 0;
        passingRating = 0;
        goalieRating = random_number + random_potiental;
        overallRating = goalieRating;
        break;
    default:
        faceOffRating = 0;
        shootingRating = 0;
        checkingRating = 0;
        passingRating = 0;
        goalieRating = 0;
        overallRating = (faceOffRating + shootingRating + passingRating + checkingRating) / 4;
        break;
    }
}
