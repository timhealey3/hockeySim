#include "main.h"

int main() {
	Team team;
	GameLogic gamelogic;
	bool gameRunning = true;
	std::vector<Player> freeAgents;
	//while (gameRunning) {
	// generate teams
	team.generatePlayers();
		// core game play loop
	// view teams
	//team.viewPlayers();
		// cut players
	Player cutPlayer = team.cutPlayer();
	freeAgents.push_back(cutPlayer);
		// sign free agents
			// draft players
		// re sign players
		// trade players
		// talk to players
	// play game
	gamelogic.gamePlay(&team, &team);
	//}
	// 32 teams eventually
	// 82 games
	// 23 man roster
	return 0;
}