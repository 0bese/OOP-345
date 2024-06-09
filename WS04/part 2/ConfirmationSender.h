/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 8 June 2024
 */
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H
#include <iostream>
namespace seneca
{
    class Reservation;
    class ConfirmationSender
    {
        const Reservation **m_reservations{};
        size_t m_cnt{};

    public:
        ConfirmationSender() = default;

        // copy constructor
        ConfirmationSender(const ConfirmationSender &src);

        // copy assignment
        ConfirmationSender &operator=(const ConfirmationSender &src);

        // move constructor
        ConfirmationSender(ConfirmationSender &&src);

        // move assignment
        ConfirmationSender &operator=(ConfirmationSender &&src);

        // operator overload
        ConfirmationSender &operator+=(const Reservation &res);
        ConfirmationSender &operator-=(const Reservation &res);

        // desctructor
        ~ConfirmationSender();

                friend std::ostream &operator<<(std::ostream &ostr, const ConfirmationSender &confirmSender);
    };

}

#endif