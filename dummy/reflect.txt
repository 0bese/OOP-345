#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <iostream>
#include <string>

namespace seneca {

    class Reservation {
        std::string m_reservationID;
        std::string m_reservationName;
        std::string m_email;
        int m_numOfPeople{0};
        int m_day{0};
        int m_hour{0};

    public:
        Reservation() = default;
        Reservation(const std::string& res);

        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

    std::string trim(const std::string& str);

}

#endif // SENECA_RESERVATION_H
