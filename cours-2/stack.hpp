#ifndef STACK_H_
#define STACK_H_


struct Stack {
    private:
        int taille;
        int head;
        int * tab;
    public:
        Stack(int taille = 100);
        Stack(Stack const & auxStack);
        Stack& operator=(Stack const & auxStack);
        ~Stack();
        void push (int a);
        int pop();
        void print();
};

#endif