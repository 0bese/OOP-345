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

#include <fstream>
#include <iostream>
#include "ProteinDatabase.h"

namespace seneca
{
    ProteinDatabase::ProteinDatabase()
    {
        numSequences = 0;
        sequences = nullptr;
    }

    ProteinDatabase::ProteinDatabase(const std::string &filename) : ProteinDatabase()
    {
        loadFromFile(filename);
    }

    // Copy constructor
    ProteinDatabase::ProteinDatabase(const ProteinDatabase &other) : numSequences(other.numSequences)
    {
        if (other.sequences)
        {
            sequences = new std::string[numSequences];
            for (size_t i = 0; i < numSequences; ++i)
            {
                sequences[i] = other.sequences[i];
            }
        }
        else
        {
            sequences = nullptr;
        }
    }

    // Copy assignment operator
    ProteinDatabase &ProteinDatabase::operator=(const ProteinDatabase &other)
    {
        if (this != &other)
        {
            delete[] sequences;
            numSequences = other.numSequences;
            if (other.sequences)
            {
                sequences = new std::string[numSequences];
                for (size_t i = 0; i < numSequences; ++i)
                {
                    sequences[i] = other.sequences[i];
                }
            }
            else
            {
                sequences = nullptr;
            }
        }
        return *this;
    }

    // Move constructor
    ProteinDatabase::ProteinDatabase(ProteinDatabase &&other) noexcept : numSequences(other.numSequences), sequences(other.sequences)
    {
        other.numSequences = 0;
        other.sequences = nullptr;
    }

    // Move assignment operator
    ProteinDatabase &ProteinDatabase::operator=(ProteinDatabase &&other) noexcept
    {
        if (this != &other)
        {
            delete[] sequences;

            numSequences = other.numSequences;
            sequences = other.sequences;

            other.numSequences = 0;
            other.sequences = nullptr;
        }
        return *this;
    }

    // Destructor
    ProteinDatabase::~ProteinDatabase()
    {
        delete[] sequences;
    }

    size_t ProteinDatabase::size() const
    {
        return numSequences;
    }

    std::string ProteinDatabase::operator[](size_t index) const
    {
        if (index < numSequences)
        {
            return sequences[index];
        }
        return "";
    }

    void ProteinDatabase::loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        // First pass: Count the number of sequences
        std::string line;
        size_t count = 0;
        while (std::getline(file, line))
        {
            if (line[0] == '>')
            {
                ++count;
            }
        }

        // Allocate memory for the sequences
        delete[] sequences; // Free any existing sequences
        sequences = new std::string[count];
        numSequences = count;

        // Second pass: Read the sequences
        file.clear();  // Clear eof and fail bits
        file.seekg(0); // Reset file pointer to the beginning

        size_t currentIndex = 0;
        while (std::getline(file, line))
        {
            if (line[0] == '>')
            {
                if (currentIndex < numSequences)
                {
                    currentIndex++;
                }
            }
            else
            {
                if (currentIndex > 0 && currentIndex <= numSequences)
                {
                    sequences[currentIndex - 1] += line;
                }
            }
        }
    }
}