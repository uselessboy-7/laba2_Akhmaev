#include <iostream>
#include "test_queue.hpp"

using namespace std;

template <typename T>
void run_interface(){
    cout << "\nTest results you can see above\n";
    cout << "Interface for integer or float\n";
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    queue<T> q;
    for (int i = 0; i < size; i++){
        T data;
        cout << "Enter element : ";
        cin >> data;
        option<T>el(data);
        q.push(el);
    }
    int type;
    int check = 0;
    while(check == 0) {
        cout
                << "\nWhat type of functions do you want to use ?\n 1: Map\n 2: Where\n 3: Reduce\n 4: Get index data\n 5: Separation\n 6: Merge\n 7: Get first element\n 8: Quit\n";

        cin >> type;
        switch (type) {
            case 1:{
                option<T> (*foo_map_ptr)(option<T>) = map_foo;
                auto *ptr = q.map(*foo_map_ptr);
                queue<T> answer(ptr);
                answer.print();
                break;
            }
            case 2:{
                bool (*foo_where_ptr)(option<T>) = where_foo;
                queue<T> answer(q.where(*foo_where_ptr));
                answer.print();
                break;
            }
            case 3:{
                cout << "Enter element for reduce: ";
                int red;
                cin >> red;
                option<T>red_el(red);
                option<T> (*foo_reduce_ptr)(option<T>, option<T>) = reduce_foo;
                option<T> answer = q.reduce(*foo_reduce_ptr,red_el);
                cout << answer.get_value();
                break;
            }
            case 4:{
                cout << "Enter indexes : ";
                int first, second;
                cout << "\nFirst index: ";
                cin >> first;
                cout << "Second index: ";
                cin >> second;
                queue<T> answer(q.get_index_queue(first, second));
                answer.print();
                break;
            }
            case 5:{
                bool (*foo_separation_test)(option<T>) = separation_foo;
                auto arr = q.separation(*foo_separation_test);
                cout << "\nFirst:\n";
                arr[0].print();
                cout << "\nSecond:\n";
                arr[1].print();
                break;
            }
            case 6:{
                cout << "Enter size of  second queue: ";
                cin >> size;
                queue<T> q1;
                for (int i = 0; i < size; i++){
                    T data;
                    cout << "Enter element : ";
                    cin >> data;
                    option<T>el(data);
                    q1.push(el);
                }
                queue<T> answer(q.merge(&q1));
                answer.print();
                break;
            }
            case 7:{
                cout << q.get_first().get_value();
                break;
            }
            case 8:
                check = 1;
                break;
        }
    }
};

