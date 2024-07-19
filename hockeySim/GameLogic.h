#pragma once
#include "Team.h"
class GameLogic
{
private:
	uint8_t period;
	uint8_t minute;
	uint8_t userTeamScore;
	uint8_t cpuTeamScore;
public:
	GameLogic();
	bool gamePlay(Team UserTeam, Team CpuTeam);
};

