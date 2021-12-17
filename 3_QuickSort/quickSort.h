#include <iostream>

void quickSort (int *array, int low, int high, int *swapsCounter, int *compareCounter){

    int i = low;
    int j = high;
    int pivot = array[(i+j) / 2];

    while (i <= j){
        while (array[i] < pivot) {
            i++;
            (*compareCounter)++;
        }
        while (array[j] > pivot) {
            j--;
            (*compareCounter)++;
        }
        if (i <= j){
            swap(&array[i], &array[j]);
            (*compareCounter)++;
            (*swapsCounter)++;
            i++;
            j--;
        }
        (*compareCounter)++;
    }

    if (j > low) {
        quickSort(array, low, j, swapsCounter, compareCounter);
        (*compareCounter)++;
    }
    if (i < high) {
        quickSort(array, i, high, swapsCounter, compareCounter);
        (*compareCounter)++;
    }

}