#include <iostream>
#include "Function.hpp"

int main() {
 
    std::vector<int> a;

    Function<int(int)> test = [&](int x) {
        a.push_back(x);
    };

    for (auto &i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}