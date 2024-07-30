/*/////////////////////////////////////////////////////////////////////////
                        Milestone-3
Full Name  : Kojo Anyane Obese
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NRA
Date       : 29/07/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace seneca
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation *m_pNextStation{};

    public:
        Workstation(const std::string &str);
        bool attemptToMoveOrder();
        void fill(std::ostream &os);
        Workstation *getNextStation() const;
        void setNextStation(Workstation *station = nullptr);
        Workstation &operator+=(CustomerOrder &&newOrder);
        void display(std::ostream &os) const;

        // Copy Constructor
        Workstation(const Workstation &cpyFrom) = delete;
        // Copy Assignment Operator
        Workstation &operator=(const Workstation &cpyFrom) = delete;
        // Move Constructor (*this = std::move(cpyFrom);)
        Workstation(Workstation &&mvFrom) = delete;
        // Move Assignment Operator
        Workstation &operator=(Workstation &&mvFrom) = delete;
    };
}

#endif // SDDS_WORKSTATION_H