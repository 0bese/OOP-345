#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

// global variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca
{
    class FoodOrder
    {
        char cust_name[10]{};
        char *food_desc{};
        double food_price{};
        bool daily_special{};

        FoodOrder &setEmpty();
        bool isEmpty() const;
        FoodOrder &deallocate();
        operator bool() const;

    public:
        FoodOrder() = default;
        FoodOrder(const FoodOrder &foodOrder);
        ~FoodOrder();
        FoodOrder &operator=(const FoodOrder &foodOrder);
        std::istream &read(std::istream &istr = std::cin);
        std::ostream &display(std::ostream &ostr = std::cout) const;
    };
}

#endif