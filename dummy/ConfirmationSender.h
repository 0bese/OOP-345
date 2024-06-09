// ConfirmationSender.h

#ifndef CONFIRMATION_SENDER_H
#define CONFIRMATION_SENDER_H

#include <iostream>
#include <string>
#include "Reservation.h"

namespace seneca {
    class ConfirmationSender {
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other) noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;
        ~ConfirmationSender();
        
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
        
    private:
        static const size_t MAX_SIZE = 100; // Maximum size of the array
        const Reservation* arr[MAX_SIZE]; // Array to store reservations
        size_t count; // Number of reservations
    };
}

#endif // CONFIRMATION_SENDER_H
