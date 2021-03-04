#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

using namespace std;

class Customer
{
    public:
        string getFirstname() {return firstName;};
        string getlastname() {return lastName;};
        string getAddress1() {return address1;};
        string getAddress2() {return address2;};
        string getAddress3() {return address3;};

        void getCustomerDetails();
        void displayWelcome();
        void displayThankYou();

    private:
        //customer details variables
        string firstName, lastName, address1, address2, address3;
};

#endif // CUSTOMER_H
