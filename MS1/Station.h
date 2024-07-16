/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 15 July 2024
 */

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>

#include "Utilities.h"

namespace seneca
{

    class Station
    {
        int m_id;
        std::string m_name;
        std::string m_description;
        size_t m_serialNumber;
        size_t m_quantity;

        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string oneRecord);

        const std::string &getItemName() const;

        size_t getNextSerialNumber();

        size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream &os, bool full) const;
    };

}

#endif // SENECA_STATION_H