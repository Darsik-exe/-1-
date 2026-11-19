#pragma once

#include <iostream>
#include <cstdint> 
#include <string>

class proper_fraction {
    private:
        int64_t a, b;
        int64_t gcd(int64_t a, int64_t b);
        void reduction(int64_t& x, int64_t& y);
        int64_t bin_pow(int64_t x, int64_t n);

    public:
        proper_fraction (int64_t x = 0, int64_t y = 1);
        proper_fraction (const std::string& s);
        proper_fraction (const proper_fraction& x);

        int64_t get_numerator() const;
        int64_t get_denominator() const;
        std::pair <int64_t, int64_t> get() const;
        
        void set_numerator(const int64_t& x);
        void set_denominator(const int64_t& x);    
        void set(const int64_t& x, const int64_t& y);

        proper_fraction operator+ (const proper_fraction& x);
        proper_fraction operator- (const proper_fraction& x);
        proper_fraction operator* (const proper_fraction& x);
        proper_fraction operator/ (const proper_fraction& x);
        proper_fraction operator^ (const proper_fraction& x);

        proper_fraction& operator= (const proper_fraction& x);

        bool operator< (const proper_fraction& x);
        bool operator> (const proper_fraction& x);
        bool operator== (const proper_fraction& x);
        bool operator<= (const proper_fraction& x); 
        bool operator>= (const proper_fraction& x);
};

//std::ostream& operator<< (std::ostream& out, proper_fraction& x);

std::ostream& operator<< (std::ostream& out, proper_fraction x);

std::istream& operator>> (std::istream& in, proper_fraction& x);    
