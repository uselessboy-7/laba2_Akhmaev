#ifndef LAB2_2_OPTIONS_HPP
#define LAB2_2_OPTIONS_HPP

template<typename T>
class option {
private:
    T data;
    //int priority;
    bool has_value = false;

public:
    //explicit option(T value, int pr) : data(value), priority(pr), has_value(true) {};
    explicit option(T value) : data(value), has_value(true) {};

    option();


    //explicit option(T);

    ~option();

    //bool has_priority() const;

    bool it_has_value() const;

    T get_value() const;

    //int get_priority() const;

    void set_value(T);

    //void set_priority(int);

    bool operator==(const option &right);

    bool operator!=(const option &right);

};

template<typename T>
option<T>::~option() = default;


template<typename T>
T option<T>::get_value() const {
    if (has_value) {
        return data;
    } else {
        throw "Has no data option";
    }
}

template<typename T>
void option<T>::set_value(T value) {
    data = value;
}

template<typename T>
option<T>::option() {
    //data = 0;
    //priority = 0;
    has_value = true;
}

/*template<typename T>
option<T>::option(T value) {
    data = value;
    //priority = 0;
    has_value = true;
}*/

/*template<typename T>
int option<T>::get_priority() const {
    if (has_priority()) {
        return priority;
    } else {
        throw "Has no priority";
    }
}

template<typename T>
void option<T>::set_priority(int pr) {
    priority = pr;
}

template<typename T>
bool option<T>::has_priority() const {
    return priority >= 0;
}*/


template<typename T>
bool option<T>::it_has_value() const {
    return has_value;
}

template<typename T>
bool option<T>::operator==(const option &right) {
    if (has_value && right.it_has_value()) {
        return data == right.get_value();
    } else {
        throw "Can't compare options";
    }
}

template<typename T>
bool option<T>::operator!=(const option &right) {
    if (has_value && right.it_has_value()) {
        return data != right.get_value();
    } else {
        throw "Can't compare options";
    };
}

#endif //LAB2_2_OPTIONS_HPP
