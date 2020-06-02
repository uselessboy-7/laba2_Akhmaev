#include <iostream>
#include <string>
#include "queue.hpp"
#include "test_queue.hpp"
#include "student.hpp"
#include "test_list.hpp"
#include "interface.hpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << '\n';
    ///// STUDENT
    cout << "STUDENT EXAMPLE "<< endl;
    student number_1(12, 14);
    option<student> student_1(number_1);
    student number_2(10, 13);
    option<student> student_2(number_2);
    queue<student> test;
    test.push(student_1);
    test.push(student_2);
    test.print();
    cout << '\n';
    std::cout << '\n';
    cout << "TESTS OF QUEUE" << endl;
    //// TESTS Q
    reduce_test<int> reduce_test;
    std::cout << "reduce test: ";
    reduce_test.test();
    std::cout << '\n';
    map_test<int> map_test;
    std::cout << "map test: ";
    map_test.test();
    std::cout << '\n';
    where_test<int> where_test;
    std::cout << "where test: ";
    where_test.test();
    std::cout << '\n';
    queue_index_test<int> queue_index_test;
    std::cout << "get index queue test: ";
    queue_index_test.test();
    std::cout << '\n';
    separation_test<int> separation_test;
    std::cout << "separation test: ";
    separation_test.test();
    std::cout << '\n';
    merge_test<int> merge_test;
    std::cout << "merge test: ";
    merge_test.test();
    std::cout << '\n';
    /*queue<int> test_merge;
    queue<int> test_merge_1;
    for(int i = 0; i < 4; i++){
        option<int>el(i,i+1);
        option<int>el1(2*i,2*(i+1));
        test_merge.push(el);
        test_merge_1.push(el1);
    }
    queue<int>answer(test_merge.merge(test_merge_1));
    answer.print();*/
//// TESTS ARR
    cout << '\n';
    cout << "TEST OF LIST" << endl;
    set_test<int> set_test;
    std::cout << "set test: ";
    set_test.test();
    std::cout << '\n';
    get_test<int> get_test;
    std::cout << "get test: ";
    get_test.test();
    std::cout << '\n';
    insert_test<int> insert_test;
    std::cout << "insert test: ";
    insert_test.test();
    std::cout << '\n';
    get_index_arr_test<int> get_index_arr_test;
    std::cout << "get index arr test: ";
    get_index_arr_test.test();
    std::cout << '\n';
    concat_test<int> concat_test;
    std::cout << "concat test: ";
    concat_test.test();
    std::cout << '\n';
    /*queue<string> first;
    for (int i = 0; i < 4; i++) {
        option<string> el(std::to_string(i));
        first.push(el);
    }
    cout <<  first.get_first().get_value();*/
    char c;
    cout << "Choose the type of q : 'i' for integer; 'f' for float  ";
    cin >> c;

    switch (c) {
        case 'i': {
            run_interface<int>();
            break;
        }
        case 'f': {
            run_interface<float>();
            break;
        }
    }
    return 0;
}
