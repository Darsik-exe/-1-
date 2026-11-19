#include "proper_fraction_class.h"

int64_t proper_fraction::gcd(int64_t a, int64_t b) {
    while (a && b) 
        if (a > b) a %= b;
        else b %= a;

        return a + b;
}

int64_t proper_fraction::bin_pow(int64_t x, int64_t n) {
    int64_t res = 1;
    while (n) {
        if (n % 2) {
            res = res * x;
            --n;
        }
        else {
            x = x * x;
            n /= 2;
        }
    }

    return res;
}

void proper_fraction::reduction(int64_t& x, int64_t& y) {
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

proper_fraction::proper_fraction (int64_t x, int64_t y) {
    a = x;
    b = y;

    reduction(a, b);
}

proper_fraction::proper_fraction (const std::string& s) {
    bool f = 0;
    short sign_a = 1, sign_b = 1;
    a = b = 0;
    
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

    a *= sign_a;
    b *= sign_b;

    //std::cout << ">>> " << a << ' ' << b << '\n';

    reduction(a, b);
}

proper_fraction::proper_fraction (const proper_fraction& x) {
    a = x.get().first;
    b = x.get().second;

    reduction(a, b);
}

int64_t proper_fraction::get_numerator() const {
    return a;
}

int64_t proper_fraction::get_denominator() const {
    return b;
}

std::pair <int64_t, int64_t> proper_fraction::get() const {
    return {a, b};
}

void proper_fraction::set_numerator(const int64_t& x) {
    a = x;
            
    reduction(a, b);
}

void proper_fraction::set_denominator(const int64_t& x) {
    b = x;
            
    reduction(a, b);
}

void proper_fraction::set(const int64_t& x, const int64_t& y) {
    a = x;
    b = y;

    reduction(a, b);
}

proper_fraction proper_fraction::operator+ (const proper_fraction& x) {
    int64_t a_new, b_new;
    int64_t c = gcd(b, x.get_denominator());
        
    int64_t con1 = x.get_denominator() / c;
    int64_t con2 = b / c;
            
    a_new = a * con1 + x.get_numerator() * con2;
    b_new = b * con1;

    reduction(a_new, b_new);
            
    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator- (const proper_fraction& x) {
    int64_t a_new, b_new;
    int64_t c = gcd(b, x.get_denominator());
        
    int64_t con1 = x.get_denominator() / c;
    int64_t con2 = b / c;
            
    a_new = a * con1 - x.get_numerator() * con2;
    b_new = b * con1;

    reduction(a_new, b_new);
            
    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator* (const proper_fraction& x) {
    int64_t a_new = a * x.get_numerator();
    int64_t b_new = b * x.get_denominator();

    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator/ (const proper_fraction& x) {
    int64_t a_new = a * x.get_denominator();
    int64_t b_new = b * x.get_numerator();

    return proper_fraction(a_new, b_new);
}

proper_fraction proper_fraction::operator^ (const proper_fraction& x) {
    int64_t n = x.get_numerator();
    int64_t m = x.get_denominator();
    
    if (m != 1) {
        std::cerr << "Sorry, but I can't get squart.";
        
        exit(0);
    }

    a = bin_pow(a, n);
    b = bin_pow(b, n);

    return proper_fraction(a, b);
}

proper_fraction& proper_fraction::operator= (const proper_fraction& x) {
    a = x.get_numerator();
    b = x.get_denominator();

    return *this;
}

bool proper_fraction::operator< (const proper_fraction& x) {
    int64_t c = b / gcd(b, x.get_denominator()) * x.get_denominator();

    return (a * c < x.get_numerator() * c);
}

bool proper_fraction::operator> (const proper_fraction& x) {
    int64_t c = b / gcd(b, x.get_denominator()) * x.get_denominator();

    return (a * c > x.get_numerator() * c);
}

bool proper_fraction::operator== (const proper_fraction& x) {
    return (a == x.get_numerator() && b == x.get_denominator());
}

bool proper_fraction::operator<= (const proper_fraction& x) {
    return (*this < x || *this == x);
}

bool proper_fraction::operator>= (const proper_fraction& x) {
    return (*this > x || *this == x);
}

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