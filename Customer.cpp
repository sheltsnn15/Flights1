#include "Customer.h"
#include <iostream>
using namespace std;

void Customer::getCustomerDetails()//get customer details
{
    cout << "\n\n\t" << setw(33) << setfill('-') << "-" << "/Enter Customer Details/" << setw(33) << setfill('-') << "-" << endl; //prompt user to enter customer details
    cout << "\n\t\t\tCustomer first name: "; cin >> firstName;
    cout << "\t\t\tCustomer last name: "; cin >> lastName;
    cout << "\t\t\tAddress line 1: "; cin >> address1;
    cout << "\t\t\tAddress line 2: "; cin >> address2;
    cout << "\t\t\tAddress line 3: "; cin >> address3;
}

void Customer::displayWelcome()//display welcome message
{
    cout<<"\n\n\t\t________________________________________________________________________________\n"
        <<"\t\t\t\t\tWelcome To LDF Travel Agency\n"
        <<"\t\t________________________________________________________________________________\n\n";
}

void Customer::displayThankYou()//display thank you message
{
    cout << "\n\n\tThank you for booking with LDF and we look forward to doing business with you again.\n"
         << "\tqueries@ldf.ie"
         << "\twww.lef.ie"
         << "\t021-123456"
         << "\twww.facebook.com/ldf" << endl;
}
