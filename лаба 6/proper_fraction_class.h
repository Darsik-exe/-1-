#ifndef proper_fraction_class
#define proper_fraction_class

class proper_fraction {
    private:
        int a, b;
        int gcd(int a, int b);
        void reduction(int& x, int& y);
    
    public:
        proper_fraction (int x = 1, int y = 1);
        proper_fraction (const proper_fraction& x);

        int get_numerator() const;
        int get_denominator() const;
        std::pair <int, int> get() const;
        
        void set_numerator(int x);
        void set_denominator(int x);    
        void set(int x, int y);

        proper_fraction operator+ (const proper_fraction& x);
        proper_fraction operator* (const proper_fraction& x);
        proper_fraction operator/ (const proper_fraction& x);
        proper_fraction operator+ (const int& x);
        proper_fraction operator* (const int& x);
        proper_fraction operator/ (const int& x);
};

//std::ostream& operator<< (std::ostream& out, proper_fraction& x);

std::ostream& operator<< (std::ostream& out, proper_fraction x);

std::istream& operator>> (std::istream& in, proper_fraction& x);    

#endif /*proper_fraction_class*/