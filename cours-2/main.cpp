#include <iostream>
#include "stack.hpp"

int main() {
    Stack mystack;
    mystack.Init();

    mystack.push(3);
    mystack.push(5);
    mystack.print();


    int poppedValue = mystack.pop();
    std::cout << poppedValue << std::endl;

    mystack.push(8);
    mystack.print();

    return 0;
}