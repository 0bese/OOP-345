/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */

#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "Directory.h"

namespace seneca
{
    class Filesystem
    {
        Directory *m_root{};
        Directory *m_current{};

    public:
        Filesystem(const std::string &fileName, const std::string &path = {});
        Filesystem &operator=(Filesystem &) = delete;
        Filesystem(Filesystem &) = delete;
        Filesystem(Filesystem &&) noexcept;
        Filesystem &operator=(Filesystem &&) noexcept;
        Filesystem &operator+=(Resource *);
        Directory *change_directory(const std::string & = "");
        Directory *get_current_directory() const;
        ~Filesystem();
    };
}
#endif // !SENECA_FILESYSTEM_H
