#include "GameLogic.h"

GameLogic::GameLogic()
{
}

bool GameLogic::gamePlay(Team* UserTeam, Team* CpuTeam)
{
	firstPeriod(UserTeam, CpuTeam);
	secondPeriod(UserTeam, CpuTeam);
	thirdPeriod(UserTeam, CpuTeam);
	// return true if user team wins
	// return false if cpu team wins
	return true;
}

bool GameLogic::faceOff(Team* UserTeam, Team* CpuTeam)
{
	// if (UserTeam.Center.getFaceoffSkill() => cpu) return true
	//bool result = UserTeam->Center->getFaceoffSkill() >= CpuTeam->Center->getFaceoffSkill();
	bool result = false;
	return result;
}

void GameLogic::firstPeriod(Team* UserTeam, Team* CpuTeam)
{
	UserTeam->autoGenLines();
	for (int i = 20; i > 0; i--) {
		// change shifts every 2 minutes
		if (i % 2 == 0) {
			if (i == 20) {
				std::cout << "Starting First Period" << "\n";
				// userTeam.startingTeam
				// cpuTeam.startingTeam
				faceOff(UserTeam, CpuTeam);
			}
			else {
				// userTeam.shiftChange
				// cpuTeam.shiftChange
			}
		}

	}
}

void GameLogic::secondPeriod(Team* UserTeam, Team* CpuTeam)
{
}

void GameLogic::thirdPeriod(Team* UserTeam, Team* CpuTeam)
{
}

