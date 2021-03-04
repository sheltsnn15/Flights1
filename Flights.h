#ifndef FLIGHTS_H
#define FLIGHTS_H
#include <iostream>
#include "Time.h"
#include "Customer.h"
#include "Report.h"

using namespace std;

class Flights
{
    public:

        void printFlightDetails();
        void populateSummary(Flights, Flights, Customer);
        void getFlightDetails(Report &, string);
        void printSummaryLetter();



    private:

        Time departureTime, arrivalTime, journeyLength, firstDepartTime, secondArriveTime, departureDate, arrivalDate, totalDays, totalJourneyLength;

        string departureAirport;
        string arrivalAirport;
        double travelCost;
        string flightClass;

};

#endif // FLIGHTS_H
