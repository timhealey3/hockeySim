#include "main.h"

int main() {

	GameLogic gamelogic;
	GenerateName genName;
    GameTime gameTime;
	genName.readNameFile();
	bool gameRunning = true;
	std::vector<Team*> opposingTeams;
	std::vector<Team*> scheduleYourTeam;
    std::vector<Team*> preasonScheduleYourTeam;
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
	// get input hand wave to use chicago
	Team* myTeam = opposingTeams[1];
	opposingTeams.erase(opposingTeams.begin() + 1);
	std::cout << "My Team " << myTeam->getName() << "\n";
    // game play loop
    while (gameRunning) {
        // generate schedule TODO have it schedule per day
        // TODO have it schedule all teams
        for (int i = 0; i < 82; i++) {
            scheduleYourTeam.push_back(opposingTeams[i/3]);
        }

        for (const auto& sched : scheduleYourTeam) {
            std::cout << "Schedule: " << sched->getName() << "\n";
        }
        // core game loop reset every year
        for (int x = 0; x < 365; x++) {

            if (gameTime.getMonth() == 8 && gameTime.getDate() == 0)
            {
                // start training camp for your team
                std::cout << "Off season training and training camp results are in: " << "\n";
                Trainingcamp *trainingcamp;
                myTeam->trainingCamp(trainingcamp);
                delete trainingcamp;

                // training camp improvements for other teams
                for (auto &team: opposingTeams) {
                    Trainingcamp *trainingcampOpossing;
                    myTeam->trainingCamp(trainingcampOpossing);
                    delete trainingcampOpossing;
                }

                // schedule pre-season games
                for (int i = 0; i < 4; i++) {
                    preasonScheduleYourTeam.push_back(opposingTeams[i]);
                }
            }


            // cut players
            //Player* cutPlayer = team.cutPlayer();
            //freeAgents.push_back(cutPlayer);
                // sign free agents
                    // draft players
                // re sign players
                // trade players
                // talk to players
            // play game
            gamelogic.gamePlay(myTeam, opposingTeams[0]);
            //}
            // 32 teams eventually
            // 82 games
            // 23 man roster */
            gameTime.setDate(1);
        }
    }
    delete myTeam;
    for (Team* allTeams : opposingTeams) {
        delete allTeams;
    }
	return 0;
}