/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H

#include "Directory.h"
#include "Resource.h"

#include "File.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace seneca
{
    class Directory;

    class Filesystem
    {
        Directory *m_root;
        Directory *m_current;

        void load_file(const std::string &filename);
        void create_resource(const std::string &path, const std::string &contents = "");

    public:
        Filesystem(const std::string &filename, const std::string &root_name = "");
        ~Filesystem();

        Filesystem &operator+=(Resource *resource);
        Directory *change_directory(const std::string &name = "");
        Directory *get_current_directory() const;
    };
}
#endif // SENECA_FILESYSTEM_H