#include <iostream>

void print (int size, int * array) {
    std::cout << "[";
    int i = 0;
    for (; i < size - 1; ++i) {
        std::cout << array[i] << ",";
    }
    if (i < size) {
        std::cout << array[i];
    }
    std::cout << "]" << std::endl;
}

void swapValues (int i, int j, int tab[]) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}


void sort (int length, int tab[]) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i; j < length; ++j) {
            if (tab[i] > tab[j]) {
                swapValues(i, j, tab);
            }
        }
    }
}
