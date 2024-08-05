#pragma once
#include "Player.h"

class Trainingcamp
{
public:
    void improveCenter(Player* player, int randomIncrease);
    void improveLeft(Player* player, int randomIncrease);
    void improveRight(Player* player, int randomIncrease);
    void improveDefense(Player* player, int randomIncrease);
    void improveGoalie(Player* player, int randomIncrease);
};
