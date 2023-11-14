#include <iostream>
#include "stack.hpp"

Stack::Stack(int taille) {
    head = 0;
    this->taille = taille;
    tab = new int [taille];
}

Stack::~Stack() {
    delete tab;
}

void Stack::push (int a) {
    if (head < taille) {
        tab[head] = a;
        head += 1;
    }
}

int Stack::pop () {
    if (head > 0) {
        int temp = tab[head - 1];
        head -= 1;
        return temp;
    }
    return -1;
 }

 void Stack::print () {
    std::cout << "[";
    int i = 0;
    for (; i < head - 1; ++i) {
        std::cout << tab[i] << ",";
    }
    if (i < taille) {
        std::cout << tab[i];
    }
    std::cout << "]" << std::endl;
}

