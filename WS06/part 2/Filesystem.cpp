/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */
#include "Filesystem.h"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace seneca
{
    Filesystem::Filesystem(const std::string &filename, const std::string &root_name)
        : m_root(nullptr), m_current(nullptr)
    {

        m_root = new Directory(root_name);
        m_current = m_root;

        // Load contents from file
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string path;
            std::string contents;

            if (line.find('|') != std::string::npos)
            {
                std::getline(iss, path, '|');
                std::getline(iss, contents);
                contents = contents.substr(contents.find_first_not_of(" "), contents.find_last_not_of(" ") + 1);
                create_resource(path, contents);
            }
            else
            {
                std::getline(iss, path);
                create_resource(path);
            }
        }

        file.close();
    }

    // Destructor
    Filesystem::~Filesystem()
    {
        delete m_root;
    }

    // Operator += to add a resource to the current directory
    Filesystem &Filesystem::operator+=(Resource *resource)
    {
        (*m_current) += resource;
        return *this;
    }

    // Change directory method
    Directory *Filesystem::change_directory(const std::string &name)
    {
        if (name.empty())
        {
            m_current = m_root;
        }
        else
        {
            Directory *dir = dynamic_cast<Directory *>(m_current->find(name));
            if (!dir)
            {
                throw std::invalid_argument("Cannot change directory! " + name + " not found.");
            }
            m_current = dir;
        }
        return m_current;
    }

    // Get current directory method
    Directory *Filesystem::get_current_directory() const
    {
        return m_current;
    }

    // Helper function to create resources (directories/files)
    void Filesystem::create_resource(const std::string &path, const std::string &contents)
    {
        std::istringstream iss(path);
        std::string token;
        Directory *current_dir = m_root;

        while (std::getline(iss, token, '/'))
        {
            if (token.empty())
                continue;

            Resource *res = current_dir->find(token);
            if (!res)
            {
                if (iss.eof())
                {
                    res = new File(token, contents);
                }
                else
                {
                    res = new Directory(token);
                }
                (*current_dir) += res;
            }

            current_dir = dynamic_cast<Directory *>(res);
            if (!current_dir)
            {
                throw std::runtime_error("Failed to cast Resource to Directory.");
            }
        }
    }

} // namespace seneca
