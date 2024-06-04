#include "Book.h"
namespace seneca
{

    Book::Book()
    {
        m_title = "";
        m_numChapters = 0;
        m_numPages = 0;
    }

    Book::Book(const std::string &title, unsigned nChapters, unsigned nPages)
    {
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
    }

    Book::Book(const Book &other_book)
    {
        m_title = other_book.m_title;
        m_numChapters = other_book.m_numChapters;
        m_numPages = other_book.m_numPages;
    }

    Book &Book::operator=(const Book &other_book)
    {
        if (this != &other_book)
        {
            this->m_title = other_book.m_title;
            this->m_numChapters = other_book.m_numChapters;
            this->m_numPages = other_book.m_numPages;
        }
        return *this;
    }

    bool Book::operator<(const Book &other) const
    {
        double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
        double pagesPerChapter2 = other.m_numPages / static_cast<double>(other.m_numChapters);
        return pagesPerChapter < pagesPerChapter2 ? true : false;
    }

    bool Book::operator>(const Book &other) const
    {
        double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
        double pagesPerChapter2 = other.m_numPages / static_cast<double>(other.m_numChapters);
        return pagesPerChapter > pagesPerChapter2 ? true : false;
    }

    std::ostream &Book::print(std::ostream &os) const
    {
        if (m_title != "")
        {
            std::string collect = m_title;
            collect.append(",");
            collect.append(std::to_string(m_numChapters));
            collect.append(",");
            collect.append(std::to_string(m_numPages));
            // os << std::setw(53) << std::right << m_title << ',' << m_numChapters << ',' << m_numPages;
            os << std::setw(56) << std::right << collect;
            double pagesPerChapter = m_numPages / static_cast<double>(m_numChapters);
            os << " | (" << std::left << std::fixed << std::setprecision(6) << pagesPerChapter << ")    ";
            os << std::defaultfloat;
        }
        else
        {
            os << "| Invalid book data";
        }

        return os;
    }

    std::ostream &operator<<(std::ostream &os, const Book &bk)
    {
        return bk.print(os);
    }

}