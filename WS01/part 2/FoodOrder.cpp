#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"

double g_taxrate = 0.0; // Initialize global variables
double g_dailydiscount = 0.0;

namespace seneca
{
	FoodOrder &FoodOrder::setEmpty()
	{
		food_desc = nullptr;
		cust_name[0] = '\0';
		food_price = 0.0;
		daily_special = false;

		return *this;
	}

	bool FoodOrder::isEmpty() const
	{
		return !cust_name[0];
	}

	FoodOrder::operator bool() const
	{
		return cust_name[0];
	}

	FoodOrder &FoodOrder::deallocate()
	{
		delete[] food_desc;
		food_desc = nullptr;

		return *this;
	}

	FoodOrder::~FoodOrder()
	{
		delete[] food_desc;
	}

	FoodOrder::FoodOrder(const FoodOrder &foodOrder)
	{
		*this = foodOrder;
	}

	FoodOrder &FoodOrder::operator=(const FoodOrder &foodOrder)
	{
		if (this != &foodOrder)
		{
			if (foodOrder)
			{
				deallocate();

				strcpy(cust_name, foodOrder.cust_name);
				food_desc = new char[strlen(foodOrder.food_desc) + 1];
				strcpy(food_desc, foodOrder.food_desc);
				food_price = foodOrder.food_price;
				daily_special = foodOrder.daily_special;
			}
		}

		return *this;
	}

	std::istream &FoodOrder::read(std::istream &istr)
	{
		string description;
		if (istr)
		{
			istr.getline(cust_name, 10, ',');

			getline(istr, description, ',');
			deallocate();
			food_desc = new char[description.length() + 1];
			strcpy(food_desc, description.c_str());

			istr >> food_price;
			istr.ignore();

			char tempSpecial = istr.get();
			if (tempSpecial == 'Y')
			{
				daily_special = true;
			}
			else if (tempSpecial == 'N')
			{
				daily_special = false;
			}

			istr.ignore(1000, '\n');
		}

		if (!istr)
		{
			delete[] food_desc;
			setEmpty();

			istr.clear();
			istr.ignore(1000, '\n');
		}
		return istr;
	}

	std::ostream &FoodOrder::display(std::ostream &ostr) const
	{
		static int counter = 1;

		// Can also use the iomanip library to use setw, width, right, fixed, left
		ostr.setf(ios::left);
		ostr.width(2);
		ostr << counter << ". ";
		if (!isEmpty())
		{
			ostr.width(10);
			ostr << cust_name;
			ostr << "|";
			ostr.width(25);
			ostr << food_desc;
			ostr << "|";
			ostr.width(12);

			double priceAfterTax = food_price * (1 + g_taxrate);
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << priceAfterTax;
			ostr << "|";
			ostr.unsetf(ios::left);
			if (daily_special)
			{
				ostr.width(13);
				ostr.setf(ios::right);
				ostr << priceAfterTax - g_dailydiscount;
				ostr.unsetf(ios::right);
			}
			ostr.unsetf(ios::fixed);
		}
		else
		{
			ostr << "No Order";
		}

		ostr << endl;
		counter++;

		return ostr;
	}
}
