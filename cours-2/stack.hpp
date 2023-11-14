#ifndef STACK_H_
#define STACK_H_

struct Stack {
    int taille;
    int head;
    int * tab;
    Stack(int taille = 100);
    ~Stack();
    void push (int a);
    int pop();
    void print();
};
#endif