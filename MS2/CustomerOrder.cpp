#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <iomanip>

namespace seneca
{
    size_t CustomerOrder::m_widthField = 0;

    /**
     * Constructor for the CustomerOrder class with default member initialization.
     *
     * @param None
     *
     * @return None
     *
     * @throws None
     */
    CustomerOrder::CustomerOrder() : m_name{}, m_product{},
                                     m_cntItem{0}, m_lstItem{nullptr} {}

    /**
     * Constructs a CustomerOrder object from a string.
     *
     * @param theStr The string from which to construct the CustomerOrder.
     *
     * @throws None.
     */
    CustomerOrder::CustomerOrder(const std::string &theStr)
    {
        Utilities u;
        size_t pos = 0;
        size_t tempPos = 0;
        size_t count = 0;
        bool more = true;

        m_name = u.extractToken(theStr, pos, more);
        m_product = u.extractToken(theStr, pos, more);

        tempPos = pos;

        while (more)
        {
            u.extractToken(theStr, tempPos, more);
            count++;
        }

        m_cntItem = count;
        m_lstItem = new Item *[m_cntItem];

        more = true;

        for (size_t i = 0; i < m_cntItem && more; ++i)
        {
            std::string itemName = u.extractToken(theStr, pos, more);
            m_lstItem[i] = new Item(itemName);
        }

        if (u.getFieldWidth() > m_widthField)
        {
            m_widthField = u.getFieldWidth();
        }
    }

    /**
     * Copy constructor not allowed.
     *
     * @param other The other CustomerOrder object to copy
     *
     * @throws std::runtime_error Copy constructor not allowed.
     */
    CustomerOrder::CustomerOrder(const CustomerOrder &other)
    {
        throw std::runtime_error("Copy constructor not allowed.");
    }

    /**
     * Assignment operator not allowed.
     *
     * @param other The other CustomerOrder object to copy
     *
     * @throws std::runtime_error Assignment operator not allowed.
     */
    CustomerOrder &CustomerOrder::operator=(const CustomerOrder &other)
    {
        if (this != &other)
        {
            throw std::runtime_error("Assignment operator not allowed.");
        }
        return *this;
    }

    /**
     * Move constructor for the CustomerOrder class.
     *
     * @param other the rvalue reference to the other CustomerOrder object
     *
     * @throws None
     *
     * @return None
     */
    CustomerOrder::CustomerOrder(CustomerOrder &&other) noexcept
    {
        *this = std::move(other);
    }

    /**
     * Move assignment operator for the CustomerOrder class.
     *
     * @param other the rvalue reference to the other CustomerOrder object
     *
     * @throws None
     *
     * @return None
     */
    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&other) noexcept
    {
        if (this != &other)
        {
            for (size_t i = 0; i < m_cntItem; ++i)
            {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;

            m_name = std::move(other.m_name);
            m_product = std::move(other.m_product);
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;

            other.m_lstItem = nullptr;
            other.m_cntItem = 0;
        }
        return *this;
    }

    /**
     * Destructor for the CustomerOrder class.
     *
     * This destructor frees the memory allocated for the items in the list
     * and the list itself.
     *
     * @throws None
     */
    CustomerOrder::~CustomerOrder()
    {
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    /**
     * Checks if the order is filled.
     *
     * @return true if all items in the order are filled, false otherwise
     */
    bool CustomerOrder::isOrderFilled() const
    {
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (!m_lstItem[i]->m_isFilled)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if a specific item in the customer order is filled.
     *
     * @param itemName The name of the item to check.
     *
     * @return `true` if the item is filled, `false` otherwise.
     *
     * @throws None.
     */
    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        bool itemExists = false;
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (m_lstItem[i]->m_itemName == itemName)
            {
                itemExists = true;
                if (!m_lstItem[i]->m_isFilled)
                {
                    return false;
                }
            }
        }
        return !itemExists;
    }

    /**
     * Fills an item in the customer order with the provided station.
     *
     * @param station The station to fill the item with.
     * @param os The output stream to print the result.
     *
     * @return void
     *
     * @throws None
     */
    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            if (m_lstItem[i]->m_itemName == station.getItemName())
            {
                if (station.getQuantity() > 0)
                {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;

                    os << "    Filled " << m_name << ", " << m_product
                       << " [" << m_lstItem[i]->m_itemName << "]" << '\n';
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product
                       << " [" << m_lstItem[i]->m_itemName << "]" << '\n';
                }
                return;
            }
        }
    }

    /**
     * Displays the customer order information on the provided output stream.
     *
     * @param os The output stream to display the customer order on.
     *
     * @return void
     *
     * @throws None
     */
    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << '\n';
        for (size_t i = 0; i < m_cntItem; ++i)
        {
            os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
               << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName
               << (m_lstItem[i]->m_isFilled ? " - FILLED" : " - TO BE FILLED") << '\n';
        }
    }
}
