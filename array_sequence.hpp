#ifndef LAB2_2_ARRAY_SEQUENCE_HPP
#define LAB2_2_ARRAY_SEQUENCE_HPP

#include "sequence.hpp"
#include "dinamic_array.hpp"

template<typename T>
class array_sequence : public sequence<T> {
private:
    dinamic_array<T> *data;
    int size{};
public:
    array_sequence();

    array_sequence(option<T> *data, int size);

    explicit array_sequence(dinamic_array<T> *data);

    explicit array_sequence(sequence<T> *);

    array_sequence(const array_sequence<T> &other);

    dinamic_array<T> *get_data() const;

    int get_size() const override;

    void print() override;

    void append(option<T>) override;

    void prepend(option<T>) override;

    void set_el(option<T>, int) override;

    option<T> get_el(int) override;

    void insert_el(option<T>, int) override;

    option<T> get_last() override;

    option<T> get_first() override;

    sequence<T> *get_index_data(int, int) override;

    void concat(sequence<T> *) override;

    bool operator==(sequence<T> *right);

    ~array_sequence();
};

template<typename T>
array_sequence<T>::array_sequence() {
    this->data = new dinamic_array<T>();
    this->size = 0;
}

template<typename T>
array_sequence<T>::array_sequence(option<T> *data, int size) {
    this->data = new dinamic_array<T>(data, size);
    this->size = size;
}

template<typename T>
array_sequence<T>::array_sequence(dinamic_array<T> *data) {
    this->data = data;
    this->size = data->get_size();
}

template<typename T>
array_sequence<T>::array_sequence(const array_sequence<T> &other) {
    this->data = other.get_data();
    this->size = other.get_size();
}

template<typename T>
dinamic_array<T> *array_sequence<T>::get_data() const {
    return this->data;
}

template<typename T>
int array_sequence<T>::get_size() const {
    return this->size;
}

template<typename T>
void array_sequence<T>::print() {
    this->data->print();
}

template<typename T>
void array_sequence<T>::append(option<T> el) {
    this->data->append(el);
    this->size++;
}

template<typename T>
void array_sequence<T>::prepend(option<T> el) {
    this->data->prepend(el);
    this->size++;
}

template<typename T>
void array_sequence<T>::set_el(option<T> el, int index) {
    this->data->set_el(el, index);
}

template<typename T>
option<T> array_sequence<T>::get_el(int index) {
    return this->data->get_el(index);
}

template<typename T>
void array_sequence<T>::insert_el(option<T> el, int index) {
    this->data->insert_el(el, index);
    this->size++;
}

template<typename T>
option<T> array_sequence<T>::get_last() {
    return this->data->get_el(this->size-1);
}

template<typename T>
option<T> array_sequence<T>::get_first() {
    return this->data->get_el(0);
}

template<typename T>
sequence<T> *array_sequence<T>::get_index_data(int start_index, int end_index) {
    auto *ptr = new array_sequence<T>(this->data->get_index_data(start_index, end_index));
    return ptr;
}

template<typename T>
void array_sequence<T>::concat(sequence<T> *other) {
    for(int i = 0; i < other->get_size(); i++){
        append(other->get_el(i));
    }
}

template<typename T>
bool array_sequence<T>::operator==(sequence<T> *right) {
   if (this->size == right->get_size()){
       for(int i = 0; i < this->size; i++){
           return !(get_el(i) != right->get_el(i));
       }
   }else{
       throw "Can't compare";
   }
}

template<typename T>
array_sequence<T>::array_sequence(sequence<T> *other) {
    this->data = new dinamic_array<T>();
    for(int i = 0; i < other->get_size(); i++){
        append(other->get_el(i));
    }
    this->size = other->get_size();
}


template<typename T>
array_sequence<T>::~array_sequence() = default;

#endif //LAB2_2_ARRAY_SEQUENCE_HPP
