#include <iostream>

void swap (int *i, int *j){
    int temp = *j;
    *j = *i;
    *i = temp;
}

int partition (int *array, int low, int high, int *lp, int *swapsCounter, int *compareCounter){
    if (array[low] > array[high])
        swap (&array[low], &array[high]);

    int j = low + 1;
    int g = high - 1;
    int k = low + 1;

    int leftPivot = array[low];
    int rightPivot = array[high];

    while (k <= g){
        if (array[k] < leftPivot){
            swap(&array[k], &array[j]);
            (*swapsCounter)++;
            (*compareCounter)++;
            j++;
        }
        else if (array[k] >= g) {
            while (array[g] > rightPivot && k < g) {
                g--;
                (*compareCounter)++;
            }
            swap(&array[k], &array[g]);
            (*swapsCounter)++;
            g--;
            (*compareCounter)++;
            if (array[k] < leftPivot){
                swap(&array[k], &array[j]);
                (*swapsCounter)++;
                (*compareCounter)++;
                j++;
            }
        }
        k++;
        (*compareCounter)++;
    }
    j--;
    g++;

    swap(&array[low], &array[j]);
    swap(&array[high], &array[g]);
    *swapsCounter += 2;

    *lp = j;

    return g;
}

void dualPivotQuickSort_2 (int *array, int low, int high, int *swapsCounter, int *compareCounter){

    if (low < high){
        int lp, rp;
        rp = partition(array, low, high, &lp, swapsCounter, compareCounter);
        dualPivotQuickSort_2(array, low, lp - 1, swapsCounter, compareCounter);
        dualPivotQuickSort_2(array, lp + 1, rp - 1, swapsCounter, compareCounter);
        dualPivotQuickSort_2(array, rp + 1, high, swapsCounter, compareCounter);
    }

}