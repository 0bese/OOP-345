/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: July 22 2024
 Milestone 2
 */

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <string>
#include "Station.h"

namespace seneca
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{0};
		bool m_isFilled{false};
		Item(const std::string &src) : m_itemName(src){};
	};

	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item **m_lstItem{};
		static size_t m_widthField;

	public:
		// Default constructor
		CustomerOrder();

		// Copy constructor - Not allowed
		CustomerOrder(const CustomerOrder &other);

		// Constructor with a string argument to initialize order
		CustomerOrder(const std::string &theStr);

		// Move assignment operator for transferring ownership of resources
		CustomerOrder &operator=(CustomerOrder &&other) noexcept;

		// Assignment operator - Not allowed
		CustomerOrder &operator=(const CustomerOrder &other);

		// Move constructor for transferring ownership of resources
		CustomerOrder(CustomerOrder &&other) noexcept;

		// Checks if the entire order is filled
		bool isOrderFilled() const;

		// Checks if a specific item in the order is filled
		bool isItemFilled(const std::string &itemName) const;

		// Fills items from the station and outputs status to the provided stream
		void fillItem(Station &station, std::ostream &os);

		// Displays the order details to the provided stream
		void display(std::ostream &os) const;

		// Destructor for cleaning up resources
		~CustomerOrder();
	};

}

#endif // SENECA_CUSTOMERORDER_H