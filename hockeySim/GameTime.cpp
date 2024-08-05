#include "GameTime.h"

GameTime::GameTime()
{
    date = 0;
    month = 8;
    monthName = {{0, "January"}, {1, "February"}, {2, "March"}, {3, "April"}, {4, "May"}, {5, "June"}, {6, "July"}, {7, "August"}
    , {8, "September"}, {9, "October"}, {10, "November"}, {11, "December"}};
}

uint8_t GameTime::getDate()
{
    return date;
}

uint8_t GameTime::getMonth()
{
    return month;
}

std::string GameTime::getMonthString()
{
    return monthName[month];
}

void GameTime::setDate(uint8_t newDate)
{
    // increase date by one
    if (newDate == 1) {
        if (date < 30) {
            date++;
        } else {
            date = 0;
            setMonth(1);
        }
    }
    // custom date increase TODO make it work for multiple month range
    else
    {
        if ((date+newDate) < 30) {
            date += newDate;
        } else {
            date = (date+newDate) - 30;
            setMonth(1);
        }
    }
}

void GameTime::setMonth(uint8_t newMonth)
{
    // TODO make it work for multiple month range
    if (month + newMonth < 11) {
        month++;
    }
    else {
        month = 0;
    }
}