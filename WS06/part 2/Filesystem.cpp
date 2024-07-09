/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Filesystem.h"
#include "File.h"

using namespace std;
namespace seneca
{
    Filesystem::Filesystem(const std::string &fileName, const std::string &str)
    {

        std::ifstream inputFile(fileName);
        if (!inputFile)
        {
            throw invalid_argument("File not found: " + fileName);
        }
        else
        {
            m_root = new Directory(str);
            m_current = m_root;
            string line;
            while (getline(inputFile, line))
            {
                string path, contents;
                size_t delimiter = line.find("|");
                size_t pos1 = line.find_first_not_of(" ");
                size_t pos2 = line.find_last_not_of(" ", delimiter - 1);
                path = line.substr(pos1, pos2 - pos1 + 1);
                line.erase(0, delimiter + 1);
                pos1 = line.find_first_not_of(" ");
                line.erase(0, pos1);
                pos2 = line.find_last_not_of(" ");
                contents = line.substr(0, pos2 + 1);
                size_t pos = 0;
                vector<seneca::OpFlags> flag;
                flag.push_back(seneca::OpFlags::RECURSIVE);
                Directory *rootDir = m_root;
                while ((pos = path.find("/")) != string::npos)
                {
                    if (!(m_root->find(path.substr(0, pos + 1), flag)))
                    {
                        Directory *dir = new Directory(path.substr(0, pos + 1));
                        *rootDir += dir;
                        rootDir = dir;
                    }
                    else
                    {
                        rootDir = dynamic_cast<Directory *>(m_root->find(path.substr(0, pos + 1), flag));
                    }
                    path = path.substr(pos + 1);
                }

                if (delimiter != string::npos)
                {
                    if (!(m_root->find(path)))
                    {
                        File *file = new File(path, contents);
                        *rootDir += file;
                    }
                }
            }
        }
    }

    Filesystem::Filesystem(Filesystem &&other) noexcept
    {
        *this = std::move(other);
    }

    Filesystem &Filesystem::operator=(Filesystem &&other) noexcept
    {
        if (this != &other)
        {
            delete m_root;
            m_root = other.m_root;
            delete other.m_root;
            other.m_current = nullptr;
            m_current = m_root;
        }
        return *this;
    }

    Filesystem &Filesystem::operator+=(Resource *resPtr)
    {
        *m_current += resPtr;
        return *this;
    }

    Directory *Filesystem::change_directory(const std::string &dirName)
    {

        if (dirName.empty())
        {
            m_current = m_root;
        }
        else
        {
            vector<seneca::OpFlags> flag;
            flag.push_back(seneca::OpFlags::RECURSIVE);
            Directory *dir = dynamic_cast<Directory *>(m_current->find(dirName, flag));
            if (dir)
            {
                m_current = dir;
                return m_current;
            }
            else
            {
                throw std::invalid_argument("Cannot change directory! " + dirName + " not found.");
            }
        }
        return m_current;
    }

    Directory *Filesystem::get_current_directory() const
    {
        return m_current;
    }

    Filesystem::~Filesystem()
    {
        delete m_root;
        m_current = nullptr;
    }
}