#ifndef STACK_H_
#define STACK_H_

struct Stack {
    int taille;
    int tab[20];
    Stack();
    void push (int a);
    int pop();
    void print();
};
#endif