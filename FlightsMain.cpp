#include <iostream>
#include "Flights.cpp"
#include "Time.cpp"
#include "Customer.cpp"
#include "Report.cpp"

using namespace std;



int main()
{
    bool anotherFlight = true;
    char ch;
    Flights flt1, flt2, summary1;//create an instance of flight boarding passes and order summary
    Customer cus1;
    Report report1;

    cus1.displayWelcome();
    do
    {
        flt1.getFlightDetails(report1, "Flight 1");
        flt1.printFlightDetails();

        flt2.getFlightDetails(report1, "Flight 2");
        flt2.printFlightDetails();

        cus1.getCustomerDetails();

        summary1.populateSummary(flt1, flt2, cus1);

        report1.employeeReport();

        cout << "\n\tWould you like to order another flight[Y/N]: "; cin >> ch;

        if (ch == 'N' || ch == 'n')
        {
            anotherFlight = false;
            cout << "\n\tAll done\n\n";
            cus1.displayThankYou();
            exit(0);
        }

    }while(anotherFlight);

    return 0;
}
