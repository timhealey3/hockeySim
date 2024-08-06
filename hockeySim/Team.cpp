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
	// delete pointers
	for (auto& player : team) {
		delete player;
	}
	team.clear();
}

std::string Team::getName()
{
	return name;
}

void Team::generatePlayers(GenerateName genName)
{
	for (int i = 0; i < 3; i++) {
		// generate random name
		std::string firstName = genName.generateFirstName();
		std::string lastName = genName.generateLastName();
		Player* player = new Player(firstName, lastName, Player::PositionPossible::center, Player::Potiental::high);
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		std::string firstName = genName.generateFirstName();
		std::string lastName = genName.generateLastName();
		Player* player = new Player(firstName, lastName, Player::PositionPossible::left, Player::Potiental::high);
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		std::string firstName = genName.generateFirstName();
		std::string lastName = genName.generateLastName();
		Player* player = new Player(firstName, lastName, Player::PositionPossible::right, Player::Potiental::high);
		team.push_back(player);
	}
	for (int i = 0; i < 6; i++) {
		std::string firstName = genName.generateFirstName();
		std::string lastName = genName.generateLastName();
		Player* player = new Player(firstName, lastName, Player::PositionPossible::defense, Player::Potiental::high);
		team.push_back(player);
	}
	for (int i = 0; i < 3; i++) {
		std::string firstName = genName.generateFirstName();
		std::string lastName = genName.generateLastName();
		Player* player = new Player(firstName, lastName, Player::PositionPossible::goalie, Player::Potiental::high);
		team.push_back(player);
	}
}

void Team::viewPlayers()
{
	for (int i = 0; i < team.size(); i++) {
		std::cout << team[i]->getName() << " " << team[i]->getDisplayPosition() << " - " << team[i]->getOverallRating() << "\n";
	}
}

Player* Team::cutPlayer()
{
	Player* cutPlayer = team[0];
	team[0]->cutContract();
	if (!team.empty()) {
		team.erase(team.begin());
	}
	return cutPlayer;
}

bool Team::compareByRating(Player* p1, Player* p2)
{
	return p1->getOverallRating() < p2->getOverallRating();
}

void Team::autoGenLines()
{
	
	for (auto& player : team) {
		if (player->getPosition() == Player::PositionPossible::center) {
			centerVector.push_back(player);
		}
		else if (player->getPosition() == Player::PositionPossible::left) {
			leftVector.push_back(player);
		}
		else if (player->getPosition() == Player::PositionPossible::right) {
			rightVector.push_back(player);
		}
		else if (player->getPosition() == Player::PositionPossible::defense) {
			defenseVector.push_back(player);
		}
		else  {
			goalieVector.push_back(player);
		}
	}

	// sort them
	std::sort(centerVector.begin(), centerVector.end(), [](Player* p1, Player* p2) {
		return p1->getOverallRating() > p2->getOverallRating();
		});
	std::sort(leftVector.begin(), leftVector.end(), [](Player* p1, Player* p2) {
		return p1->getOverallRating() > p2->getOverallRating();
		});
	std::sort(rightVector.begin(), rightVector.end(), [](Player* p1, Player* p2) {
		return p1->getOverallRating() > p2->getOverallRating();
		});
	std::sort(defenseVector.begin(), defenseVector.end(), [](Player* p1, Player* p2) {
		return p1->getOverallRating() > p2->getOverallRating();
		});
	std::sort(goalieVector.begin(), goalieVector.end(), [](Player* p1, Player* p2) {
		return p1->getOverallRating() > p2->getOverallRating();
		});
	
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
	if (currentLine++ <= 3) { // TODO fix this
		currentLine++;
	}
	else { currentLine = 1; }
}

void Team::setName(std::string newName)
{
	name = newName;
}

Player* Team::CurrentLineCenter()
{
	return centerVector[0]; // TODO fix this
}

Player* Team::CurrentLineGoalie()
{
	return goalieVector[0];
}

void Team::trainingCamp(Trainingcamp* trainingcamp, bool verbose) {
    for (Player* player : team) {
		int oldValue = player->getOverallRating();
		int random_potiental = (std::rand() % player->getPotientalRating()) * 0.1;
		if (player->getAge() < 30) {
			switch (player->getPosition())
			{
			case Player::PositionPossible::center:
				trainingcamp->improveCenter(player, random_potiental);
				break;
			case Player::PositionPossible::left:
				trainingcamp->improveLeft(player, random_potiental);
				break;
			case Player::PositionPossible::right:
				trainingcamp->improveRight(player, random_potiental);
				break;
			case Player::PositionPossible::defense:
				trainingcamp->improveDefense(player, random_potiental);
				break;
			case Player::PositionPossible::goalie:
				trainingcamp->improveGoalie(player, random_potiental);
				break;
			default:
				break;
			}
		}
		if (verbose) {
			std::cout << player->getName() << " Age: " << player->getAge() << " Rating: " << oldValue << " -> " << player->getOverallRating() << "\n";
		}
	}
}
