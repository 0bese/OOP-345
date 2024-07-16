/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 15 July 2024
 */

#include "Utilities.h"

namespace seneca
{

    char Utilities::m_delimiter{};

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string &str, size_t &nextPos, bool &more)
    {
        std::string tempStr{};
        std::stringstream ss(str);

        ss.seekg(nextPos);
        getline(ss, tempStr, m_delimiter);

        if (tempStr.empty())
        {
            more = false;
            throw "delimiter is found at next_pos";
        }

        else if (ss.tellg() == -1)
        {
            more = false;
        }

        else
        {
            nextPos = ss.tellg();
            more = true;
        }

        if (m_widthField < tempStr.length())
            m_widthField = tempStr.length();

        tempStr = trim(tempStr);

        return tempStr;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

    std::string trim(const std::string &strInput)
    {
        unsigned int n1{}, n2{};

        n1 = strInput.find_first_not_of(" ");
        n2 = strInput.find_last_not_of(" ");

        return strInput.substr(n1, n2 - n1 + 1);
    }

}