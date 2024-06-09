#include "Restaurant.h"

namespace seneca {

    // Helper function to copy data from another Restaurant
    void Restaurant::copyFrom(const Restaurant& src) {
        m_cnt = src.m_cnt;
        m_reservations = new Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; ++i) {
            m_reservations[i] = new Reservation(*src.m_reservations[i]);
        }
    }

    // Helper function to move data from another Restaurant
    void Restaurant::moveFrom(Restaurant&& src) noexcept {
        m_cnt = src.m_cnt;
        m_reservations = src.m_reservations;
        src.m_reservations = nullptr;
        src.m_cnt = 0;
    }

    // Helper function to clear data
    void Restaurant::clear() {
        for (size_t i = 0; i < m_cnt; ++i) {
            delete m_reservations[i];
        }
        delete[] m_reservations;
        m_reservations = nullptr;
        m_cnt = 0;
    }

    // Constructor with reservations array and count
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_cnt{cnt} {
        m_reservations = new Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; ++i) {
            m_reservations[i] = new Reservation(*reservations[i]);
        }
    }

    // Copy constructor
    Restaurant::Restaurant(const Restaurant& src) {
        copyFrom(src);
    }

    // Copy assignment operator
    Restaurant& Restaurant::operator=(const Restaurant& src) {
        if (this != &src) {
            clear();
            copyFrom(src);
        }
        return *this;
    }

    // Move constructor
    Restaurant::Restaurant(Restaurant&& src) noexcept {
        moveFrom(std::move(src));
    }

    // Move assignment operator
    Restaurant& Restaurant::operator=(Restaurant&& src) noexcept {
        if (this != &src) {
            clear();
            moveFrom(std::move(src));
        }
        return *this;
    }

    // Destructor
    Restaurant::~Restaurant() {
        clear();
    }

    // Return the number of reservations
    size_t Restaurant::size() const {
        return m_cnt;
    }

    // Overload operator<< for Restaurant
    std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest) {
        static int CALL_CNT = 0;
        CALL_CNT++;
        ostr << "--------------------------" << std::endl
             << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl
             << "--------------------------" << std::endl;
        if (rest.size() == 0) {
            ostr << "This restaurant is empty!" << std::endl;
        } else {
            for (size_t i = 0; i < rest.m_cnt; ++i) {
                ostr << *rest.m_reservations[i];
            }
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

}
