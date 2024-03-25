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

Stack::Stack(Stack const & auxStack) {
    taille = auxStack.taille;
    head = auxStack.head;
    tab = new int [taille];
    for (int i = 0; i < head; ++i) {
        tab[i] = auxStack.tab[i];
    }
}

Stack& Stack::operator= (Stack const & auxStack) {
    if (this != & auxStack) {
        delete tab;
        this->taille = auxStack.taille;
        this->head = auxStack.head;
        this->tab = new int[taille];
        for (int i = 0; i < head; ++i) {
            this->tab[i] = auxStack.tab[i];
        }
    }
    return *this;
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

