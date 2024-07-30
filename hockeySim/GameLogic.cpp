#include "GameLogic.h"

GameLogic::GameLogic()
{
	userTeamScore = 0;
	cpuTeamScore = 0;
	minute = 0;
	period = 0;
	faceOffRequired = false;
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
	std::cout << "MSG::SCORE: Home " << userTeamScore << " Away: " << cpuTeamScore << std::endl;
	
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
	std::cout << "GAMELOGIC::FACEOFF " << "Home Team Faceoff Skill: " << UserTeam->CurrentLineCenter()->getFaceOffSkill() << " Away Team Faceoff Skill: " << CpuTeam->CurrentLineCenter()->getFaceOffSkill() <<  " Result: " << result << "\n";
	return result;
}

bool GameLogic::shotOnNet(Team* ShootingTeam, Team* DefendingTeam)
{
	// compare center shooting rating to goalie rating
	// the difference will be the change the puck goes in or not
	// increase shot by one, save/goal aswell
	int shotRating = std::rand() % ShootingTeam->CurrentLineCenter()->getShootingSkill();
	int defendingRating = std::rand() % DefendingTeam->CurrentLineGoalie()->getGoalieSkill();
	bool result = (shotRating > defendingRating) ? true : false;
	std::cout << "GAMELOGIC::shot on net:: Result " << result << "\n";
	return result;
}

void GameLogic::firstPeriod(Team* UserTeam, Team* CpuTeam)
{
	std::cout << "\nFirst Period: " << UserTeam->getName() << " Vs " << CpuTeam->getName() << "\n";
	period = 1;
	UserTeam->autoGenLines();
	CpuTeam->autoGenLines();
	for (int i = 20; i > 0; i--) {
		if (faceOffRequired) {
			std::cout << "GAMELOGIC::faceoff required MSG::SCORE: Home " << userTeamScore << " Away: " << cpuTeamScore << std::endl;
		}
		// change shifts every 2 minutes
		if (i % 2 == 0) {
			// start of game/period
			if (i == 20) {
				std::cout << "GAMELOGIC::Starting First Period" << "\n";
				icearea = IceArea::midIce;
				UserTeam->setCurrentLine(1);
				CpuTeam->setCurrentLine(1);
				bool faceOffResult = faceOff(UserTeam, CpuTeam);
				puckControl = faceOffResult;
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
	std::cout << "GAMELOGIC::TEAM " << puckControl << " has possesion of the puck" << "\n";
	if (puckControl) {
		// move puck
		if (icearea < IceArea::awayEnd) {
			icearea = static_cast<IceArea>(static_cast<int>(icearea) + 1);
		}
		else { 
			bool shotResult = shotOnNet(UserTeam, CpuTeam);
			if (shotResult) {
				userTeamScore++;
				faceOffRequired = true;
			}
		}
	}
	else  {
		// move puck
		if (icearea > IceArea::homeEnd) {
			icearea = static_cast<IceArea>(static_cast<int>(icearea) - 1);
		}
		else { 
			bool shotResult = shotOnNet(CpuTeam, UserTeam);
			if (shotResult) {
				cpuTeamScore++;
				faceOffRequired = true;
			}
			
		}
	}
}

std::string GameLogic::getIceAreaString(IceArea area)
{
	switch (area) {
	case IceArea::midIce:         return "Mid Ice";
	case IceArea::homeEnd:  return "CPU Team Attacking::Puck in Home Team Zone";
	case IceArea::awayEnd:  return "Home Team Attacking::Puck in Away Team Zone";
	default:                      return "Unknown Area";
	}
}

