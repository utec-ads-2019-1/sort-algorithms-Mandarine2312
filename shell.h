#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            for(int gap = (size/2)+1; gap >= 1; gap--){
                for(int j = 0; j < size - i; j++){
                    compare(elements, j, j+gap);
                }
                for(int j = size-1; j >= size-gap-1; j--){
                    compare(elements, j-gap, j);
                }
            }

        void printElements(){
            int *array = (int*) elements;
            for(int i = 0; i < size; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }


        inline string name() { return "ShellSort"; }
};

#endif