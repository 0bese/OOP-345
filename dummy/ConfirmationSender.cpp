// ConfirmationSender.cpp

#include "ConfirmationSender.h"

namespace seneca {
    // Default constructor
    ConfirmationSender::ConfirmationSender() : count(0) {}
    
    // Copy constructor
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) {
        count = other.count;
        for (size_t i = 0; i < count; ++i) {
            arr[i] = other.arr[i];
        }
    }
    
    // Copy assignment operator
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            count = other.count;
            for (size_t i = 0; i < count; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    
    // Move constructor
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept : count(other.count) {
        for (size_t i = 0; i < count; ++i) {
            arr[i] = other.arr[i];
        }
        // Reset the other object
        other.count = 0;
    }
    
    // Move assignment operator
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
        if (this != &other) {
            count = other.count;
            for (size_t i = 0; i < count; ++i) {
                arr[i] = other.arr[i];
            }
            // Reset the other object
            other.count = 0;
        }
        return *this;
    }
    
    // Destructor
    ConfirmationSender::~ConfirmationSender() {
        for (size_t i = 0; i < count; ++i) {
            arr[i] = nullptr;
        }
    }
    
    // Overloaded operator +=
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        if (count < MAX_SIZE) {
            arr[count++] = &res;
        }
        return *this;
    }
    
    // Overloaded operator -=
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        size_t foundIndex = std::numeric_limits<size_t>::max(); // Initialize to max value
        for (size_t i = 0; i < count; ++i) {
            if (arr[i] == &res) {
                foundIndex = i;
                break;
            }
        }
        
        if (foundIndex != std::numeric_limits<size_t>::max()) {
            // Remove reservation and shift elements
            delete arr[foundIndex];
            for (size_t i = foundIndex; i < count - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            arr[count - 1] = nullptr;
            --count;
        }
        
        return *this;
    }
    
    // Overloaded operator <<
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "Confirmation Sender Content: \n";
        for (size_t i = 0; i < sender.count; ++i) {
            os << *sender.arr[i]; // Assuming Reservation has an overloaded operator<<
        }
        return os;
    }
}
