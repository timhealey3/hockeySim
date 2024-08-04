#pragma once
#include <string>
#include <vector>

class Speech {
private:
public:
    Speech();
    std::vector<std::string> getBeforeGameOptions();
    std::vector<std::string> getMidGameOptions();
    std::vector<std::string> getEndGameOptions();
    std::vector<std::string> getMediaOptions();
    std::vector<std::string> getGameShoutOptions();
};
