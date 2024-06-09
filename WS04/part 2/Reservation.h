/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 8 June 2024
 */
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H
#include <iostream>
#include <string>
namespace seneca
{

    class Reservation
    {
        std::string m_reservationID{};
        std::string m_reservationName{};
        std::string m_email{};
        int m_numOfPeople{};
        int m_day{};
        int m_hour{};

    public:
        Reservation(const std::string &res);
        void update(int day, int time);

        friend std::ostream &operator<<(std::ostream &ostr, const Reservation &res);

        // custom trim function
        friend std::string trim(const std::string &str);
    };
}

#endif