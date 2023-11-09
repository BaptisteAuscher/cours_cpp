#include <iostream>
#include "sort.hpp"

int main () {
    int tab[] = {9,8,5,17,11,3};
    print(6, tab);
    std::cout << "Started sorting" << std::endl;
    sort(6, tab);
    print(6, tab);
    return 0;
}