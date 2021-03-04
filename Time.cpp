#include "Time.h"
#include <iostream>
using namespace std;

bool Time::validateTime(int hh, int mm)//Check if time is valid
{
    if(!(cin.good()))//check if input is int
    {
        //explain error
        cout << "\n\t\t\tError: That is not number\n";
        //clear input stream
        cin.clear();
        //remove old values
        cin.ignore(INT_MAX, '\n');
        return false;
    }

    if (hh < 0 || hh > 23 || mm < 0 || mm > 59)
    {
        //explain error
        cout << "\n\t\t\tError: Time out of bounds\n";
        return false;
    }
    return true;

}

bool Time::validateDate(int day, int month, int year)
{
    if(!(cin.good()))//check if input is int
    {
        //explain error
        cout << "\n\t\t\t\tError: That is not number, please re-enter\n";
        //clear input stream
        cin.clear();
        //remove old values
        cin.ignore(INT_MAX, '\n');
        return false;
    }

    if(day < 1 || day > 31) {//check if days entered is not out of bounds
        cout << "\n\t\t\t\tError: The day entered is out of bounds\n";
        return false;
    }
    else if(month < 1 || month > 12) {//check if month entered is not out of bounds
        cout << "\n\t\t\t\tError: The month entered is out of bounds\n";
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {//check if day entered is relevant to its month
        cout << "\n\t\t\t\tError: This month entered does not have that many days\n"
        << "\t\t\t\tREMEMBER: April, June, September, November has 30 days\n";
        return false;
    }
    else if ((month == 2) && (year % 4 == 0) && day >= 29) {//check if year is leap year
        cout << "\n\t\t\t\tError: This month entered does not have that many days\n"
        << "\t\t\t\tIt's a leap year\n"
        << "\t\t\t\tREMEMBER: February does not have more than 29 days\n";
        return false;

    }
    else if ((month == 2) && (year % 4 != 0) && day >= 28) {//check if year is not a leap year
        cout << "\n\t\t\t\tError: This month entered does not that have many days\n"
        << "\t\t\t\tREMEMBER: February only has 29 days on a leap year\n";
        return false;
    }
    return true;

}

Time Time::operator-(Time operand2)//method to calculate the journey
{
    Time result;//create a variable of calculated time
    int departTime = this->hour*60 + this->minute,
        arriveTime = operand2.hour*60 + operand2.minute,
        journeyLength = departTime-arriveTime;
    result.hour = journeyLength/60;
    result.minute = journeyLength%60;
    if (result.hour < 0 || result.minute < 0)//if answer is negative, multiply by - one
    {
        result.hour *= (-1);
        result.minute *= (-1);
    }
    return result;
}

int Time::calcDays(Time operand2)//method to calculate days
{
    Time totalDays;

    int departDay = this->day;
    int departMonth = this->month;

    int arriveDay = operand2.day;
    int arriveMonth = operand2.month;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//store lengths of months respectively

    if(departMonth == arriveMonth)//if first month equals second month
    {
        totalDays.day = arriveDay - departDay +1;
        return totalDays.day;
    }

    else//else if first month doesn't equals second month
    {
        for(int i = departMonth; i < arriveMonth; i++)//loop through array and find month entered
            totalDays.day += daysInMonth[i];//add the month index value to total days

        totalDays.day += arriveDay - departDay +1;
        return totalDays.day;
    }

}

