
#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"

double g_taxrate;
double g_dailydiscount;

namespace seneca
{
    FoodOrder::FoodOrder() : food_desc(nullptr), food_price(0), daily_special(false) {}

    FoodOrder::FoodOrder(const FoodOrder& FO) {
		if(FO.cust_name != nullptr && FO.cust_name[0] != '\0' && FO.food_desc != nullptr && FO.food_desc[0] != '\0') {
			delete[] food_desc;
			food_desc = nullptr;
			food_desc = new char[strlen(FO.food_desc) + 1];
			strcpy(food_desc, FO.food_desc);
			strcpy(cust_name, FO.cust_name);
			food_price = FO.food_price;
			daily_special = FO.daily_special;
		}
		else {
			delete[] food_desc;
			food_desc = nullptr;
			cust_name[0] = '\0';
			food_price = -1;
			daily_special = false;
		}
	}

	// Copy Assignment Overload
	FoodOrder& FoodOrder::operator=(const FoodOrder& FO) {
		if (this != &FO) {
			if (FO.cust_name != nullptr && FO.cust_name[0] != '\0' && FO.food_desc != nullptr && FO.food_desc[0] != '\0') {
				delete[] food_desc;
				food_desc = nullptr;
				food_desc = new char[strlen(FO.food_desc) + 1];
				strcpy(food_desc, FO.food_desc);
				strcpy(cust_name, FO.cust_name);
				food_price = FO.food_price;
				daily_special = FO.daily_special;
			}
			else {
				delete[] food_desc;
				food_desc = nullptr;
				cust_name[0] = '\0';
				food_price = -1;
				daily_special = false;
			}
		}
		return *this;
	}

	void FoodOrder::read(std::istream& istr) {
		// Resetting "this" instance member variables to default values
		cust_name[0] = '\0';
		delete[] food_desc;
		food_desc = nullptr;
		food_price = -1;
		daily_special = false;

		// Setting up temporary variables to store data before confirmation
		char tempCustomer[10];
		std::string tempFoodDescription;
		double tempPrice = -1;
		char tempDailySpecial = '\0'; // Variable to compare whether incoming daily special status is a 'Y' or a 'N'

		istr.get(tempCustomer, 10, ',');
		istr.ignore();
		getline(istr, tempFoodDescription, ',');
		istr >> tempPrice;
		istr.ignore();
		istr >> tempDailySpecial;
        
        if (istr.good()) {
			strcpy(cust_name, tempCustomer);
			food_desc = new char[strlen(tempFoodDescription.c_str()) + 1];
			strcpy(food_desc, tempFoodDescription.c_str());
			food_price = tempPrice;
			if (tempDailySpecial == 'Y') {
				daily_special = true;
			}
			else {
				daily_special = false;
			}
		}
	}

	void FoodOrder::display()const {
		static int counter = 0;
		counter++;
		double priceWTax = (1.00 + g_taxrate) * food_price;
		double specialPrice = priceWTax - g_dailydiscount;

		if (cust_name[0] == '\0') {
			std::cout.setf(std::ios::left);
			std::cout.width(2);
			std::cout << counter << ". No Order" << std::endl;
		}
		else {
			std::cout.setf(std::ios::left);
			std::cout.width(2);
			std::cout << counter << ". ";
			std::cout.width(10);
			std::cout << cust_name << "|";
			std::cout.width(25); 
			std::cout << food_desc << "|";
			std::cout.width(12);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << priceWTax << "|";
			if (daily_special == true) {
				std::cout.unsetf(std::ios::left);
				std::cout.width(13);
				std::cout << specialPrice;
			}
			std::cout << std::endl;
		}

	}

    FoodOrder::~FoodOrder()
    {
        delete[] food_desc; // Free dynamically allocated memory
    }
}