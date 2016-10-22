#include "vector.h"
#include <iostream>

int main() {

    Vector<int> test;
    int a = 0, b = 20;

    std::cout << test.size() << std::endl;
    test.insert( 1, 1 );
    test.unsort( a, b );

    return 0;
}
