#ifndef LAB2_2_LINKED_LIST_HPP
#define LAB2_2_LINKED_LIST_HPP

#include <iostream>
#include "options.hpp"


template<typename T>
class linked_list {
private:
    struct Node {
        Node() : n_next(nullptr) {}

        explicit Node(option<T> t) : data(t), n_next(nullptr) {}

        option<T> data;
        Node *n_next;
    };

    Node *head;
    Node *end;
    int size{};
public:
    linked_list() : head(nullptr), end(nullptr), size(0) {};

    linked_list(Node *head, Node *end, int size) : head(head), end(end), size(size) {};

    linked_list(option<T> *, int);

    linked_list(const linked_list &a);

    ~linked_list();

    void append(option<T>);

    void prepend(option<T>);

    void remove();

    void print();

    bool has_el(option<T>);

    bool is_empty();

    option<T> get_last() const;

    option<T> get_first() const;

    option<T> get_el(int) const;

    void set_el(option<T>, int);

    void insert_el(option<T>, int);

    linked_list<T> get_index_data(int, int);

    void concat(const linked_list &a);

    int get_size() const;
};

template<typename T>
linked_list<T>::~linked_list() = default;

template<typename T>
void linked_list<T>::prepend(option<T> el) {
    if (Node *node = new Node(el)) {
        if (head) {
            node->n_next = head;
            head = node;
            size++;
        } else {
            node->n_next = head;
            head = node;
            end = node;
            size++;
        }
    }
}


template<typename T>
void linked_list<T>::append(option<T> el) {
    if (Node *node = new Node(el)) {
        if (head) {
            end->n_next = node;
            end = node;
            size++;
        } else {
            node->n_next = head;
            head = node;
            end = node;
            size++;
        }
    }
}

template<typename T>
void linked_list<T>::remove() {
    if (head) {
        Node *new_head = head->n_next;
        delete head;
        head = new_head;
    } else {
        throw "Remove from empty linked_list";
    }
}

template<typename T>
void linked_list<T>::print() {
    Node *el_pointer = head;
    while (el_pointer) {
        option<T> el = el_pointer->data;
        std::cout << "val: " << el.get_value() <<  "\t";
        el_pointer = el_pointer->n_next;
    }
}


template<typename T>
int linked_list<T>::get_size() const {
    return size;
}

template<typename T>
bool linked_list<T>::has_el(option<T> el) {
    Node *el_pointer = head;
    while (el_pointer) {
        option<T> c_el = el_pointer->data;
        if (c_el.get_value() == el.get_value()) {
            return true;
        }
        el_pointer = el_pointer->n_next;
    }
    return false;
}

template<typename T>
bool linked_list<T>::is_empty() {
    return not head;
}

template<typename T>
linked_list<T>::linked_list(option<T> *items, int count) {
    if (Node *node_f = new Node(items[0])) {
        head = node_f;
    }
    if (Node *node_l = new Node(items[count - 1])) {
        end = node_l;
    }
    for (int i = 0; i < count - 1; i++) {
        Node *node = new Node(items[i]);
        Node *next_node = new Node(items[i + 1]);
        node->n_next = next_node;
    }
    end->n_next = nullptr;
}

template<typename T>
option<T> linked_list<T>::get_last() const{
    option<T> el = end->data;
    return el;
}

template<typename T>
option<T> linked_list<T>::get_first() const{
    option<T> el = head->data;
    return el;
}

template<typename T>
option<T> linked_list<T>::get_el(int index) const{
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index; i++) {
            el_pointer = el_pointer->n_next;
        }
        return el_pointer->data;
    } else {
        throw "Index out of range";
    }
}

template<typename T>
void linked_list<T>::insert_el(option<T> el, int index) {
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index - 1; i++) {
            el_pointer = el_pointer->n_next;
        }
        if (Node *node = new Node(el)) {
            node->n_next = el_pointer->n_next;
            el_pointer->n_next = node;
            size++;
        }
    } else {
        throw "Index out of range";
    }
}

template<typename T>
linked_list<T> linked_list<T>::get_index_data(int k, int j) {
    if (k >= 0 && j >= 0 && k <= size - 1 && j <= size - 1) {
        linked_list<T> buff;
        for(int i = k; i <= j; i++){
            buff.append(this->get_el(i));
        }
        return buff;
    } else {
        throw "Index out of range";
    }
}

template<typename T>
linked_list<T>::linked_list(const linked_list &a) {
    this->head = nullptr;
    this->end = nullptr;
    this->size = 0;
    for(int i = 0; i < a.get_size(); i++){
        if (Node *node = new Node(a.get_el(i))) {
            if (this->head) {
                this->end->n_next = node;
                this->end = node;
                this->size++;
            } else {
                node->n_next = this->head;
                this->head = node;
                this->end = node;
                this->size++;
            }
        }
    }
}

template<typename T>
void linked_list<T>::concat(const linked_list &a) {
    end->n_next = *a.get_first();
    end = *a.get_last();
}

template<typename T>
void linked_list<T>::set_el(option<T> el, int index) {
    if (index <= size - 1 && index >= 0) {
        Node *el_pointer = head;
        for (int i = 0; i < index; i++) {
            el_pointer = el_pointer->n_next;
        }
        if(Node *node = new Node(el)){
            node->n_next = el_pointer->n_next;
            el_pointer = node;
        }
    } else {
        throw "Index out of range";
    }
}


#endif //LAB2_2_LINKED_LIST_HPP
