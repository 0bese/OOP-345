/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */

#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include <iostream>
#include <cstring>
#include <string>
#include "Resource.h"

namespace seneca
{
    class File : public Resource
    {
        std::string m_contents{};

    public:
        File(const std::string &name, const std::string &contents = "");
        void update_parent_path(const std::string &);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };
}
#endif // !SENECA_FILE_H
