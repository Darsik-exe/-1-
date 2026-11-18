#include "basic_student_class.h"

void basic_student_class::copy_name(char* name) {
    int sz = strlen(name) + 1;
    this -> name = new char[sz];
    strcpy(this -> name, name); 
    this -> name[sz] = 0;

    return;
}

void basic_student_class::copy_name(const std::string& name) {
    int sz = static_cast<int>(name.size());
    this -> name = new char[sz + 1];
    this -> name[sz] = 0;
    
    for (int i = 0; i < static_cast<int>(name.size()); ++i) 
        this -> name[i] = name[i];

    return;
}

basic_student_class::basic_student_class(const std::string& name, const int& year, const int& group, const int& passbook) {    
    copy_name(name);

    this -> year = year;
    this -> group = group;
    this -> passbook = passbook;
    ID = go_ID();
}

basic_student_class::basic_student_class(char* name, const int& year, const int& group, const int& passbook) {
    copy_name(name);

    this -> year = year;
    this -> group = group;
    this -> passbook = passbook;
    ID = go_ID();
}

basic_student_class::basic_student_class(const basic_student_class& student) {
    name = student.get_name();
    year = student.get_year();
    group = student.get_group();
    passbook = student.get_passbook();
    ID = go_ID();
}

basic_student_class::~basic_student_class() {
    delete[] name;
    
}

void basic_student_class::rename(const char* new_name) {
    *name = *new_name; 
}

void basic_student_class::reyear(const int& new_year) {
    year = new_year;
}

void basic_student_class::regroup(const int& new_group) {
    group = new_group;
}

std::string basic_student_class::print() const {
    std::stringstream out;
    
    //std::cout << "zero first\n";

    out << "ID: " << ID << '\n';
    out << "Passbook: " << passbook << '\n';
    out << "Name: " << name << '\n';
    out << "Year: " << year << '\n';
    out << "Group: " << group << '\n';

    //std::cout << "zero second\n";

    return out.str();
}

char* basic_student_class::get_name() const {
    return name;
}

int basic_student_class::get_year() const {
    return year;
}

int basic_student_class::get_group() const {
    return group;
}

int basic_student_class::get_ID() const {
    return ID;
}

int basic_student_class::get_passbook() const {
    return passbook;
}

int basic_student_class::get_type() const {
    return type;
}

double basic_student_class::get_mid_first_grade() {
    return 0;
}

double basic_student_class::get_mid_year_grade() {
    return 0;
}

std::ostream& operator<< (std::ostream& out, const basic_student_class& student) {
    out << student.print();

    return out;
}