/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */
#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include <string>
#include <iostream>
#include "Resource.h"
#include "Flags.h"
namespace seneca
{
    class File : public Resource
    {
    private:
        std::string m_contents; // stores contents of file

    public:
        // custom constructor that initializes file with name and optional content
        File(const std::string &name, const std::string &contents = "");

        // override function from resource
        // update parent path of file
        void update_parent_path(const std::string &parentPath) override;

        // returning type of resource
        NodeType type() const override;

        // returning full path of file
        std::string path() const override;

        // returning name of file
        std::string name() const override;

        // returning -1 as count does not apply to files
        int count() const override;

        // returning size of file contents in bytes
        size_t size() const override;

        // creating and returning a copy of file object
        Resource *clone() const override;

        // Copy constructor
        File(const File &other) = default;

        // Copy assignment operator
        File &operator=(const File &other) = default;

        // Move constructor
        File(File &&other) noexcept = default;

        // Move assignment operator
        File &operator=(File &&other) noexcept = default;

        // Destructor
        ~File() = default;
    };
}
#endif // SENECA_FILE_H