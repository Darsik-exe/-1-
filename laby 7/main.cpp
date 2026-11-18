#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "basic_student_class.h"
#include "student_after_first.h"
#include "student_after_second.h"

int main() {
    std::vector <basic_student_class*> v;
    v.clear();

    int n;

    std::cout << "Write count of students: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Write type of student (basic, after firts, after second): ";

        std::cin.ignore();

        std::string s;
        getline(std::cin, s);
        //std::cout << ">>>>> " << s << '\n';

        std::string name;
        int year, group, passbook;
        std::vector<int> first_grade(4), second_grade(5);

        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "Year: ";
        std::cin>> year;
            
        std::cout << "Group: ";
        std::cin >> group;

        std::cout << "Passbook: ";
        std::cin >> passbook;
        
        if (s != "basic") {
            std::cout << "First grades: ";
            for (int j = 0; j < 4; ++j)
                std::cin >> first_grade[j];
        }

        if (s == "after second") {
            std::cout << "Second grades: ";
            for (int j = 0; j < 5; ++j)
                std::cin >> second_grade[j];
        }

        if (s == "basic") {
            basic_student_class* student = new basic_student_class(name, year, group, passbook);
            v.push_back(student);
        }

        if (s == "after first") {
            student_after_first* student = new student_after_first(name, year, group, passbook, first_grade);
            v.push_back(student);
        }

        if (s == "after second") {
            student_after_second* student = new student_after_second(name, year, group, passbook, first_grade, second_grade);
            v.push_back(student);
        }
    }

    std::cout << "Studensts:\n";

    for (const auto& x : v) {
        std::cout << x -> print();
    } 

    std::cin.ignore();

    int gr;
    std::cout << "Mid grade in group: ";
    std::cin >> gr;

    long double mid_first = 0, mid_second = 0;
    int cnt_first = 0, cnt_second = 0; 

    for (auto x : v) {
        if (x -> get_group() == gr) {
           if (dynamic_cast<student_after_first*>(x)) {
                mid_first += x -> get_mid_first_grade();
                ++cnt_first;
            }
            if (dynamic_cast<student_after_second*>(x)) {
                mid_second += x -> get_mid_year_grade();
                ++cnt_second;
            }
        }
    }

    if(cnt_first) {
        mid_first /= cnt_first;
        std::cout << "First mid: " << std::fixed << std::setprecision(1) << mid_first << '\n';
    }
    else {
        std::cout << "No first grades\n";
    }
    if (cnt_second) {
        mid_second /= cnt_second;
        std::cout << "Second mid: " << std::fixed << std::setprecision(1) << mid_second << '\n';
    }
    else {
        std::cout << "No year grades\n";
    }

    long double mid = 0;
    int cnt = 0;

    for (const auto& x : v) {
        if (dynamic_cast<student_after_first*>(x)) {
            mid += x -> get_mid_first_grade();
            ++cnt;
        }
    }

    if(cnt) {
        mid /= cnt;

        std::cout << "Mid in array (firtst grades): " << mid;
    }
    else {
        std::cout << "No grades";
    }

    return 0;
}

/*
5
basic
df
3
2
6546544
after second
fghb
2
4
47345895
2 8 5 3
1 10 3 5 7 
after first
adhf
3
4
547537
10 9 6 4
after first
arga
2
2
856730
8 9 1 0
after second
drjgj
1
3
53998570
8 10 7 3
9 7 5 6 1 
*/