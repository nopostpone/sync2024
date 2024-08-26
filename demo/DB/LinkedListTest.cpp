#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {

    int a[] = {1, 2, 3, 4, 5};

    LinkedList<int> l(a, 5);

    l.push_back(1);

    cerr << l[0];

    

    return 0;
}