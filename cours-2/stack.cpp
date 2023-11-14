#include <iostream>
#include "stack.hpp"

void Stack::Init() {
    taille = 0;
    for (int i = 0; i < 20; ++i) {
        tab[i] = 0;
    }
}

void Stack::push (int a) {
    if (taille < 20) {
        tab[taille] = a;
        taille = taille + 1;
    }
}

int Stack::pop () {
    if (taille > 0) {
        int temp = tab[taille - 1];
        taille = taille - 1;
        return temp;
    }
    return -1;
 }

 void Stack::print () {
    std::cout << "[";
    int i = 0;
    for (; i < taille - 1; ++i) {
        std::cout << tab[i] << ",";
    }
    if (i < taille) {
        std::cout << tab[i];
    }
    std::cout << "]" << std::endl;
}

