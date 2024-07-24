#include "GameLogic.h"

GameLogic::GameLogic()
{
}

bool GameLogic::gamePlay(Team* UserTeam, Team* CpuTeam)
{
	firstPeriod(UserTeam, CpuTeam);
	secondPeriod(UserTeam, CpuTeam);
	thirdPeriod(UserTeam, CpuTeam);
	Stat gameStat;
	// return true if user team wins
	// return false if cpu team wins
	return true;
}

bool GameLogic::faceOff(Team* UserTeam, Team* CpuTeam)
{
	bool result = UserTeam->CurrentLineCenter()->getFaceOffSkill() >= CpuTeam->CurrentLineCenter()->getFaceOffSkill();
	return result;
}

bool GameLogic::shotOnNet(Team* ShootingTeam, Team* DefendingTeam)
{
	// compare center shooting rating to goalie rating
	// the difference will be the change the puck goes in or not
	// increase shot by one, save/goal aswell
	std::cout << "shot on net" << "\n";
	int shotRating = ShootingTeam->CurrentLineCenter()->getShootingSkill();
	int defendingRating = DefendingTeam->CurrentLineGoalie()->getGoalieSkill();
	return false;
}

void GameLogic::firstPeriod(Team* UserTeam, Team* CpuTeam)
{
	UserTeam->autoGenLines();
	for (int i = 20; i > 0; i--) {
		// change shifts every 2 minutes
		if (i % 2 == 0) {
			// start of game/period
			if (i == 20) {
				std::cout << "Starting First Period" << "\n";
				icearea = IceArea::midIce;
				UserTeam->setCurrentLine(1);
				CpuTeam->setCurrentLine(1);
				bool faceOffResult = faceOff(UserTeam, CpuTeam);
				puckControl = faceOffResult ? UserTeam : CpuTeam;
			}
			else {
				UserTeam->shiftChange();
				CpuTeam->shiftChange();
			}
		}
		moveArea(UserTeam, CpuTeam);
	}
}

void GameLogic::secondPeriod(Team* UserTeam, Team* CpuTeam)
{
}

void GameLogic::thirdPeriod(Team* UserTeam, Team* CpuTeam)
{
}

void GameLogic::moveArea(Team* UserTeam, Team* CpuTeam)
{
	// if puck in opposite end and have control then take a shot
	if (puckControl) {
		// move puck
		if (icearea < IceArea::awayEnd) {
			icearea = static_cast<IceArea>(static_cast<int>(icearea) + 1);
		}
		else { shotOnNet(UserTeam, CpuTeam); }
	}
	else  {
		// move puck
		if (icearea > IceArea::homeEnd) {
			icearea = static_cast<IceArea>(static_cast<int>(icearea) - 1);
		}
		else { shotOnNet(CpuTeam, UserTeam); }
	}
}

