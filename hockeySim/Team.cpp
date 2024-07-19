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
	for (int i = 0; i < 10; i++) {
		Player player("Jimmy", "Howard", Player::PositionPossible::offense);
		// name, position
		team.push_back(player);
	}
	for (int i = 0; i < 10; i++) {
		Player player("Jimmy", "Howard", Player::PositionPossible::defense);
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		Player player("Jimmy", "Howard", Player::PositionPossible::goalie);
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

