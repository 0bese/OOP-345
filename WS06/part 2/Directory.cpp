/*
 Name: Kojo Anyane Obese
 Email: kaobese@myseneca.ca
 Student ID: 137653226
 Date: 9 July 2024
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Directory.h"
#include <iomanip>

using namespace std;
namespace seneca
{
    Directory::Directory(const std::string &name)
    {
        m_name = name;
        if (!m_name.empty() && m_name.back() != '/')
            m_name += "/";
    }

    void Directory::update_parent_path(const std::string &path)
    {
        m_parent_path = path;
        for (auto &resource : m_contents)
        {
            resource->update_parent_path(m_parent_path + m_name);
        }
    }

    NodeType Directory::type() const
    {
        return NodeType::DIR;
    }

    std::string Directory::path() const
    {
        return m_parent_path + m_name;
    }

    std::string Directory::name() const
    {
        return m_name;
    }

    int Directory::count() const
    {
        return static_cast<int>(m_contents.size());
    }

    size_t Directory::size() const
    {
        size_t totalSize = 0u;

        for (auto &resource : m_contents)
        {
            totalSize += resource->size();
        }

        return totalSize;
    }

    Directory &Directory::operator+=(Resource *resource)
    {
        for (Resource *res : m_contents)
        {
            if (res)
            {
                if (res->name() == resource->name())
                {
                    throw std::runtime_error("Error...! Resource with the same name already exists...");
                }
            }
        }
        resource->update_parent_path(path());
        m_contents.push_back(resource);
        return *this;
    }

    Resource *Directory::find(const std::string &name, const std::vector<OpFlags> &flags)
    {
        auto Flag = std::find_if(flags.begin(), flags.end(), [](OpFlags flag)
                                 { return flag == OpFlags::RECURSIVE; });

        if (Flag != flags.end())
        {
            for (auto &resource : m_contents)
            {
                if (resource->type() == NodeType::DIR)
                {
                    auto findResource = dynamic_cast<Directory *>(resource)->find(name, flags);
                    if (findResource != nullptr)
                    {
                        return findResource;
                    }
                }
            }
        }

        for (auto &resource : m_contents)
        {
            if (resource->name() == name)
            {
                return resource;
            }
        }
        return nullptr;
    }

    Directory::~Directory()
    {
        for (auto &Resource : m_contents)
        {
            delete Resource;
        }
        m_contents.clear();
    }

    // part 2
    void Directory::remove(const std::string &name, const std::vector<OpFlags> &flags)
    {
        bool recursive = false;
        for (auto flag : flags)
        {
            if (flag == OpFlags::RECURSIVE)
            {
                recursive = true;
            }
        }
        Resource *result = find(name, flags);
        if (result)
        {
            size_t resultIdx{};
            for (size_t i = 0; i < m_contents.size(); i++)
            {
                if (m_contents[i] == result)
                {
                    resultIdx = i;
                }
            }
            if (result->type() == NodeType::DIR)
            {
                if (recursive)
                {
                    delete result;
                    result = nullptr;
                    m_contents.erase(m_contents.begin() + resultIdx);
                }
                else
                {
                    throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
                }
            }
            else if (result->type() == NodeType::FILE)
            {
                delete result;
                result = nullptr;
                m_contents.erase(m_contents.begin() + resultIdx);
            }
            else
            {
                throw std::runtime_error("An unknown type found.");
            }
        }
        else
        {
            throw std::invalid_argument(name + " does not exist in " + path() + ".");
        }
    }

    void Directory::display(std::ostream &os, const std::vector<FormatFlags> &flags) const
    {
        bool Flag = false;
        for (auto flag : flags)
            if (flag == FormatFlags::LONG)
                Flag = true;

        os << "Total size: " << std::setw(2) << size() << " bytes\n";

        for (auto resource : m_contents)
        {
            if (resource->type() == NodeType::FILE)
            {
                os << "F | ";
            }
            else if (resource->type() == NodeType::DIR)
            {
                os << "D | ";
            }
            os << std::setw(15) << std::setiosflags(std::ios::left) << resource->name() << std::setiosflags(std::ios::left) << " |";
            if (Flag)
            {
                if (resource->type() == NodeType::FILE)
                {
                    os << "  " << std::setw(2) << "" << "|" << std::setw(5) << std::setiosflags(std::ios::right) << resource->size() << std::resetiosflags(std::ios::right) << " bytes | \n";
                }
                else if (resource->type() == NodeType::DIR)
                {
                    os << "  " << std::setw(2) << resource->count() << "|" << std::setw(5) << std::setiosflags(std::ios::right) << resource->size() << std::resetiosflags(std::ios::right) << " bytes | \n";
                }
            }
            else
                os << std::endl;
        }
    }
}