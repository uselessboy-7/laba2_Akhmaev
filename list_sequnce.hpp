#ifndef LAB2_2_LIST_SEQUNCE_HPP
#define LAB2_2_LIST_SEQUNCE_HPP

#include "sequence.hpp"
#include "linked_list.hpp"

template<typename T>
class list_sequence : public sequence<T> {
private:
    linked_list<T> *data;
    int size{};
public:
    list_sequence();

    list_sequence(option<T> *data, int size);

    explicit list_sequence(sequence<T> *);

    explicit list_sequence(linked_list<T> *data);

    list_sequence(const list_sequence<T> &other);

    linked_list<T> * get_data() const;

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

    ~list_sequence();
};

template<typename T>
list_sequence<T>::list_sequence() {
    this->data = new linked_list<T>();
    this->size = 0;
}

template<typename T>
list_sequence<T>::list_sequence(option<T> *data, int size) {
    this->data = new linked_list<T>(data, size);
    this->size = size;
}

template<typename T>
list_sequence<T>::list_sequence(linked_list<T> *data) {
    this->data = data;
    this->size = data->get_size();
}

template<typename T>
list_sequence<T>::list_sequence(const list_sequence<T> &other) {
    this->data = other.get_data();
    this->size = other.get_size();
}

template<typename T>
list_sequence<T>::list_sequence(sequence<T> *other) {
    this->data = new linked_list<T>();
    for(int i = 0; i < other->get_size(); i++){
        this->append(other->get_el(i));
    }
    this->size = other->get_size();
}


template<typename T>
linked_list<T> *list_sequence<T>::get_data() const {
    return this->data;
}

template<typename T>
int list_sequence<T>::get_size() const {
    return this->size;
}

template<typename T>
void list_sequence<T>::print() {
    this->data->print();
}

template<typename T>
void list_sequence<T>::append(option<T> el) {
    this->data->append(el);
    this->size++;
}

template<typename T>
void list_sequence<T>::prepend(option<T> el) {
    this->data->prepend(el);
    this->size++;
}

template<typename T>
void list_sequence<T>::set_el(option<T> el, int index) {
    this->data->set_el(el, index);
}

template<typename T>
option<T> list_sequence<T>::get_el(int index) {
    return this->data->get_el(index);
}

template<typename T>
void list_sequence<T>::insert_el(option<T> el, int index) {
    this->data->insert_el(el, index);
    this->size++;
}

template<typename T>
option<T> list_sequence<T>::get_last() {
    return this->data->get_el(this->size - 1);
}

template<typename T>
option<T> list_sequence<T>::get_first() {
    return this->data->get_el(0);
}

template<typename T>
sequence<T> *list_sequence<T>::get_index_data(int start_index, int end_index) {
    auto *ptr_linked_list = new linked_list<T>(this->data->get_index_data(start_index, end_index));
    auto *ptr = new list_sequence<T>(ptr_linked_list);
    //auto *ptr = new list_sequence<T>(this->data->get_index_data(start_index, end_index));
    return ptr;
}

template<typename T>
void list_sequence<T>::concat(sequence<T> *other) {
    for (int i = 0; i < other->get_size(); i++) {
        this->append(other->get_el(i));
    }
}

template<typename T>
bool list_sequence<T>::operator==(sequence<T> *right) {
    if (this->size == right->get_size()){
        for(int i = 0; i < this->size; i++){
            return !(get_el(i) != right->get_el(i));
        }
    }else{
        throw "Can't compare";
    }
}


template<typename T>
list_sequence<T>::~list_sequence() = default;


#endif //LAB2_2_LIST_SEQUNCE_HPP
