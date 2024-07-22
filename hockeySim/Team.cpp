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
	for (int i = 0; i < 10; i++) {
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

	std::sort(team.begin(), team.end(), [](Player& p1, Player& p2) {
		return p1.getOverallRating() > p2.getOverallRating();
		});
	
	for (auto& player : team) {
		std::cout << player.getName() << ": " << player.getOverallRating() << std::endl;
		// add highest rating players to line one
	}
}
