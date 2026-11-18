#pragma once
#include <iostream>
#include "ID_maker.h"
#include <cstring>
#include <sstream>

class basic_student_class {
    private:
        int ID, passbook;
        char* name;
        int year, group;
        
        basic_student_class();

        void copy_name(char* name);
        void copy_name(const std::string& name);

    protected:
        int type = 0;

    public:
        basic_student_class(const std::string& name, const int& year, const int& group, const int& passbook);
        basic_student_class(char* name, const int& year, const int& group, const int& passbook);
        basic_student_class(const basic_student_class& student);

        ~basic_student_class();

        void rename(const char* new_name);
        void reyear(const int& new_year);
        void regroup(const int& new_group);

        virtual std::string print();

        char* get_name() const;
        int get_year() const;
        int get_group() const;
        int get_ID() const;
        int get_passbook() const;
        int get_type() const;

        virtual double get_mid_first_grade();
        virtual double get_mid_year_grade();
        
};

std::ostream& operator<< (std::ostream& out, const basic_student_class& student);