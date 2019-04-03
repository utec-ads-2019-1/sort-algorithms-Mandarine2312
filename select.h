#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            int *positionOfMax = new int;
            int *array = (int*) elements;

            for(int i = size; i >= 0; i--){
                *positionOfMax = i;
                for(int j = i; j >= 0; j--){
                    if(array[j] > array[*positionOfMax]){
                        *positionOfMax = j;
                    }
                }
                swap(array[i], array[*positionOfMax]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif