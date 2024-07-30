/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: July 22 2024
 Milestone 2
 */

#include <iostream>
#include "Utilities.h"
namespace seneca
{
	char Utilities::m_delimiter = ',';

	void Utilities::setDelimiter(char delimiter)
	{
		m_delimiter = delimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	void Utilities::setFieldWidth(size_t width)
	{
		m_fieldWidth = width;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_fieldWidth;
	}

	std::string Utilities::trim(std::string str)
	{
		size_t last = str.find_last_not_of(' ');
		size_t first = str.find_first_not_of(' ');
		if (first == std::string::npos)
		{
			return str;
		}
		return str.substr(first, (last - first + 1));
	}

	std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
	{
		std::string temp{};
		size_t len;

		if (next_pos >= str.length())
		{
			more = false;
			return "";
		}

		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw std::runtime_error("Delimiter at next_pos");
		}

		size_t delimPos = str.find(m_delimiter, next_pos);

		if (delimPos == std::string::npos)
		{
			temp = str.substr(next_pos);
			next_pos = str.length();
		}
		else
		{
			temp = str.substr(next_pos, delimPos - next_pos);
			next_pos = delimPos + 1;
		}

		temp = trim(temp);
		len = temp.length();
		if (len > m_fieldWidth)
		{
			m_fieldWidth = len;
		}

		more = next_pos < str.length();

		return temp;
	}
}