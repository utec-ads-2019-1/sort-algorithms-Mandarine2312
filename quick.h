#ifndef QUICK_H
#define QUICK_H

#include "sort.h"
#include <vector>


class QuickSort : public Sort {       
    public:
        QuickSort(void *elements, size_t size) : Sort(elements, size) {}

        void quickSorter(void (*compare)(void*, int, int), int left, int pivot) {
            int *array = (int *) elements;
            int right = pivot - 1, originalLeft = left;

            if ((pivot - left) > 0) {
                while (left < right) {
                    if (array[left] > array[right]) {
                        std::swap(array[left], array[right]);
                    } else if (array[left] < array[pivot]) {
                        left++;
                    } else if (array[right] >= array[pivot]) {
                        right--;
                    }
                }

                compare(elements, right, pivot);
            }

            if(((pivot-1)-originalLeft) >= 1){
                quickSorter(compare, originalLeft, right-1);
                quickSorter(compare, right+1, pivot);
            }
        }


        void execute(void (*compare)(void*, int, int)) {
            quickSorter(compare, 0, size-1);
        }

        inline string name() { return "QuickSort"; }
};

#endif