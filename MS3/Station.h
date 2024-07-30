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

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include "Utilities.h"
#include <string>
#include <iostream>

namespace seneca
{
    class Station
    {
        int m_id;
        std::string m_name;
        std::string m_desc;
        int m_nextSerial;
        int m_stockQty;

        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string &record);

        const std::string &getItemName() const;

        size_t getNextSerialNumber();

        size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream &os, bool full) const;
    };
}

#endif
