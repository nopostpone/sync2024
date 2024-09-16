#include <iostream>
#include "LinkedList.hpp"

using namespace std;

struct Test {
    int u = 10;
    double v = 123.123;
    short w = 2;
};

int main() {

// Node test
    string a = "This is A.";
    Node<string> A(a);

    cout << A.val << endl;

    Node<Test> bzd;
    cout << bzd.val.u << " " << bzd.val.v << " " << bzd.val.w << endl;

    Node<string> B("This is B.");
    A.next = &B;
    cout << (A.next)->val << endl;

    B.prev = &A;
    cout << (B.prev)->val << endl;
    cout << (B.prev->next)->val << " " << B.val << endl;

// LinkedList test

    Node<string> C("This is C.");

    LinkedList<string> Z;
    Z.push_back(C);
    cout << Z.size() << endl;


    return 0;
}