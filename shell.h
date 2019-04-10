#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            for(int i = (size/2); i >= 1; i--){
                for(int j = 0; j < size - i; j++){
                    compare(elements, j, j+i);}
            }
        }

        //No olvidar cambiar números del mocker
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