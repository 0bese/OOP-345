#include "Directory.h"
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <algorithm> // for std::find_if

namespace seneca
{

    class Directory : public Resource
    {
        std::vector<Resource *> m_contents;

    public:
        Directory::Directory(const std::string &name) : m_name(name)
        {
            if (!m_name.empty() && m_name.back() != '/')
                m_name += '/';
        }

        Directory::~Directory()
        {
            for (auto resource : m_contents)
            {
                delete resource;
            }
        }

        void Directory::update_parent_path(const std::string &parent_path) override
        {
            m_parent_path = parent_path;
            for (auto resource : m_contents)
            {
                resource->update_parent_path(m_parent_path + m_name);
            }
        }

        NodeType Directory::type() const override
        {
            return NodeType::DIR;
        }

        std::string Directory::path() const override
        {
            return m_parent_path + m_name;
        }

        std::string Directory::name() const override
        {
            return m_name;
        }

        int Directory::count() const override
        {
            return static_cast<int>(m_contents.size());
        }

        size_t Directory::size() const override
        {
            size_t totalSize = 0;
            for (auto resource : m_contents)
            {
                totalSize += resource->size();
            }
            return totalSize;
        }

        Directory &Directory::operator+=(Resource *resource)
        {
            auto existing = std::find_if(m_contents.begin(), m_contents.end(), [&](Resource *res)
                                         { return res->name() == resource->name(); });

            if (existing != m_contents.end())
            {
                throw std::invalid_argument("Resource with the same name already exists in this directory.");
            }

            resource->update_parent_path(m_parent_path + m_name);
            m_contents.push_back(resource);
            return *this;
        }

        Resource *Directory::find(const std::string &name, const std::vector<OpFlags> &flags = {})
        {
            // Implementation for finding resources by name, optionally recursively
        }

        void Directory::remove(const std::string &name, const std::vector<OpFlags> &flags = {})
        {
            // Implementation for removing resources by name, optionally recursively
        }

        void Directory::display(std::ostream &os, const std::vector<FormatFlags> &flags) const
        {
            os << "Total size: " << size() << " bytes\n";
            for (const auto &res : m_contents)
            {
                os << (res->type() == NodeType::DIR ? "D | " : "F | ");
                os << std::left << std::setw(15) << res->name() << " |";

                if (!flags.empty() && std::find(flags.begin(), flags.end(), FormatFlags::LONG) != flags.end())
                {
                    if (res->type() == NodeType::DIR)
                    {
                        os << std::right << std::setw(3) << dynamic_cast<const Directory *>(res)->count() << " |";
                    }
                    else
                    {
                        os << "    |";
                    }
                    os << std::right << std::setw(10) << res->size() << " bytes |";
                }
                os << "\n";
            }
        }

    private:
        std::string m_name;
        std::string m_parent_path = "/";
    };

} // namespace seneca
