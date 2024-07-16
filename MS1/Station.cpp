/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 15 July 2024
 */

#include <iomanip>

#include "Station.h"

namespace seneca
{

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const std::string record)
    {
        Utilities tempObj;
        size_t nextPos = 0;
        bool more = true;

        m_id = ++id_generator;
        m_name = tempObj.extractToken(record, nextPos, more);
        m_serialNumber = stoi(tempObj.extractToken(record, nextPos, more));
        m_quantity = stoi(tempObj.extractToken(record, nextPos, more));
        m_description = tempObj.extractToken(record, nextPos, more);

        if (m_widthField < m_name.length())
        {
            m_widthField = m_name.length();
        }
    }

    const std::string &Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const
    {
        return m_quantity;
    }

    void Station::updateQuantity()
    {
        if (m_quantity - 1 >= 0)
            m_quantity--;
    }

    void Station::display(std::ostream &os, bool full) const
    {
        os << std::setfill('0') << std::setw(3) << std::right << m_id << " | ";
        os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name << " | ";
        os << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << " | ";

        if (full)
        {
            os << std::setfill(' ') << std::setw(4) << std::right << m_quantity << " | " << m_description;
        }

        os << std::setfill(' ') << std::setw(0) << "\n";
    }

}