#include <iostream>

void quickSort (int *array, int low, int high){

    static auto begin = std::chrono::high_resolution_clock::now();

    int i = low;
    int j = high;
    int pivot = array[(i+j) / 2];

    while (i <= j){
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j){
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }

    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);

    static auto end = std::chrono::high_resolution_clock::now();
    static auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

}