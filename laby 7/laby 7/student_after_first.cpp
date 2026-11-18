#include "student_after_first.h"

student_after_first::student_after_first (const std::string& name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade) : basic_student_class(name, year, group, passbook) {
    this -> first_grade = first_grade;

    sum_first = 0;
    for (const int& to : first_grade) {
        sum_first += to;
    }
    
    type = 1;
}

student_after_first::student_after_first (char* name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade) : basic_student_class(name, year, group, passbook) {
    this -> first_grade = first_grade;

    sum_first = 0;
    for (const int& to : first_grade) {
        sum_first += to;
    }

    type = 1;
}

student_after_first::student_after_first (const basic_student_class& student, std::vector<int>& first_grade) : basic_student_class(student) {
    this -> first_grade = first_grade;

    sum_first = 0;
    for (const int& to : first_grade) {
        sum_first += to;
    }

    type = 1;
}

student_after_first::student_after_first (const student_after_first& student) : basic_student_class(student){
    first_grade = student.get_full_first_grade();
    sum_first = student.get_sum_first();

    type = 1;
}

std::string student_after_first::print() const {
    std::stringstream out;

    //std::cout << "first first\n";
    out << basic_student_class::print();
    //std::cout << "firts second\n";
    
    out << "Grade after first: ";
    for (const auto& x : first_grade) {
        out << x << ' ';
    }
    out << '\n';

    return out.str();
}

int student_after_first::get_sum_first() const {
    return sum_first;
}

int student_after_first::get_first_grade(const int& ind) const {
    return first_grade[ind];
}

std::vector<int> student_after_first::get_full_first_grade() const {
    return first_grade;
}

void student_after_first::fixed_first_grade(const int& ind, const int& x) {
    sum_first += x - first_grade[ind];
    first_grade[ind] = x;
}

void student_after_first::fixed_all_first_grade(const std::vector<int> new_first_grade) {
    first_grade = new_first_grade;
    
    sum_first = 0;
    for (const int& to : first_grade) {
        sum_first += to;
    }
}

double student_after_first::get_mid_first_grade() {
    return (sum_first / 4.0);
}

std::ostream& operator<< (std::ostream& out, const student_after_first& student) {
    out << student.print();

    return out;
}