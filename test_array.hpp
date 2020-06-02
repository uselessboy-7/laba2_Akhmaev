#ifndef LAB2_2_TEST_ARRAY_HPP
#define LAB2_2_TEST_ARRAY_HPP

#include "array_sequence.hpp"

template<typename T>
class set_test {
private:
    array_sequence<T> first;
    array_sequence<T> second;
public:
    set_test() : first(), second() {};

    void test();

    ~set_test();
};

template<typename T>
void set_test<T>::test() {
    option<int> test_el(10);
    for (int i = 0; i < 2; i++) {
        option<T> el(i);
        first.append(el);
    }
    first.append(test_el);
    for (int i = 3; i < 4; i++) {
        option<T> el(i);
        first.append(el);
    }
    for (int i = 0; i < 4; i++) {
        option<T> el(i);
        second.append(el);
    }
    second.set_el(test_el, 2);
    if (first == &second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}


template<typename T>
class get_test {
private:
    array_sequence<T> first;
    option<T> second;
public:
    get_test() : first(), second() {};

    void test();

    ~get_test();
};

template<typename T>
void get_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<T> el(i);
        first.append(el);
    }
    //second.set_priority(3);
    second.set_value(2);
    if (second == first.get_el(2)) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }

}

template<typename T>
class insert_test {
private:
    array_sequence<T> first;
    array_sequence<T> second;
public:
    insert_test() : first(), second() {};

    void test();

    ~insert_test();
};


template<typename T>
void insert_test<T>::test() {
    option<int> test_el(10);

    for (int i = 0; i < 2; i++) {
        option<T> el(i);
        first.append(el);
    }
    first.append(test_el);
    for (int i = 3; i < 4; i++) {
        option<T> el(i);
        first.append(el);
    }

    for (int i = 0; i < 2; i++) {
        option<T> el(i);
        second.append(el);
    }
    for (int i = 3; i < 4; i++) {
        option<T> el(i);
        second.append(el);
    }
    second.insert_el(test_el, 2);
    if (first == &second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}


template<typename T>
class get_index_arr_test {
private:
    array_sequence<T> first;
    array_sequence<T> second;
public:
    get_index_arr_test() : first(), second() {};

    void test();

    ~get_index_arr_test();
};

template<typename T>
void get_index_arr_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<T> el(i);
        first.append(el);
    }
    for (int i = 1; i < 3; i++) {
        option<T> el(i);
        second.append(el);
    }
    array_sequence<T> answer(first.get_index_data(1, 2));
    if (answer == &second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
class concat_test {
private:
    array_sequence<T> first;
    array_sequence<T> second;
public:
    concat_test() : first(), second() {};

    void test();

    ~concat_test();
};

template<typename T>
void concat_test<T>::test() {
    array_sequence<T> buff;
    for (int i = 0; i < 2; i++) {
        option<T> el(i);
        first.append(el);
    }
    for (int i = 0; i < 4; i++) {
        option<T> el(i);
        second.append(el);
    }
    for (int i = 2; i < 4; i++) {
        option<T> el(i);
        buff.append(el);
    }
    first.concat(&buff);
    if (first == &second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
concat_test<T>::~concat_test() = default;

template<typename T>
get_index_arr_test<T>::~get_index_arr_test() = default;


template<typename T>
insert_test<T>::~insert_test() = default;

template<typename T>
get_test<T>::~get_test() = default;


template<typename T>
set_test<T>::~set_test() = default;


#endif //LAB2_2_TEST_ARRAY_HPP
