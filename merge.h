#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(void *elements, size_t size) : Sort(elements, size) {}

        void mergeSorter(void (*compare)(void*, int, int), int left, int right){
            if((right - left) == 1){
                compare(elements, left, right);
            }else if((right - left) > 1){
                mergeSorter(compare, left, (right+left)/2);
                mergeSorter(compare, (right+left)/2 + 1, right);
                sortMerged(compare, left, right);
            }

        }

        void sortMerged(void (*compare)(void*, int, int), int left, int right){
            for(int i = left+1; i <= right; i++){
                for(int j = i; j >left; j--) {
                    compare(elements, j-1, j);
                }
            }
        };


        void execute(void (*compare)(void*, int, int)) {
            mergeSorter(compare, 0, size-1);
        }

        inline string name() { return "MergeSort"; }
};

#endif