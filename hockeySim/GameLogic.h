#pragma once
#include "Team.h"
class GameLogic
{
public:
	enum class IceArea { homeEnd, midIce, awayEnd };
private:
	uint8_t period;
	uint8_t minute;
	uint8_t userTeamScore;
	uint8_t cpuTeamScore;
	Team* puckControl;
	IceArea icearea;
public:
	GameLogic();
	bool gamePlay(Team* UserTeam, Team* CpuTeam);
	bool faceOff(Team* UserTeam, Team* CpuTeam);
	bool shotOnNet();
	void firstPeriod(Team* UserTeam, Team* CpuTeam);
	void secondPeriod(Team* UserTeam, Team* CpuTeam);
	void thirdPeriod(Team* UserTeam, Team* CpuTeam);
	void moveArea(Team* UserTeam, Team* CpuTeam);
};

