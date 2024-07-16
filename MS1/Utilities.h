/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 15 July 2024
 */
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include <sstream>

namespace seneca
{

    class Utilities
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        Utilities() = default;

        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string &str, size_t &nextPos, bool &more);

        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };

    std::string trim(const std::string &strInput);
}

#endif // SENECA_UTILITIES_H