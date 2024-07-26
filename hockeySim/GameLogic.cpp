#include "GameLogic.h"

GameLogic::GameLogic()
{
	userTeamScore = 0;
	cpuTeamScore = 0;
	minute = 0;
	period = 0;
}

GameLogic::~GameLogic()
{
}

bool GameLogic::gamePlay(Team* UserTeam, Team* CpuTeam)
{
	Stat gameStat;
	firstPeriod(UserTeam, CpuTeam);
	secondPeriod(UserTeam, CpuTeam);
	thirdPeriod(UserTeam, CpuTeam);
	if (userTeamScore == cpuTeamScore) { 
		overtimeLogic(UserTeam, CpuTeam);
	}
	int result = endGameLogic(UserTeam, CpuTeam);
	std::cout << "MSG::SCORE: Home " << static_cast<int>(userTeamScore) << " Away: " << static_cast<int>(cpuTeamScore) << std::endl;
	
	// end of game result
	switch (result) {
	case (0): {
			return true;
		}
	case (1): {
		return false;
	}
	case (2): {
		return false;
	}
	default: {
		return false;
	}
	}
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
	std::cout << "END::shot on net" << "\n\n";
	bool result = true;
	return result;
}

void GameLogic::firstPeriod(Team* UserTeam, Team* CpuTeam)
{
	period = 1;
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
		std::cout << "AREA::Puck has moved to " << getIceAreaString(icearea) << "\n";
	}
}

void GameLogic::secondPeriod(Team* UserTeam, Team* CpuTeam)
{
	std::cout << "Start Second Period" << "\n";
	period = 2;
}

void GameLogic::thirdPeriod(Team* UserTeam, Team* CpuTeam)
{
	std::cout << "Start Third Period" << "\n";
	period = 3;
}

int GameLogic::endGameLogic(Team* UserTeam, Team* CpuTeam)
{

	// win game
	if (userTeamScore > cpuTeamScore){
		return 0;
	}
	// lose game
	else if (userTeamScore < cpuTeamScore) {
		return 1;
	}
	// time game
	else {
		return 2;
	}
}

int GameLogic::overtimeLogic(Team* UserTeam, Team* CpuTeam)
{
	period = 4;
	return 0;
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

std::string GameLogic::getIceAreaString(IceArea area)
{
	switch (area) {
	case IceArea::midIce:         return "Mid Ice";
	case IceArea::homeEnd:  return "Offensive Zone";
	case IceArea::awayEnd:  return "Defensive Zone";
	default:                      return "Unknown Area";
	}
}

