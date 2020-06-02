#ifndef LAB2_2_QUEUE_HPP
#define LAB2_2_QUEUE_HPP

#include "sequence.hpp"
#include "array_sequence.hpp"
#include <iostream>

template<typename T>
class queue {
private:
    sequence<T> *data;
    //int max_prirority{};
    int size{};
public:
    queue();

    explicit queue(sequence<T> *);

    explicit queue(queue<T> *);

    ~queue();

    void push(option<T>);

    void print();

    int get_size() const;

    //int get_max_priority();

    sequence<T> *get_data() const;

    queue<T> *merge(queue<T> *);

    void add(queue<T> *);

    queue<T> *get_index_queue(int, int);

    queue<T> *separation(bool f(option<T>));

    queue<T> *map(option<T> (f)(option<T>));

    option<T> reduce(option<T> (f)(option<T>, option<T>), option<T>);

    queue<T> *where(bool f(option<T>));

    option<T> get_first();

    bool operator==(const queue &right);

};

template<typename T>
queue<T>::queue() {
    this->data = new array_sequence<T>();
    this->size = 0;
    //this->max_prirority = -1;
}

template<typename T>
queue<T>::queue(sequence<T> *other) {
    this->data = new array_sequence<T>();
    for (int i = 0; i < other->get_size(); i++) {
        push(other->get_el(i));
    }
    this->size = other->get_size();
}


template<typename T>
sequence<T> *queue<T>::get_data() const {
    return this->data;
}

template<typename T>
void queue<T>::push(option<T> el) {
   /* if (el.get_priority() > this->max_prirority) {
        this->data->append(el);
        this->max_prirority = el.get_priority();
        this->size++;
    } else {
        int j = 0;
        for (int i = 0; i < this->size; i++) {
            if ((this->data->get_el(i).get_priority() >= el.get_priority())) {
                break;
            }
            j++;
        }
        this->data->insert_el(el, j);
        this->size++;
    }*/
   this->data->append(el);
   this->size++;
}

template<typename T>
void queue<T>::print() {
    this->data->print();
}


template<typename T>
queue<T> *queue<T>::merge(queue<T> *other) {
    auto *ptr = new queue<T>(this->data);
    for (int i = 0; i < other->get_size(); i++) {
        ptr->push(other->get_data()->get_el(i));
    }
    return ptr;
}

template<typename T>
int queue<T>::get_size() const {
    return this->size;
}

template<typename T>
void queue<T>::add(queue<T> *other) {
    queue<T> buff(this->data);
    for (int i = 0; i < other->get_size(); i++) {
        buff.push(other->get_data().get_el(i));
    }
    this->data = buff.get_data();
    this->size = buff.get_size();
}


template<typename T>
queue<T> *queue<T>::get_index_queue(int i, int j) {
    auto *ptr = new queue<T>(this->data->get_index_data(i, j));
    return ptr;
}


template<typename T>
queue<T> *queue<T>::map(option<T> (*f)(option<T>)) {
    auto *ptr = new queue<T>();
    for (int i = 0; i < this->size; i++) {
        ptr->push(f(this->data->get_el(i)));
    }
    return ptr;
}

template<typename T>
queue<T> *queue<T>::where(bool (*f)(option<T>)) {
    auto *ptr = new queue<T>;
    for (int i = 0; i < this->size; i++) {
        if (f(this->data->get_el(i))) {
            ptr->push(this->data->get_el(i));
        }
    }
    return ptr;
}

template<typename T>
queue<T> *queue<T>::separation(bool (*f)(option<T>)) {
    auto *buff = new queue<T>[2];
    for (int i = 0; i < this->size; i++) {
        if (f(this->data->get_el(i))) {
            buff[0].push(this->data->get_el(i));
        } else {
            buff[1].push(this->data->get_el(i));
        }
    }
    return buff;
}


template<typename T>
bool queue<T>::operator==(const queue &right) {
    return *this->data == right.get_data();
}

template<typename T>
option<T> queue<T>::reduce(option<T> (*f)(option<T>, option<T>), option<T> el) {
    option<T> answer(f(this->data->get_el(0), el));
    for (int i = 1; i < this->size; i++) {
        answer.set_value(f(this->data->get_el(i), answer).get_value());
    }
    return answer;
}

template<typename T>
queue<T>::queue(queue<T> *other) {
    this->data = other->get_data();
    this->size = other->get_size();
    //this->max_prirority = other->max_prirority;
}

template<typename T>
option<T> queue<T>::get_first() {
    return this->data->get_first();
}


/*template<typename T>
int queue<T>::get_max_priority() {
    return this->max_prirority;
}*/

template<typename T>
queue<T>::~queue() = default;

#endif //LAB2_2_QUEUE_HPP
