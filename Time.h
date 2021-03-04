#ifndef TIME_H
#define TIME_H
#include "Flights.h"

class Time
{//Time class
    public:
        Time operator-(Time);
        int calcDays(Time);
        bool validateTime(int, int);
        bool validateDate(int, int, int);

        void setHour(int hh) {hour = hh;};
        int getHour() {return hour;};

        void setMinute(int mm) {minute = mm;};
        int getMinute() {return minute;};

        void setDay(int dd) {day = dd;};
        int getDay() {return day;};

        void setMonth(int mon) {month = mon;};
        int getMonth() {return month;};

        void setYear(int yy) {year = yy;};
        int getYear() {return year;};


    private:
        int hour, minute, day, month, year;

};

#endif // TIME_H
