/*/////////////////////////////////////////////////////////////////////////
                        Milestone-3
Full Name  : Kojo Anyane Obese
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NRA
Date       : 29/07/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <string>
#include <iostream>
#include "Station.h"
#include "Utilities.h"

namespace seneca
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
        std::string m_name;
        std::string m_product;
        size_t m_cntItem;
        Item **m_lstItem;

        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const std::string &str);

        CustomerOrder(const CustomerOrder &) { throw "Copying Disabled"; };
        CustomerOrder &operator=(const CustomerOrder &) = delete;
        CustomerOrder(CustomerOrder &&src) noexcept;
        CustomerOrder &operator=(CustomerOrder &&src) noexcept;
        virtual ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };
}
#endif