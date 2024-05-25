/*/////////////////////////////////////////////////////////////////////////
                        Workshop-2 Part-2
Full Name  : Kojo Anyane Obese
Student ID#: 137653226
Email      : kaobese@myseneca.ca
Section    : NRA
Date       : 25/05/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H
#include <iostream>
#include <iomanip>
#include <chrono>

namespace seneca
{
    struct Task
    {
        std::string taskName;
        std::string timeUnits;
        std::chrono::steady_clock::duration duration;
    };

    class TimedTask
    {
        static const size_t MAX_RECORDS = 10;
        size_t m_numRecords{};
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
        Task tasks[MAX_RECORDS];

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char *taskName);

        friend std::ostream &operator<<(std::ostream &os, const TimedTask &tt);
    };
}
#endif