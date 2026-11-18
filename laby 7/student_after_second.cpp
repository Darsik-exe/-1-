#include "student_after_second.h"

student_after_second::student_after_second (const std::string& name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade, std::vector<int>& second_grade) : student_after_first (name, year, group, passbook, first_grade) {
    this -> second_grade = second_grade;

    sum_second = 0;
    sum_all = get_sum_first();
    for (auto x : second_grade) {
        sum_second += x;
        sum_all += x;
    }

    type = 2;
}

student_after_second::student_after_second (char* name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade, std::vector<int>& second_grade) : student_after_first (name, year, group, passbook, first_grade) {
    this -> second_grade = second_grade;

    sum_second = 0;
    sum_all = get_sum_first();
    for (auto x : second_grade) {
        sum_second += x;
        sum_all += x;
    }

    type = 2;
}

student_after_second::student_after_second (const basic_student_class& student, std::vector<int>& first_grade, std::vector<int>& second_grade) : student_after_first (student, first_grade) {
    this -> second_grade = second_grade;

    sum_second = 0;
    sum_all = get_sum_first();
    for (auto x : second_grade) {
        sum_second += x;
        sum_all += x;
    }

    type = 2;
}

student_after_second::student_after_second (const student_after_first& student, std::vector<int>& second_grade) : student_after_first (student) {
    this -> second_grade = second_grade;

    sum_second = 0;
    sum_all = get_sum_first();
    for (auto x : second_grade) {
        sum_second += x;
        sum_all += x;
    }

    type = 2;
}

student_after_second::student_after_second (const student_after_second& student) : student_after_first (student) {
    second_grade = student.get_full_second_grade();

    sum_second = student.get_sum_first();
    sum_all = get_sum_first();

    type = 2;
}

std::string student_after_second::print() {
    std::stringstream out;

    //std::cout << "second frist\n";
    out << student_after_first::print();
    //std::cout << "second second\n";
    
    out << "Grade after second: ";
    for (const auto& x : second_grade) {
        out << x << ' ';
    }
    out << '\n';

    return out.str();   
}

int student_after_second::get_sum_second() const {
    return sum_second;
}

int student_after_second::get_sum_all() const {
    return sum_all;
}

int student_after_second::get_second_grade(const int& ind) const {
    return second_grade[ind];
}

std::vector<int> student_after_second::get_full_second_grade() const {
    return second_grade;
}

void student_after_second::fixed_second_grade(const int& ind, const int& x) {
    second_grade[ind] = x;
}

void student_after_second::fixed_all_second_grade(const std::vector<int> new_second_grade) {
    second_grade = new_second_grade;
}

double student_after_second::get_mid_second_grade() {
    return (get_sum_second() / 5.0);
}

double student_after_second::get_mid_year_grade() {
    return (get_sum_all() / 9.0);
}

std::ostream& operator<< (std::ostream& out, const student_after_second& student) {
    out << static_cast<student_after_first>(student);
    out << "Grade after second: ";
    for (const auto& x : student.get_full_second_grade()) {
        out << x << ' ';
    }
    out << '\n';

    return out;
}