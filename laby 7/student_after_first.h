#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "basic_student_class.h"

class student_after_first : public basic_student_class {
    private: 
        std::vector<int> first_grade = {-1, -1, -1, -1};
        int sum_first = 0;

        student_after_first();

    public:
        student_after_first (const std::string& name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade);
        student_after_first (char* name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade);
        student_after_first (const basic_student_class& student, std::vector<int>& first_grade);
        student_after_first (const student_after_first& student);

        virtual std::string print() override;

        int get_sum_first() const;
        int get_first_grade(const int& ind) const;
        std::vector<int> get_full_first_grade() const;

        void fixed_first_grade(const int& ind, const int& x);
        void fixed_all_first_grade(const std::vector<int> new_first_grade);

        double get_mid_first_grade() override;
};

std::ostream& operator<< (std::ostream& out, const student_after_first& student);