#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H
#include <iostream>
#include "Book.h"
#include "Collection.h"

namespace seneca
{
    template <typename T>
    class OrderedCollection : public Collection<T, 72>
    {
    public:
        bool operator+=(const T &item)
        {
            unsigned size = Collection<T, 72>::size();
            if (size >= Collection<T, 72>::capacity())
            {
                return false;
            }

            size++;
            if (size == 1)
            {
                (*this)[size - 1] = item;
            }
            else
            {
                (*this)[size - 1] = item;
                for (unsigned i = 0; i < size; i++)
                {
                    for (unsigned j = 0; j < size - 1; j++)
                    {
                        if ((*this)[j] > (*this)[j + 1])
                        {
                            T tmp = (*this)[j];
                            (*this)[j] = (*this)[j + 1];
                            (*this)[j + 1] = tmp;
                            // std::cout << (*this)[j] << std::endl;
                        }
                    }
                }
            }
            Collection<T, 72>::setSmallestItem(item);
            Collection<T, 72>::setLargestItem(item);
            Collection<T, 72>::incrSize();
            return true;
        }
    };

}

#endif //! SENECA_ORDEREDCOLLECTION_H