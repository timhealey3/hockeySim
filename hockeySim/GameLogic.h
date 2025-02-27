#pragma once
#include "Team.h"
class GameLogic
{
public:
	enum class IceArea { homeEnd, midIce, awayEnd };
private:
	uint8_t period;
	uint8_t minute;
	int userTeamScore;
	int cpuTeamScore;
	bool puckControl;
	bool faceOffRequired;
	IceArea icearea;
	Stat gameStat;
public:
	GameLogic();
	~GameLogic();
	bool gamePlay(Team* UserTeam, Team* CpuTeam);
	bool faceOff(Team* UserTeam, Team* CpuTeam);
	bool shotOnNet(Team* ShootingTeam, Team* DefendingTeam);
	void firstPeriod(Team* UserTeam, Team* CpuTeam);
	void secondPeriod(Team* UserTeam, Team* CpuTeam);
	void thirdPeriod(Team* UserTeam, Team* CpuTeam);
	int endGameLogic(Team* UserTeam, Team* CpuTeam);
	int overtimeLogic(Team* UserTeam, Team* CpuTeam);
	void moveArea(Team* UserTeam, Team* CpuTeam);
	std::string getIceAreaString(IceArea area);
};

