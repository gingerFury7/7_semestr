#include <iostream>

void swap (int i, int j){
    int temp = j;
    j = i;
    i = temp;
}

void dualPivotQuickSort (int *array, int low, int high){
    if (array[low] > array[high])
        swap(array[low], array[high]);

    int k = low + 1;
    int j = k;
    int g = high - 1;

    int leftPivot = array[low];
    int rightPivot = array[high];

    while (k <= g){
        if (array[k] < leftPivot){
            swap(array[k], array[j]);
            j++;
        }
        else if (array[k] >= rightPivot){
            while (array[g] > rightPivot && k < g){
                g--;
            }
            if (array[g] > leftPivot) {
                swap(array[k], array[g]);
            } else {
                swap(array[k], array[g]);
                swap(array[k], array[j]);
            }
            g--;
        } else {
            k++;
        }

    }
//    swap(array[low], array[j - 1]);
//    swap(array[high], array[g + 1]);

    j--;
    g++;


    dualPivotQuickSort(array, low, j - 1);
    dualPivotQuickSort(array, j + 1, g - 1);
    dualPivotQuickSort(array, g + 1, high);
}