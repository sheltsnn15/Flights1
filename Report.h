#ifndef REPORT_H
#define REPORT_H


class Report
{
    public:
        Report(){totalFlightCost = 0, flightsCount = 0;};

        void setTotalCost(double cost){totalFlightCost += cost;};
        void setflightsNum(){flightsCount++;};

        void employeeReport();
        double round(double);

    private:
        double totalFlightCost;
        unsigned short flightsCount;
};

#endif // REPORT_H
