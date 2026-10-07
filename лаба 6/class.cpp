#include <iostream>
#include "proper_fraction_class.h"

int main() {
    proper_fraction a;
    proper_fraction b;
    int c;

    std::cout << "Write first number ('1', '-1/9', '-4/-5', '2/-10'): ";
    std::cin >> a;

    std::cout << "Write second number ('1', '-1/9', '-4/-5', '2/-10'): ";
    std::cin >> b;

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';

    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a / b = " << a / b << '\n';

    return 0;
}