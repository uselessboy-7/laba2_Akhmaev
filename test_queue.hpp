#ifndef LAB2_2_TEST_QUEUE_HPP
#define LAB2_2_TEST_QUEUE_HPP

#include "queue.hpp"


template<typename T>
option<T> map_foo(option<T> el) {
    auto buff = el.get_value() * 5;
    el.set_value(buff);
    return el;
}

template<typename T>
option<T> reduce_foo(option<T> el, option<T> el1) {
    option<T> buff(2 * el.get_value() + 3 * el1.get_value());
    return buff;
}

template<typename T>
bool where_foo(option<T> el) {
    return el.get_value() >= 2;
}

template<typename T>
bool separation_foo(option<T> el) {
    return el.get_value() > 2;
}


template<typename T>
class map_test {
private:
    queue<T> first;
    queue<T> second;
public:
    map_test() : first(), second() {};

    ~map_test();

    void test();
};

template<typename T>
void map_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<int> el(i);
        option<int> el1(i * 5);
        first.push(el);
        second.push(el1);
    }
    option<int> (*foo_map_ptr)(option<int>) = map_foo;
    auto *ptr = first.map(*foo_map_ptr);
    queue<T> answer(ptr);
    if (answer == second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
map_test<T>::~map_test() = default;


template<typename T>
class reduce_test {
private:
    queue<T> data;
public:
    reduce_test() : data() {};

    ~reduce_test();

    void test();
};

template<typename T>
void reduce_test<T>::test() {
    int right_answer = 144;
    for (int i = 0; i < 3; i++) {
        option<int> el(i + 1);
        data.push(el);
    }
    option<T> test_value(4);
    option<int> (*foo_reduce_ptr)(option<int>, option<int>) = reduce_foo;
    option<T> answer = data.reduce(*foo_reduce_ptr, test_value);
    if (answer.get_value() == right_answer) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
reduce_test<T>::~reduce_test() = default;


template<typename T>
class queue_index_test {
private:
    queue<T> first;
    queue<T> second;
public:
    queue_index_test() : first(), second() {};

    ~queue_index_test();

    void test();
};

template<typename T>
void queue_index_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<int> el(i);
        first.push(el);
    }
    for (int i = 1; i < 3; i++) {
        option<int> el(i);
        second.push(el);
    }
    queue<T> answer(first.get_index_queue(1, 2));
    if (answer == second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
queue_index_test<T>::~queue_index_test() = default;


template<typename T>
class where_test {
private:
    queue<T> first;
    queue<T> second;
public:
    where_test() : first(), second() {};

    ~where_test();

    void test();
};

template<typename T>
void where_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<int> el(i);
        first.push(el);
    }
    for (int i = 2; i < 4; i++) {
        option<int> el(i);
        second.push(el);
    }
    bool (*foo_where_ptr)(option<int>) = where_foo;
    queue<T> answer(first.where(*foo_where_ptr));
    if (answer == second) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
where_test<T>::~where_test() = default;


template<typename T>
class separation_test {
private:
    queue<T> first;
    queue<T> *second;
    queue<T> *test_mas;
public:
    separation_test() {
        first;
        second = new queue<T>[2];
        test_mas = new queue<T>[2];
    };

    ~separation_test();

    void test();
};

template<typename T>
void separation_test<T>::test() {
    for (int i = 0; i < 4; i++) {
        option<int> el(i);
        first.push(el);
    }
    for (int i = 0; i < 3; i++) {
        option<int> el(i);
        second[1].push(el);
    }
    for (int i = 3; i < 4; i++) {
        option<int> el(i);
        second[0].push(el);
    }
    bool (*foo_separation_test)(option<int>) = separation_foo;
    test_mas = first.separation(*foo_separation_test);
    if (test_mas[0] == second[0] && test_mas[1] == second[1]) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}

template<typename T>
separation_test<T>::~separation_test() = default;


template<typename T>
class merge_test {
private:
    queue<T> first;
    queue<T> second;
    queue<T> test_q;
public:
    merge_test() : first(), second(), test_q() {};

    ~merge_test();

    void test();
};

template<typename T>
merge_test<T>::~merge_test() = default;

template<typename T>
void merge_test<T>::test() {
    for (int i = 0; i < 2; i++) {
        option<int> el(i);
        first.push(el);
    }
    for (int i = 2; i < 4; i++) {
        option<int> el(i);
        second.push(el);
    }
    for (int i = 0; i < 4; i++) {
        option<int> el(i);
        test_q.push(el);
    }
    queue<T> answer(first.merge(&second));
    if (test_q == answer) {
        std::cout << "Test pass";
    } else {
        std::cout << "Test faild";
    }
}


#endif //LAB2_2_TEST_QUEUE_HPP
