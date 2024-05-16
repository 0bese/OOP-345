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
        char cust_name[10]{'\0'};
        char *food_desc;
        double food_price;
        bool daily_special;

    public:
        FoodOrder();
        FoodOrder(const FoodOrder &FO); // Copy Constructor
        FoodOrder &operator=(const FoodOrder &FO);
        ~FoodOrder();
        void read(istream &obj);
        void display() const;
    };

}

#endif