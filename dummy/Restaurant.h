#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace seneca {

    class Restaurant {
        Reservation** m_reservations{nullptr};
        size_t m_cnt{0};

        void copyFrom(const Restaurant& src);
        void moveFrom(Restaurant&& src) noexcept;
        void clear();

    public:
        Restaurant() = default;
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& src);
        Restaurant(Restaurant&& src) noexcept;
        Restaurant& operator=(const Restaurant& src);
        Restaurant& operator=(Restaurant&& src) noexcept;
        ~Restaurant();

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest);
    };

}

#endif // SENECA_RESTAURANT_H
