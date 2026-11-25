#include <iostream>
#include <string>
#include "stack.h"

bool isOperation(const char& x);
bool isNumber(const char& x);
bool correct_symbol(const char& x);
int get_priority(const char& c);
int toInt (const std::string& s);
long double bin_pow (long double x, int n);

int main() {
    std::cout << "Write:\n";
    
    std::string s;
    getline(std::cin, s);

    while (s.find(" ") != -1) {
        s.erase(s.find(" "), 1);
    }

    int n = s.size();

    for (int i = n - 2; i >= 0; --i) {
        if (isNumber(s[i]) && s[i + 1] == '(') s.insert(i + 1, "*");
        if (s[i] == ')' && s[i + 1] == '(') s.insert(i + 1, "*");
    }

    n = s.size();

    { //check is expression correct

    if (n == 0) {
        std::cout << "WTF1???";
        
        return 0;
    }

    int cnt = 0;
    for (const auto& to : s) {
        if (to == '(') 
            ++cnt;
        if (to == ')') 
            --cnt;

        if (cnt < 0) {
            std::cout << "WTF2???";

            return 0;
        }
    } 

    if (cnt != 0) {
        std::cout << "WTF3???";

        return 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '(' && s[i + 1] == ')') {
            std::cout << "WTF4???";

            return 0;
        }
    }

    for (const auto& to : s) {
        if (!correct_symbol(to)) {
            std::cout << "WTF5???";

            return 0;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (isOperation(s[i]) && !(isNumber(s[i + 1]) || s[i + 1] == '(')) {
            std::cout << "WTF6???";

            return 0;
        }
    }

    if (isOperation(s[n - 1])) {
        std::cout << "WTF7???";

        return 0;
    }

    if (s[0] == '*' || s[0] == '/' || s[0] == '^' || isOperation(s[n - 1])) {
        std::cout << "WTF8???";

        return 0;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == '/' || s[i] == '*' || s[i] == '^') {
            if (!(isNumber(s[i - 1]) || s[i - 1] == ')') || !(isNumber(s[i + 1]) || s[i + 1] == '(')) {
                //std::cout << ">>>> " <<  << '\n';
                std::cout << "WTF9???";

                return 0;
            }
        }
    }

    } // end of check

    std::string cs;
    cs.clear();

    { //to polish
    
    stack< std::pair<int, char> > st;

    std::string number;

    for (int i = 0; i < n; ++i) {
        if (isNumber(s[i])) {
            number += s[i];
            
            continue;
        }
        
        if (!number.empty()) {
            cs += number + " ";
            number.clear();
        }
        
        if (s[i] == ')') {
            while (st.top().first) {
                cs += st.top().second;
                cs += " ";
                st >> 1;
            }
            st >> 1;

            continue;
        }

        std::pair <int, char> x;

        if (s[i] == '(') {
            x.first = 0;
            x.second = s[i]; 
            st << x;

            continue;
        }
        if (isOperation(s[i]) && (i == 0 || (!isNumber(s[i - 1]) && s[i - 1] != ')'))) {
            x.first = 4;
            x.second = s[i];
        }
        x.first = get_priority(s[i]);
        x.second = s[i];

        while (!st.empty() && (st.top().first > x.first || (x.first <= 2 && st.top().first == x.first))) {
            cs += st.top().second;
            cs += " ";
            st >> 1;
        }

        st << x;
    }

    
    if (!number.empty()) cs += number + " ";
    
    while (!st.empty()) {
        cs += st.top().second;
        cs += " ";
        st >> 1;
    }
    
    //std::cout << s << '\n' << cs << '\n';
    
    } // end of block

    stack<long double> ans;

    { //get answer
    
    std::string number;
    number.clear();

    for (const auto& to : cs) {
        if (isNumber(to)) {
            number += to;
            
            continue;
        }

        if (!number.empty()) {
            ans << static_cast<long double>(toInt(number));

            number.clear();
        }

        if (!correct_symbol(to)) 
            continue;

        long double x = ans.top();
        long double y = 0;
        ans >> 1;
        if (!ans.empty()) {
            y = ans.top();
            ans >> 1;
        }

        if (to == '/') 
            y = y / x;
        
        if (to == '*') 
            y = y * x;
        
        if (to == '+') 
            y = y + x;
    
        if (to == '-') 
            y = y - x;

        if (to == '^') 
            y = bin_pow(y, x);

        //std::cout << x << ' ' << y << '\n';

        ans << y;
    }

    } //end of block

    std::cout << ans.top();

    return 0;
}

bool isOperation(const char& x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') 
        return true;
    else 
        return false;
}

bool isNumber(const char& x) {
    if (x >= '0' && x <= '9') 
        return true;
    else 
        return false;
}

bool correct_symbol(const char& x) {
    if (x == '(' || x == ')') 
        return true;
    if (isNumber(x)) 
        return true;
    if (isOperation(x)) 
        return true;

    return false;
}

int get_priority(const char& c) {
    if (c == '-' || c == '+') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;

    return 0;
}

int toInt (const std::string& s) {
    int x = 0;
    for (int i = 0; i < s.size(); ++i) 
        x = x * 10 + s[i] - '0';

    return x;
}

 long double bin_pow (long double x, int n) {
    long double res = 1;

    while (n) {
        if (n % 2) {
            res *= x;
            --n;
        }
        else {
            x *= x;
            n /= 2;
        }
    }

    return res;
}
