#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

// global variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca
{
    class FoodOrder
    {
    private:
        // member variables
        char cust_name[10]{'\0'};
        char food_desc[25];
        double food_price;
        bool daily_special;

    public:
        // default constructor
        FoodOrder();

        // function: read
        // input: istream&
        // void
        // This function will attempt to read from the `istream` and store the information read into current object.
        void read(istream &obj);

        // function: display
        // Displays to the screen the content of an `Food Order` instance.
        // void
        void display();
    };

}

#endif