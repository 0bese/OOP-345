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

#include "TimedTask.h"

using namespace std;
namespace seneca
{
    TimedTask::TimedTask()
    {
        m_numRecords = 0;
    }
    void TimedTask::startClock()
    {
        m_startTime = chrono::steady_clock::now();
    }

    void TimedTask::stopClock()
    {
        m_endTime = chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char *taskName)
    {
        if (m_numRecords < MAX_RECORDS)
        {
            tasks[m_numRecords].taskName = taskName;
            tasks[m_numRecords].timeUnits = "nanoseconds";
            tasks[m_numRecords].duration = chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
            ++m_numRecords;
        }
    }

    ostream &operator<<(ostream &os, const TimedTask &tt)
    {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (size_t i = 0; i < tt.m_numRecords; ++i)
        {
            os << setw(21) << left << tt.tasks[i].taskName
               << setw(13) << right << tt.tasks[i].duration.count()
               << " " << tt.tasks[i].timeUnits << '\n';
        }
        os << "--------------------------\n";
        return os;
    }

}