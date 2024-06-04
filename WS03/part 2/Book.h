#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

namespace seneca
{
    class Book
    {
        std::string m_title{};
        unsigned m_numChapters{};
        unsigned m_numPages{};

    public:
        Book();
        Book(const std::string &title, unsigned nChapters, unsigned nPages);

        // Added copy constructors from part 1
        Book(const Book &other_book);
        Book &operator=(const Book &other_book);

        // Added operator overload functions
        bool operator<(const Book &other_book) const;
        bool operator>(const Book &other_book) const;

        std::ostream &print(std::ostream &os) const;
    };
    std::ostream &operator<<(std::ostream &os, const Book &bk);
}

#endif