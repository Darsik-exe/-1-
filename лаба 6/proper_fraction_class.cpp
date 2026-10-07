#include <iostream> 
#include <string>
#include "proper_fraction_class.h"

int a, b;

int proper_fraction::gcd(int a, int b) {
    while (a && b) 
        if (a > b) a %= b;
        else b %= a;

        return a + b;
    }

void proper_fraction::reduction(int& x, int& y) {
    if (y == 0) {
        std::cout << "I can't divide by 0!!! You are stupid!!!";
        
        exit(0);
    }

    int c = gcd(abs(x), abs(y));

    x /= c;
    y /= c;
        
    if (y < 0) {
        y *= -1;
        x *= -1;
    }
} 

proper_fraction::proper_fraction (int x, int y) {
    a = x;
    b = y;

    reduction(a, b);
}

proper_fraction::proper_fraction (const proper_fraction& x) {
    a = x.get().first;
    b = x.get().second;

    reduction(a, b);
}

int proper_fraction::get_numerator() const {
    return a;
}

int proper_fraction::get_denominator() const {
    return b;
}

std::pair <int, int> proper_fraction::get() const {
    return {a, b};
}

void proper_fraction::set_numerator(int x) {
    a = x;
            
    reduction(a, b);
}

void proper_fraction::set_denominator(int x) {
    b = x;
            
    reduction(a, b);
}

void proper_fraction::set(int x, int y) {
    a = x;
    b = y;

    reduction(a, b);
}

proper_fraction proper_fraction::operator+ (const proper_fraction& x) {
    int a_new, b_new;
    int c = gcd(b, x.get_denominator());
        
    int con1 = x.get_denominator() / c;
    int con2 = b / c;
            
    a_new = a * con1 + x.get_numerator() * con2;
    b_new = b * con1;

    reduction(a_new, b_new);
            
    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator* (const proper_fraction& x) {
    int a_new = a * x.get_numerator();
    int b_new = b * x.get_denominator();

    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator/ (const proper_fraction& x) {
    int a_new = a * x.get_denominator();
    int b_new = b * x.get_numerator();

    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator+ (const int& x) {
    int a_new = a + x * b;

    return proper_fraction(a_new, b);
}

proper_fraction proper_fraction::operator* (const int& x) {
    int a_new = a * x;

    return proper_fraction(a_new, b);
}

proper_fraction proper_fraction::operator/ (const int& x) {
    int b_new = b * x;

    return proper_fraction(a, b_new);
}
/*
std::ostream& operator<< (std::ostream& out, proper_fraction& x) {
    if (x.get().second == 1) 
        out << x.get().first;
    else
         out << x.get().first << '/' << x.get().second;

    return out;
}
*/

std::ostream& operator<< (std::ostream& out, proper_fraction x) {
    if (x.get().second == 1) 
        out << x.get().first;
    else
         out << x.get().first << '/' << x.get().second;

    return out;
}

std::istream& operator>> (std::istream& in, proper_fraction& x) {
    std::string s;
    in >> s;

    std::string s1, s2;
    s1.clear();
    s2.clear();

    bool f = 0;
    short sign_a = 1, sign_b = 1;
    int a = 0, b = 0;
    
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '/') {
            f = 1;

            continue;
        }

        if (!f) {
            if (s[i] == '-') 
                sign_a = -1;
            else 
                a = a * 10 + s[i] - '0';
        }
        else {
            if (s[i] == '-') 
                sign_b = -1;
            else 
                b = b * 10 + s[i] - '0';
        }
    }

    if (b == 0 && !f) 
        b = 1;

    x.set_numerator(a * sign_a);
    x.set_denominator(b * sign_b);

    return in;
}