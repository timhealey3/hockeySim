#include "main.h"

int main() {
	Team team;
	GameLogic gamelogic;
	GenerateName genName;
	genName.readNameFile();
	bool gameRunning = true;
	std::vector<Player*> freeAgents;
	std::vector<Team> opposingTeams;
	//while (gameRunning) {
	// generate teams
	team.setName("Detroit");
	team.generatePlayers(genName);
	team.viewPlayers();
	
	Team enemy;
	opposingTeams.push_back(enemy);
	for (auto& oppoTeam : opposingTeams) {
		std::cout << "\n";
		oppoTeam.setName("Toronto");
		oppoTeam.generatePlayers(genName);
		oppoTeam.viewPlayers();
	}
		// core game play loop
	// view teams
	//team.viewPlayers();
		// cut players
	//Player* cutPlayer = team.cutPlayer();
	//freeAgents.push_back(cutPlayer);
		// sign free agents
			// draft players
		// re sign players
		// trade players
		// talk to players
	// play game
	gamelogic.gamePlay(&team, &opposingTeams[0]);
	//}
	// 32 teams eventually
	// 82 games
	// 23 man roster
	return 0;
}