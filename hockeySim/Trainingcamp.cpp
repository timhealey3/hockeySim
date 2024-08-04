#include "Trainingcamp.h"

void Trainingcamp::improveCenter(Player* player, int randomPotiental)
{
    player->setFaceOffRating(player->getFaceOffSkill() + randomPotiental);
    player->setShootingRating(player->getShootingSkill() + randomPotiental);
    player->setShootingRating(player->getPassingRating() + randomPotiental);
    player->setOverallRating((player->getFaceOffSkill() + player->getShootingSkill() + player->getPassingRating() + player->getCheckingRating()) / 4);
}

void Trainingcamp::improveLeft(Player* player, int randomPotiental)
{
    player->setFaceOffRating(player->getFaceOffSkill() + randomPotiental);
    player->setShootingRating(player->getShootingSkill() + randomPotiental);
    player->setShootingRating(player->getPassingRating() + randomPotiental);
    player->setOverallRating((player->getFaceOffSkill() + player->getShootingSkill() + player->getPassingRating() + player->getCheckingRating()) / 4);
}

void Trainingcamp::improveRight(Player* player, int randomPotiental)
{
    player->setFaceOffRating(player->getFaceOffSkill() + randomPotiental);
    player->setShootingRating(player->getShootingSkill() + randomPotiental);
    player->setShootingRating(player->getPassingRating() + randomPotiental);
    player->setOverallRating((player->getFaceOffSkill() + player->getShootingSkill() + player->getPassingRating() + player->getCheckingRating()) / 4);
}

void Trainingcamp::improveDefense(Player* player, int randomPotiental)
{
    player->setCheckingRating(player->getFaceOffSkill() + randomPotiental);
    player->setShootingRating(player->getShootingSkill() + randomPotiental);
    player->setShootingRating(player->getPassingRating() + randomPotiental);
    player->setOverallRating((player->getCheckingRating() + player->getShootingSkill() + player->getPassingRating() + player->getCheckingRating()) / 4);
}

void Trainingcamp::improveGoalie(Player* player, int randomPotiental)
{
    player->setGoalieRating(player->getGoalieSkill() + randomPotiental);
    player->setOverallRating(player->getGoalieSkill());
}