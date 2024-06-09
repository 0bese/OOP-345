#include <iomanip>
#include <cctype>
#include "Reservation.h"

namespace seneca {

    std::string trim(const std::string& str) {
        auto start = str.begin();
        while (start != str.end() && std::isspace(*start)) {
            ++start;
        }
        if (start == str.end()) {
            return "";
        }
        auto end = str.end();
        do {
            --end;
        } while (end > start && std::isspace(*end));
        return std::string(start, end + 1);
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    Reservation::Reservation(const std::string& res) {
        size_t pos1 = 0, pos2, pos3;
        size_t cnt = 0;

        pos2 = res.find(':');
        pos3 = res.find(',');

        while (pos3 != std::string::npos) {
            switch (cnt) {
                case 0:
                    m_reservationID = trim(res.substr(pos1, pos2 - pos1));
                    pos1 = pos2 + 1;
                    break;
                case 1:
                    m_reservationName = trim(res.substr(pos1, pos3 - pos1));
                    pos1 = pos3 + 1;
                    break;
                case 2:
                    m_email = trim(res.substr(pos1, pos3 - pos1));
                    pos1 = pos3 + 1;
                    break;
                case 3: {
                    std::string temp_numOfPeople = res.substr(pos1, pos3 - pos1);
                    m_numOfPeople = std::stoi(temp_numOfPeople);
                    pos1 = pos3 + 1;
                    break;
                }
                case 4: {
                    std::string temp_day = res.substr(pos1, pos3 - pos1);
                    m_day = std::stoi(temp_day);
                    pos1 = pos3 + 1;

                    std::string temp_hour = res.substr(pos1);
                    m_hour = std::stoi(temp_hour);
                    pos1 = pos3 + 1;
                    break;
                }
            }
            pos3 = res.find(',', pos1);
            ++cnt;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": "
           << std::right << std::setw(20) << res.m_reservationName << "  "
           << std::left << std::setw(20) << ("<" + res.m_email + ">") << "    ";

        if (res.m_hour >= 6 && res.m_hour <= 9) {
            os << "Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00 for "
               << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.");
        } else if (res.m_hour >= 11 && res.m_hour <= 15) {
            os << "Lunch on day " << res.m_day << " @ " << res.m_hour << ":00 for "
               << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.");
        } else if (res.m_hour >= 17 && res.m_hour <= 21) {
            os << "Dinner on day " << res.m_day << " @ " << res.m_hour << ":00 for "
               << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.");
        } else {
            os << "Drinks on day " << res.m_day << " @ " << res.m_hour << ":00 for "
               << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.");
        }

        os << std::endl;
        return os;
    }

}
