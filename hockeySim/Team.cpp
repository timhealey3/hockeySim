#include "Team.h"

Team::Team()
{
	maxAmountPlayers = 23;
	amountPlayers = maxAmountPlayers;
	overallRating = 1;
	offenseRating = 1;
	defenseRating = 1;
	goalieRating = 1;
	name = "some name";
}

Team::~Team()
{
// nothing for now
}

std::string Team::getName()
{
	return name;
}

void Team::generatePlayers()
{
	for (int i = 0; i < 3; i++) {
		Player player("Pavel", "Datsyuk", Player::PositionPossible::center, Player::Potiental::high);
		// name, position
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		Player player("Henrik", "Zetter", Player::PositionPossible::left, Player::Potiental::high);
		// name, position
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		Player player("Johan", "Franzen", Player::PositionPossible::right, Player::Potiental::high);
		// name, position
		team.push_back(player);
	}
	for (int i = 0; i < 6; i++) {
		Player player("Nicolas", "Lidstrom", Player::PositionPossible::defense, Player::Potiental::high);
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		Player player("Jimmy", "Howard", Player::PositionPossible::goalie, Player::Potiental::high);
		team.push_back(player);
	}
}

void Team::viewPlayers()
{
	for (int i = 0; i < team.size(); i++) {
		std::cout << team[i].getName() << " " << team[i].getDisplayPosition() << "\n";
	}
}

Player Team::cutPlayer()
{
	Player cutPlayer = team[0];
	team[0].cutContract();
	if (!team.empty()) {
		team.erase(team.begin());
	}
	return cutPlayer;
}

bool Team::compareByRating(Player& p1, Player& p2)
{
	return p1.getOverallRating() < p2.getOverallRating();
}

void Team::autoGenLines()
{
	
	for (auto& player : team) {
		std::cout << player.getName() << ": " << player.getOverallRating() << std::endl;
		if (player.getPosition() == Player::PositionPossible::center) {
			centerVector.push_back(player);
		}
		else if (player.getPosition() == Player::PositionPossible::left) {
			leftVector.push_back(player);
		}
		else if (player.getPosition() == Player::PositionPossible::right) {
			rightVector.push_back(player);
		}
		else if (player.getPosition() == Player::PositionPossible::defense) {
			defenseVector.push_back(player);
		}
		else  {
			goalieVector.push_back(player);
		}
	}

	// sort them
	std::sort(centerVector.begin(), centerVector.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});
	std::sort(leftVector.begin(), leftVector.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});
	std::sort(rightVector.begin(), rightVector.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});
	std::sort(defenseVector.begin(), defenseVector.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});
	std::sort(goalieVector.begin(), goalieVector.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});

	// put sorted vectors in lines
	
}

void Team::setCurrentLine(int newLine)
{
	currentLine = newLine;
}

int Team::getCurrentLine()
{
	return currentLine;
}

void Team::shiftChange()
{
	if (currentLine++ <= 3) {
		currentLine++;
	}
	else { currentLine = 1; }
}

Player Team::CurrentLineCenter()
{
	return centerVector[currentLine];
}
