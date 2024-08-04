#include "Speech.h"

Speech::Speech()
{

}

std::vector<std::string> Speech::getBeforeGameOptions()
{
    std::vector<std::string> beforeGameOptions = {"Work hard out there!", "Stay focused", "Play the body", "You are the underdogs!"
    , "This will be a easy game!"};
    return beforeGameOptions;
}

std::vector<std::string> Speech::getMidGameOptions()
{
    std::vector<std::string> beforeGameOptions = {"Keep grinding it out!", "Play as a team", "The ref is TERRIBLE",
                                                  "GET IT TOGETHER!", "Great Job out there, keep it up!"};
    return beforeGameOptions;
}

std::vector<std::string> Speech::getEndGameOptions()
{
    std::vector<std::string> beforeGameOptions = {"LETS GOOO", "You were terrible", "No celebration tonight", "you embarrassed me today"
            , "You played like superstars out there"};
    return beforeGameOptions;
}

std::vector<std::string> Speech::getMediaOptions()
{
    std::vector<std::string> beforeGameOptions = {"We tried our best", "We will keep taking it game by game"};
    return beforeGameOptions;
}

std::vector<std::string> Speech::getGameShoutOptions()
{
    std::vector<std::string> beforeGameOptions = {"REF YOU ARE TERRIBLE", "SHOOT THE PUCK!", "BACK CHECK!"};
    return beforeGameOptions;
}