#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H

#include "Resource.h"
#include <vector>
#include <stdexcept>
#include <iomanip>

namespace seneca
{
    class Directory : public Resource
    {
        std::vector<Resource *> m_contents; // Changed to store pointers
        Directory(const Directory &) = delete;
        Directory &operator=(const Directory &) = delete;

    public:
        Directory(const std::string &name);

        void update_parent_path(const std::string &parent_path) override;

        NodeType type() const override;

        std::string path() const override;

        std::string name() const override;

        int count() const override;

        size_t size() const override;

        Directory &operator+=(Resource *resource);

        Resource *find(const std::string &name, const std::vector<OpFlags> &flags = {});

        void remove(const std::string &name, const std::vector<OpFlags> &flags = {});

        void display(std::ostream &os, const std::vector<FormatFlags> &flags = {}) const;

        ~Directory();
    };

}

#endif // SENECA_DIRECTORY_H
