/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */

#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Resource.h"

namespace seneca
{
    class Directory : public Resource
    {
        std::vector<Resource *> m_contents{};

    public:
        Directory(){};
        Directory(const std::string &name);
        void update_parent_path(const std::string &path);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory &operator+=(Resource *resource);
        Resource *find(const std::string &name, const std::vector<OpFlags> &flags = {});
        ~Directory();

        Directory(const Directory &) = delete;
        Directory &operator=(const Directory &) = delete;
        Directory(Directory &&) = delete;
        Directory &operator=(Directory &&) = delete;

        // part 2
        void remove(const std::string &name, const std::vector<OpFlags> &flags = {});
        void display(std::ostream &os, const std::vector<FormatFlags> &flags = {}) const;
    };
}
#endif // !SENECA_DIRECTORY_H
