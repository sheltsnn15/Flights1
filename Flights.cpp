#include "Flights.h"
#include <iostream>
#include <iomanip>//input output manipulation

using namespace std;


void Flights::getFlightDetails(Report &report, string fNum)// method to get flight details
{
    Time time;
    int theHour, theMinute, theDay, theMonth, theYear;
    char d;
    bool validTime = true;

    cout << "\n\t\t--------------------/Enter " << fNum << " Details/--------------------" << endl;
    cout << "\n\t\t\tClass: "; cin >> flightClass;

    do
    {
        cout << "\t\t\tCost: €";cin >> travelCost;
        if(!(cin.good()))
        {// validate cost to see if is number

            //explain error
            cout << "\n\t\t\t\tError: Cost invalid number, please re-enter.\n\n";
            //clear input stream
            cin.clear();
            //remove old values
            cin.ignore(132, '\n');
            cout << "\t\t\tCost: €";cin >> travelCost;
        }
    }while(!(cin.good()));

    cout << "\t\t\tDeparture Airport: "; cin >> departureAirport;
    cout << "\t\t\tArrival Airport: "; cin >> arrivalAirport;


    do
    {
        cout << "\t\t\tDeparture Date (DD/MM/YYYY): ";cin >> theDay >> d >> theMonth >> d >> theYear;
        validTime = time.validateDate(theDay, theMonth, theYear);
        if (!validTime)//if time is not valid
            cout << "\t\t\t\tPlease try again\n" << endl;
        else
        {// if time is valid, set time to time class
            departureDate.setDay(theDay);
            departureDate.setMonth(theMonth);
            departureDate.setYear(theYear);
        }

    } while(!validTime);//only proceed with program on valid time

    do
    {
        cout << "\t\t\tArrival Date (DD/MM/YYYY): "; cin >> theDay >> d >> theMonth >> d >> theYear;
        validTime = time.validateDate(theDay, theMonth, theYear);
        if (!validTime)//if time is not valid
            cout << "\t\t\t\tTime invalid, please try again\n" << endl;
        else
        {// if time is valid, set time to time class
            arrivalDate.setDay(theDay);
            arrivalDate.setMonth(theMonth);
            arrivalDate.setYear(theYear);
        }
    } while(!validTime);//only proceed with program on valid time



    do
    {//check if user entered valid departure time
        cout << "\t\t\tDeparture time (HH:MM): "; cin >> theHour >> d >> theMinute;
        validTime = time.validateTime(theHour, theMinute);
        if (!validTime)//if time is not valid
            cout << "\t\t\t\tPlease try again\n: " << endl;
        else
        {// if time is valid, set time to time class
            departureTime.setHour(theHour);
            departureTime.setMinute(theMinute);
        }
    } while(!validTime);//only proceed with program on valid time

    do
    {//check if customer has entered valid arrival time
        cout << "\t\t\tArrival time (HH:MM): ";
        cin >> theHour >> d >> theMinute;
        validTime = time.validateTime(theHour, theMinute);

        if (!validTime)//if time is not valid
            cout << "\n\t\t\t\tPlease try again\n" << endl;
        else
        {// if time is valid, set time to time class
            arrivalTime.setHour(theHour);
            arrivalTime.setMinute(theMinute);
        }
    } while(!validTime); //only proceed with program on valid time

    journeyLength = departureTime - arrivalTime;
    totalDays = arrivalDate - departureDate;

    report.setTotalCost(travelCost);
    report.setflightsNum();
}

void Flights::printFlightDetails()//display flight details
{
    cout << "\n\n\t" << setw(33) << setfill('-') << "-" << "/Printed Boarding Pass/" << setw(33) << setfill('-') << "-" << endl
         << setw(30) << setfill(' ') << "\n\tBoarding Pass"
         << setw(30) << setfill(' ') << "Class: " << flightClass
         << setw(30) << setfill(' ') << "Cost: €" << travelCost;

    cout << setw(30) << setfill(' ') << "\n\tFrom: " << departureAirport
         << setw(33) << setfill(' ') << "Date: " << departureDate.getDay() << "/" << departureDate.getMonth() << "/" << departureDate.getYear()
         << setw(27) << setfill(' ') << "Time: " << setw(2) << setfill('0') << departureTime.getHour() << ":"
                                                 << setw(2) << setfill('0') << departureTime.getMinute();

    cout << setw(30) << setfill(' ') << "\n\tTo: " << arrivalAirport
         << setw(35) << setfill(' ') << "Date: " << arrivalDate.getDay() << "/" << arrivalDate.getMonth() << "/" << arrivalDate.getYear()
         << setw(27) << setfill(' ') << "Time: " << setw(2) << setfill('0') << arrivalTime.getHour() << ":"
                                                 << setw(2) << setfill('0') << arrivalTime.getMinute();

    cout << setw(30) << setfill(' ') << "\n\tExpected Flight Time: " << setw(2) << setfill('0') << journeyLength.getHour() << "H"
                                                                     << setw(2) << setfill('0') << journeyLength.getMinute() << "M" << endl;

    cout << "\t" << setw(90) << setfill('-') << "-\n\n";
    //cout << "Journey days = " << totalDays.getDay();
}

void Flights::populateSummary(Flights ticket1, Flights ticket2, Customer cus1)//populate summary with customer and tickets info
{
    string fname, lname, addr1, addr2, addr3;//create new variables to host customer info in summary

    //get customers info and assign to variables
    fname = cus1.getFirstname();
    lname = cus1.getlastname();
    addr1 = cus1.getAddress1();
    addr2 = cus1.getAddress2();
    addr3 = cus1.getAddress3();

    //create new variables to host ticket1 info in summary
    string tkt1_DepartAirport, tkt1_ArriveAirport, tkt1_FlightClass;
    Time tkt1_DepartTime, tkt1_JourneyLength, tkt1_DepartDate;
    float tkt1_FlightCost;

    //assign ticket1 info to the created variables
    tkt1_FlightClass = flightClass = ticket1.flightClass;
    tkt1_FlightCost = travelCost = ticket1.travelCost;

    tkt1_DepartDate = departureDate = ticket1.departureDate;
    tkt1_DepartAirport = departureAirport = ticket1.departureAirport;
    tkt1_DepartTime = departureTime = ticket1.departureTime;

    tkt1_ArriveAirport = arrivalAirport = ticket1.arrivalAirport;
    tkt1_JourneyLength = journeyLength = ticket1.journeyLength;

    //create new variables to host ticket1 info in summary
    string tkt2_ArriveAirport, tkt2_FlightClass;
    Time tkt2_ArriveTime, tkt2_DepartTime, tkt2_ArriveDate;
    float tkt2_FlightCost;

    //assign ticket2 info to the created variables
    tkt2_FlightCost = travelCost = ticket2.travelCost;
    tkt2_FlightClass = flightClass = ticket2.flightClass;

    tkt2_DepartTime = departureTime = ticket2.departureTime;

    tkt2_ArriveAirport = arrivalAirport = ticket2.arrivalAirport;
    tkt2_ArriveDate = arrivalDate = ticket2.arrivalDate;
    tkt2_ArriveTime = arrivalTime = ticket2.arrivalTime;

    float totalFlightCost = tkt1_FlightCost + tkt2_FlightCost;//calculate total flight cost

    /*
    *To calculate overall journey time for summary
    *Subtract ticket 1 depart time and ticket 2 arrive time
    *Check if number of days is greater than 1
        *If so,
        *Add to journey length
        *Get number of days
        *Add 24(hours) and multiply by number of days subtracted by 1
    */
    firstDepartTime.setHour(tkt1_DepartTime.getHour());
    firstDepartTime.setMinute(tkt1_DepartTime.getMinute());
    secondArriveTime.setHour(tkt2_ArriveTime.getHour());
    secondArriveTime.setMinute(tkt2_ArriveTime.getMinute());

    totalJourneyLength = secondArriveTime - firstDepartTime;


    int numDays = ticket1.departureDate.calcDays (ticket2.arrivalDate);
    if(numDays > 1)
        totalJourneyLength.setHour (totalJourneyLength.getHour () + 24*(numDays-1));

    //display summary
    cout << "\n\n\tLDF Travel" << endl
         << "\n\tName: \t" << fname << " " << lname
         << "\n\tAddress: \t" << addr1
                              << "\n\t\t\t" << addr2
                              << "\n\t\t\t" << addr3
         << "\n\n\tREF: \t" << tkt1_DepartAirport  << "/" << tkt1_ArriveAirport << "/" << tkt2_ArriveAirport
         << "\n\n\tDear: \t" << fname
         << "\n\n\tPlease find enclosed your boarding passes for your flight from " << tkt1_ArriveAirport << " to " << tkt2_ArriveAirport << "."
         << "\n\n\tYour journey is as follows:" << endl;

    cout << "\n\n\t" << setw(33) << setfill('-') << "-" << "/Summary Of Journey/" << setw(33) << setfill('-') << "-" << endl
         << setw(30) << setfill(' ') << "\n\tName: " << fname << " " << lname
         << setw(30) << setfill(' ') << "Class: " << tkt1_FlightClass
         << setw(30) << setfill(' ') << "Total Cost: €" << totalFlightCost;

    cout << setw(30) << setfill(' ') << "\n\tFrom: " << tkt1_DepartAirport
         << setw(33) << setfill(' ') << "Date: " << tkt1_DepartDate.getDay() <<"/" << tkt1_DepartDate.getMonth() << "/" << tkt1_DepartDate.getYear()
         << setw(27) << setfill(' ') << "Time: " << setw(2) << setfill('0') << tkt1_DepartTime.getHour() << ":"
                                                 << setw(2) << setfill('0') << tkt1_DepartTime.getMinute();

    cout << setw(30) << setfill(' ') << "\n\tTo: " << tkt2_ArriveAirport
         << setw(35) << setfill(' ') << "Date: " << tkt2_ArriveDate.getDay() <<"/" << tkt2_ArriveDate.getMonth() << "/" << tkt2_ArriveDate.getYear()
         << setw(27) << setfill(' ') << "Time: " << setw(2) << setfill('0') << tkt2_ArriveTime.getHour() << ":"
                                                 << setw(2) << setfill('0') << tkt2_ArriveTime.getMinute();

    cout << setw(30) << setfill(' ') << "\n\tTotal time: " << setw(2) << setfill('0') << totalJourneyLength.getHour() << "H"
                                                           << setw(2) << setfill('0') << totalJourneyLength.getMinute() << "M" << endl;
    cout << "\t" << setw(90) << setfill('-') << "-\n\n";




}


