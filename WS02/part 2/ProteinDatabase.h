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

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>

namespace seneca
{
    class ProteinDatabase
    {
    public:
        ProteinDatabase();
        ProteinDatabase(const std::string &filename);

        // Copy constructor
        ProteinDatabase(const ProteinDatabase &other);

        // Copy assignment operator
        ProteinDatabase &operator=(const ProteinDatabase &other);

        // Move constructor
        ProteinDatabase(ProteinDatabase &&other) noexcept;

        // Move assignment operator
        ProteinDatabase &operator=(ProteinDatabase &&other) noexcept;

        // Destructor
        ~ProteinDatabase();

        size_t size() const;
        std::string operator[](size_t index) const;

    private:
        void loadFromFile(const std::string &filename);

        size_t numSequences;
        std::string *sequences;
    };
}

#endif // SENECA_PROTEINDATABASE_H