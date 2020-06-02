#ifndef LAB2_2_SEQUENCE_HPP
#define LAB2_2_SEQUENCE_HPP

#include "options.hpp"

template<typename T>
class sequence {
public:
    virtual void append(option<T>) = 0;

    virtual void prepend(option<T>) = 0;

    virtual void print() = 0;

    virtual int get_size() const = 0;

    virtual void set_el(option<T>, int) = 0;

    virtual option<T> get_el(int) = 0;

    virtual void insert_el(option<T>, int) = 0;

    virtual option<T> get_last() = 0;

    virtual option<T> get_first() = 0;

    virtual sequence<T> *get_index_data(int, int) = 0;

    virtual void concat(sequence<T> *) = 0;

    virtual bool operator==(sequence<T> *) = 0;

    virtual ~sequence() = default;

};

#endif //LAB2_2_SEQUENCE_HPP
