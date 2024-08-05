#pragma once
#include <cstdlib>
#include <string>
#include <unordered_map>

class GameTime {
private:
    uint8_t month;
    uint8_t date;
    std::unordered_map<uint8_t, std::string> monthName;
public:
    GameTime();
    uint8_t getMonth();
    uint8_t getDate();
    std::string getMonthString();
    void setMonth(uint8_t newMonth);
    void setDate(uint8_t newDate);
};