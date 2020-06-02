#ifndef LAB2_2_DINAMIC_ARRAY_HPP
#define LAB2_2_DINAMIC_ARRAY_HPP
#include <iostream>
#include "options.hpp"


template<typename T>
class dinamic_array {
private:
    option<T> *data;
    bool has_data{};
    int size{};
public:
    explicit dinamic_array() : size(0), data(nullptr), has_data(false) {}

    dinamic_array(const dinamic_array &a);

    dinamic_array(option<T> *, int);

    explicit dinamic_array(int);

    ~dinamic_array();

    bool try_has_data();

    void append(option<T> el);

    void prepend(option<T> el);

    void set_size(int);

    void print();

    option<T> get_el(int) const;

    void insert_el(option<T>, int);

    void set_el(option<T>, int);

    option<T> *get_data() const;

    dinamic_array<T> *get_index_data(int, int);

    //int get_max_pr();

    void concat(const dinamic_array &a);

    int get_size() const;

    bool operator==(const dinamic_array &right);
};


template<typename T>
void dinamic_array<T>::append(option<T> el) {

    if (not this->has_data) {
        this->size++;

        this->data = new option<T>[this->size];
        this->data[0].set_value(el.get_value());
        //this->data[0].set_priority(el.get_priority());
        this->has_data = true;

    } else {
        this->size++;
        auto *buff = new option<T>[this->size];

        for (int i = 0; i < this->size - 1; i++) {
            try {
                buff[i].set_value(this->data[i].get_value());
                //buff[i].set_priority(this->data[i].get_priority());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }

        buff[this->size - 1].set_value(el.get_value());
        //buff[this->size - 1].set_priority(el.get_priority());

        delete[] this->data;
        this->data = new option<T>[this->size];

        for (int i = 0; i < this->size; i++) {
            try {
                this->data[i].set_value(buff[i].get_value());
                //this->data[i].set_priority(buff[i].get_priority());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }
    }
}

template<typename T>
void dinamic_array<T>::prepend(option<T> el) {
    if (not this->has_data) {
        this->size++;

        this->data = new option<T>[this->size];
        this->data[0].set_value(el.get_value());
        //this->data[0].set_priority(el.get_priority());

        this->has_data = true;

    } else {
        this->size++;
        auto *buff = new option<T>[this->size];

        for (int i = 1; i < this->size; i++) {
            try {
                buff[i].set_value(this->data[i].get_value());
                //buff[i].set_priority(this->data[i].get_priority());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }

        buff[0].set_value(el.get_value());
        //buff[0].set_priority(el.get_priority());

        delete[] this->data;
        this->data = new option<T>[this->size];

        for (int i = 0; i < this->size; i++) {
            try {
                this->data[i].set_value(buff[i].get_value());
                //this->data[i].set_priority(buff[i].get_priority());
            } catch (const char *msg) {
                std::cout << msg;
            }
        }
    }
}

template<typename T>
void dinamic_array<T>::print() {
    for (int i = 0; i < this->size; i++) {
        if (this->has_data){
            std::cout << "val: " << this->data[i].get_value() <<  '\t';
        } else {
            throw "No data";
        }
    }
}

template<typename T>
int dinamic_array<T>::get_size() const {
    return this->size;
}

template<typename T>
option<T> dinamic_array<T>::get_el(int index) const {
    try {
        option<T> a = this->data[index];
        return a;
    } catch (const char *msg) {
        std::cout << msg;
    }
}


template<typename T>
void dinamic_array<T>::insert_el(option<T> el, int index) {
    this->size++;
    auto *buff = new option<T>[this->size];
    for (int i = index; i < this->size - 1; i++) {
        try {
            buff[i + 1].set_value(this->data[i].get_value());
            //buff[i + 1].set_priority(this->data[i].get_priority());
        } catch (const char *msg) {
            std::cout << msg;
        }
    }

    for (int i = 0; i < index; i++) {
        try {
            buff[i].set_value(this->data[i].get_value());
            //buff[i].set_priority(this->data[i].get_priority());
        } catch (const char *msg) {
            std::cout << msg;
        }
    }

    buff[index] = el;

    delete[] this->data;
    this->data = new option<T>[this->size];

    for (int i = 0; i < this->size; i++) {
        try {
            this->data[i].set_value(buff[i].get_value());
            //this->data[i].set_priority(buff[i].get_priority());
        } catch (const char *msg) {
            std::cout << msg;
        }
    }

}

template<typename T>
dinamic_array<T>* dinamic_array<T>::get_index_data(int k, int j) {
    if (k >= 0 && j >= 0 && k <= this->size - 1 && j <= this->size - 1) {
        auto *buff = new option<T>[j - k + 1];
        int cnt = 0;
        for (int i = k; i < j + 1; i++) {
            try {
                buff[cnt].set_value(this->data[i].get_value());
                //buff[cnt].set_priority(this->data[i].get_priority());
            } catch (const char *msg) {
                std::cout << msg;
            }
            cnt++;
        }
        auto *ptr = new dinamic_array<T>(buff, j - k + 1);
        return ptr;
    } else {
        throw "Index out of range";
    }
}

template<typename T>
dinamic_array<T>::dinamic_array(dinamic_array const &a) {
    try {
        this->data = a.get_data();
        this->size = a.get_size();
    } catch (const char *msg) {
        std::cout << msg;
    }

}

template<typename T>
dinamic_array<T>::dinamic_array(option<T> *el, int count) {
    this->data = el;
    this->size = count;
}


template<typename T>
option<T> *dinamic_array<T>::get_data() const {
    return this->data;
}

/*template<typename T>
int dinamic_array<T>::get_max_pr() {
    int max_pr = -1;
    for (int i = 0; i < this->size; i++) {
        if (this->data[i].get_priority() > max_pr) {
            max_pr = this->data[i].get_priority();
        }
    }
    return max_pr;
}*/


template<typename T>
void dinamic_array<T>::set_el(option<T> el, int index) {
    this->data[index] = el;
}

template<typename T>
bool dinamic_array<T>::operator==(const dinamic_array &right) {
    if (this->size == right.get_size()) {
        for (int i = 0; i < this->size; i++) {
            if (not(this->data[i] == right.get_el(i))) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename T>
void dinamic_array<T>::concat(const dinamic_array &a) {
    for (int i = 0; i < a.get_size(); i++) {
        this->data[this->size - 1 + i] = a.get_el(i);
    }
    this->size += a.get_size();
}

template<typename T>
bool dinamic_array<T>::try_has_data() {
    return has_data;
}

template<typename T>
void dinamic_array<T>::set_size(int val) {
    this->size = val;
}

template<typename T>
dinamic_array<T>::dinamic_array(int size) {
    this->data = new option<T>(size);
    this->size = size;
}


template<typename T>
dinamic_array<T>::~dinamic_array() = default;


#endif //LAB2_2_DINAMIC_ARRAY_HPP
