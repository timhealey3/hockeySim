#include "main.h"

int main() {

	GameLogic gamelogic;
	GenerateName genName;
	genName.readNameFile();
	bool gameRunning = true;
	std::vector<Team*> opposingTeams;
	std::vector<Team*> scheduleYourTeam;
	std::vector<Player*> freeAgents;
	std::vector<std::string> cities = {"Detroit", "Chicago", "New York", "Long Island", "Toronto" , "Montreal" , "Texas" , "Seattle" ,"Los Angeles" , "Boston" , "Buffalo" , 
		"Florida" , "Ottawa" , "Arizona" , "Colorado", "Minnesota" , "Nashville" , "St Louis" , "Winnipeg" , "Carolina" , "Columbus" , "New Jersey" , "Tampa Bay" , "Washington" , "Philly" , 
		"Calgary" , "Anaheim" , "Edmonton" , "Vegas" , "San Jose" , "Vancouver" , "Puttsburgh", "Utah" };

	// generate all teams

	for (size_t i = 0; i < cities.size(); i++) {
		Team* tmpTeam = new Team();
		tmpTeam->setName(cities[i]);
		tmpTeam->generatePlayers(genName);
		opposingTeams.push_back(tmpTeam);
	}
	// select Team from opposing teams
	for (auto& team : opposingTeams) {
		std::cout << "Team: " << team->getName() << "\n";
	}
	// get input handwave to use chicago
	Team* myTeam = opposingTeams[1];
	opposingTeams.erase(opposingTeams.begin() + 1);
	std::cout << "My Team " << myTeam->getName() << "\n";

	// generate schedule
	for (int i = 0; i < 82; i++) {
		scheduleYourTeam.push_back(opposingTeams[i/3]);
	}

	for (const auto& sched : scheduleYourTeam) {
		std::cout << "Schedule: " << sched->getName() << "\n";
	}
	
	// training camp
	// 4 preseason games
	// training camp improvements
	
	//while (gameRunning) {
	// generate teams
	/*
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
	// 23 man roster */
	return 0;
}