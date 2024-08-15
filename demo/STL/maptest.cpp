#include <iostream>
#include "Map.hpp"

int main() {
    Set s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(10);
    
    std::cout << (s.find(1)) << std::endl;
    std::cout << (s.insert(9));
    // for (auto i : s) {
    //     std::cout << i << std::endl;
    // }
}