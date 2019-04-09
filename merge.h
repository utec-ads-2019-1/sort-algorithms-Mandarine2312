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
                //sortMerged(compare, left, right);
                newSortMerged(left, ((right+left)/2)+1, right);
            }

        }

        void sortMerged(void (*compare)(void*, int, int), int left, int right){
            for(int i = left+1; i <= right; i++){
                for(int j = i; j >left; j--) {
                    compare(elements, j-1, j);
                }
            }
        }

        void printSubArray(int start, int finish){
            int *array = (int*) elements;
            for(int i = start; i <= finish; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }

        void printArray(int * elementos, int size){
            for(int i = 0; i <size-1; i++){
                cout << elementos[i] << " ";
            }
            cout << endl;
        }

        void newSortMerged(int lowerLeft, int lowerRight, int upperRight){
            int *array = (int*) elements;
            int *leftArray = new int[(lowerRight) - lowerLeft];
            int *rightArray = new int[upperRight - lowerRight+1];

            //int low = lowerLeft;

            for(int i = lowerLeft; i < lowerRight; i++){
                leftArray[i-lowerLeft] = array[i];
            }
            for(int i = lowerRight; i <= upperRight; i++){
                rightArray[i-lowerRight] = array[i];
            }

            int leftIt = 0, rightIt = 0, arrayIt = lowerLeft;
            int maxLeft = (lowerRight-1) - lowerLeft;
            while(leftIt < (lowerRight) - lowerLeft && rightIt <= upperRight - lowerRight){
                if(leftArray[leftIt] < rightArray[rightIt]){
                    array[arrayIt] = leftArray[leftIt];
                    leftIt++;
                }else{
                    array[arrayIt] = rightArray[rightIt];
                    rightIt++;
                }
                arrayIt++;
            }

            while(leftIt < (lowerRight) - lowerLeft){
                array[arrayIt] = leftArray[leftIt];
                leftIt++;
                arrayIt++;
            }

            while(rightIt <= upperRight - lowerRight){
                array[arrayIt] = rightArray[rightIt];
                rightIt++;
                arrayIt++;
            }
        }

        void execute(void (*compare)(void*, int, int)) {
            mergeSorter(compare, 0, size-1);
        }

        inline string name() { return "MergeSort"; }
};

#endif