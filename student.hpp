#ifndef LAB2_2_STUDENT_HPP
#define LAB2_2_STUDENT_HPP

#include <iostream>
#include <string>

typedef struct person_id {
    int main_id;
    int local_id;

    explicit person_id() : main_id(0), local_id(0) {};

    explicit person_id(int m, int l) : main_id(m), local_id(l) {};

    void set_id(int m, int l) {
        main_id = m;
        local_id = l;
    };

    int * get_id() const {
        int *buff = new int[2];
        buff[0] = main_id;
        buff[1] = local_id;
        return buff;
    };
} person_id;


class student {
private:
    char *first_name;
    char *middle_name;
    char *last_name;
    person_id id;
public:
    explicit student() : first_name(nullptr), middle_name(nullptr), last_name(nullptr), id() {}

    explicit student(int m_i, int l_i) : first_name(nullptr), middle_name(nullptr), last_name(nullptr), id(m_i, l_i) {}

    explicit student(char *f_n, char *m_n, char *l_n, int m_i, int l_i) : first_name(f_n), middle_name(m_n),
                                                                          last_name(l_n), id(m_i, l_i) {}

    explicit student(char *f_n, char *l_n, int m_i, int l_i) : first_name(f_n), middle_name(nullptr), last_name(l_n),
                                                               id(m_i, l_i) {}

    void set_name(char *, char *, char *);

    void set_name(char *, char *);

    char *get_name();

    void *set_index(int, int);

    int *get_index() const;

    friend std::ostream& operator<< (std::ostream &out, const student &student);

    bool operator!=(const student &right);

    student& operator=(int val);

};


void student::set_name(char *f, char *m, char *l) {
    first_name = f;
    middle_name = m;
    last_name = l;
}


void student::set_name(char *f, char *l) {
    first_name = f;
    last_name = l;
}

char *student::get_name() {
    char *buff = new char[3];
    if (middle_name) {
        try {
            buff[0] = *first_name;
            buff[1] = *middle_name;
            buff[2] = *last_name;
        } catch (const char *msg) {
            std::cout << msg;
        }
    } else {
        char m_n(' ');
        buff[0] = *first_name;
        buff[1] = m_n;
        buff[2] = *last_name;
    }
    return buff;
}

void *student::set_index(int m_i, int l_i) {
    id.set_id(m_i, l_i);
}


int *student::get_index() const {
    return id.get_id();
}

std::ostream &operator<<(std::ostream &out, const student &student) {
    int *buff = student.get_index();
    if (student.first_name && student.last_name && student.middle_name) {
        out << "Student " << " id : " << buff[0] << " " << buff[1] << " name : " << student.first_name
            << student.middle_name << student.last_name;
    } else if (student.first_name && student.last_name){
        out << "Student " << " id : " << buff[0] << " " << buff[1] << " name : " << student.first_name
            << student.last_name;
    }
    else{
        out << "Student " << " id : " << buff[0] << " " << buff[1];
    }
    return out;
}

student &student::operator=(int val) {
    if (val == 0){
        first_name = nullptr;
        middle_name = nullptr;
        last_name = nullptr;
        id.set_id(0,0);
    }
    return *this;
}

bool student::operator!=(const student &right) {
    return id.get_id() != right.get_index();
}


#endif //LAB2_2_STUDENT_HPP
