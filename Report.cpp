#include <iostream>
#include "Report.h"
using namespace std;


void Report::employeeReport()// display employee report
{
    char choice;
    bool displayReport = true;


    do//loop to check if employee wants to view their report
    {
        cout << "\n\n\t\tWould you like to display employee report [Y/N]: "; cin >> choice;

        if (choice == 'Y' || choice == 'y')//display report if the employee enters 'y'
        {
            cout << "\n\n\t" << setw(33) << setfill('-') << "-" << "/Employee Report/" << setw(33) << setfill('-') << "-" << endl
                 << "\tNumber of flights sold: \t" << flightsCount << endl
                 << "\tTotal Cost of flights: \t€" << totalFlightCost << endl
                 << "\tCommission earned: \t€" << round(totalFlightCost*0.1) << endl;
        }
        else if (choice == 'N' || choice == 'n')//don't display report if the employee enters 'n'
        {
            cout << "\n\tAll Good, Thanks" << endl;
        }
        else//if employee enters wrong choice, loop until the enter available choice
        {
            cout << "\n\tOops, wrong selection, try again" << endl;
            displayReport = false;
        }
    }while(!displayReport);
}


double Report::round(double var)//round off ans
{
   /*
   *float value * 100 = ans
   *3766.66 + .5 = ans for rounding off value
   *then type cast to int
   *then divided by 100
   */

   double value = (int)(var * 100 + .5);

   return (double)value / 100;

}


