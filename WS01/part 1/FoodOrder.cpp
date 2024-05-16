
#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"

double g_taxrate;
double g_dailydiscount;

namespace seneca
{
    FoodOrder::FoodOrder() = default;

    void FoodOrder::read(istream &obj)
    {
        // static variable named 'counter' which allows to read next order once the current order has been read.
        static size_t counter = 0;

        // getline() stores at-max 9 charaters in cust_name and exits when ',' is interpreted.
        obj.getline(cust_name, 10, ',');
        obj.getline(food_desc, 25, ',');
        obj >> food_price;
        obj.ignore(1, ',');

        char d_special[2];

        // get() stores only one character, the next one is null terminator.
        obj.get(d_special, 2);

        if (d_special[0] == 'N')
        {
            daily_special = false;
        }
        else
        {
            daily_special = true;
        }
        ++counter;
    }

    void FoodOrder::display()
    {
        // static will prevent 'counter' from getting re-initialised with 1.
        static size_t counter{1};
        double taxed_price = (food_price + (food_price * g_taxrate));
        double special_price = taxed_price - g_dailydiscount;

        // if cust_name is empty then it's length is 0.
        if (strlen(cust_name) == 0)
        {
            cout << left;
            cout << setw(2) << counter << ". "
                 << "No Order" << endl;
        }
        else
        { // left-align, right-align, setw() together form the specified format.
            cout << left;
            cout << setw(2) << counter << setw(2) << "." << setw(10) << cust_name << "|" << setw(25) << food_desc << "|";
            cout << setprecision(2);
            cout << fixed;
            cout << setw(12) << taxed_price << "|";

            if (daily_special)
            {
                cout << right;
                cout << setw(13) << special_price << endl;
            }
            else
            {
                cout << endl;
            }
        }

        ++counter;
    }

}