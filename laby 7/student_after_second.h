#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "basic_student_class.h"
#include "student_after_first.h"

class student_after_second : public student_after_first {
    private:
        std::vector<int> second_grade = {-1, -1, -1, -1, -1};
        int sum_second, sum_all;

        student_after_second();

    public:
        student_after_second (const std::string& name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade, std::vector<int>& second_grade);
        student_after_second (char* name, const int& year, const int& group, const int& passbook, std::vector<int>& first_grade, std::vector<int>& second_grade);
        student_after_second (const basic_student_class& student, std::vector<int>& first_grade, std::vector<int>& second_grade);
        student_after_second (const student_after_first& student, std::vector<int>& second_grade);
        student_after_second (const student_after_second& student);

        std::string print() override;

        int get_sum_second() const;
        int get_sum_all() const;
        int get_second_grade(const int& ind) const;
        std::vector<int> get_full_second_grade() const;

        void fixed_second_grade(const int& ind, const int& x);
        void fixed_all_second_grade(const std::vector<int> new_second_grade);

        double get_mid_second_grade();
        double get_mid_year_grade() override;
};

std::ostream& operator<< (std::ostream& out, const student_after_second& student);