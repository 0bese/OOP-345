/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 8 June 2024
 */
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H
#include <iostream>
namespace seneca
{
    class Reservation;
    class Restaurant
    {
        Reservation **m_reservations{};
        size_t m_cnt{};

    public:
        Restaurant(const Reservation *reservations[], size_t cnt); // 2-arg constructor
        Restaurant(const Restaurant &src);                         // copy constructor
        Restaurant &operator=(const Restaurant &src);              // copy assignment
        Restaurant(Restaurant &&src);                              // move constructor
        Restaurant &operator=(Restaurant &&src);                   // move assignment
        size_t size() const;
        ~Restaurant();
        friend std::ostream &operator<<(std::ostream &ostr, const Restaurant &rest);
    };
}
#endif