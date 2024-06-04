#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Book.h"
namespace seneca
{
    template <typename T, unsigned C>
    class Collection
    {
        static T m_smallestItem;
        static T m_largestItem;
        T m_items[C]{};
        unsigned m_size;
        unsigned m_capacity;

    protected:
        void setSmallestItem(const T &obj);
        void setLargestItem(const T &obj);
        // part 2
        T &operator[](unsigned index);
        void incrSize();

    public:
        Collection();
        static T getSmallestItem();
        static T getLargestItem();
        unsigned size() const;
        unsigned capacity() const;
        bool operator+=(const T &other);
        void print(std::ostream &out) const;
    };

    template <typename T, unsigned C>
    void Collection<T, C>::setSmallestItem(const T &obj)
    {
        if (obj < m_smallestItem)
        {
            m_smallestItem = obj;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::setLargestItem(const T &obj)
    {
        if (obj > m_largestItem)
        {
            m_largestItem = obj;
        }
    }
    // part 2

    template <typename T, unsigned C>
    T &Collection<T, C>::operator[](unsigned index)
    { // is query or not

        return m_items[index];
    }

    template <typename T, unsigned C>
    void Collection<T, C>::incrSize()
    {
        m_size++;
    }

    template <typename T, unsigned C>
    Collection<T, C>::Collection() : m_size(0), m_capacity(C)
    {
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getSmallestItem()
    {
        return m_smallestItem;
    }

    template <typename T, unsigned C>
    T Collection<T, C>::getLargestItem()
    {
        return m_largestItem;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::size() const
    {
        return m_size;
    }

    template <typename T, unsigned C>
    unsigned Collection<T, C>::capacity() const
    {
        return m_capacity;
    }

    template <typename T, unsigned C>
    bool Collection<T, C>::operator+=(const T &other)
    {
        if (m_size >= m_capacity)
        {
            return false;
        }
        else
        {
            m_size++;
            m_items[m_size - 1] = other;
            setSmallestItem(other);
            setLargestItem(other);
            return true;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::print(std::ostream &out) const
    {
        out << "[";
        for (unsigned int i = 0; i < m_size; ++i)
        {
            out << m_items[i];
            if (i + 1 != m_size)
            {
                out << ",";
            }
        }
        out << "]\n";
    }

    template <typename T, unsigned int C>
    T Collection<T, C>::m_smallestItem = {T(9999)};

    template <typename T, unsigned int C>
    T Collection<T, C>::m_largestItem = {T(-9999)};

    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    // part 2
    template <>
    Book Collection<Book, 72>::m_smallestItem = {"", 1, 10000};

    template <>
    Book Collection<Book, 72>::m_largestItem = {"", 10000, 1};

    template <>
    void Collection<Book, 10>::print(std::ostream &out) const
    {
        out << "| ---------------------------------------------------------------------------|" << std::endl;
        for (auto i = 0u; i < m_size; i++)
        {
            out << "| " << m_items[i] << " |" << "\n";
        }
        out << "| ---------------------------------------------------------------------------|" << std::endl;
    }

    template <>
    void Collection<Book, 72>::print(std::ostream &out) const
    {
        out << "| ---------------------------------------------------------------------------|" << std::endl;
        for (auto i = 0u; i < m_size; i++)
        {
            out << "| " << m_items[i] << " |" << "\n";
        }
        out << "| ---------------------------------------------------------------------------|" << std::endl;
    }

}

#endif // !SENECA_COLLECTION_H