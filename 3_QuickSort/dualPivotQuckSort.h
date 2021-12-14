#include <iostream>

void swap (int *i, int *j){
    int temp = *j;
    *j = *i;
    *i = temp;
}

int partition (int *array, int low, int high, int *lp){
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
            j++;
        }
        else if (array[k] >= g) {
            while (array[g] > rightPivot && k < g)
                g--;
            swap(&array[k], &array[g]);
            g--;
            if (array[k] < leftPivot){
                swap(&array[k], &array[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    swap(&array[low], &array[j]);
    swap(&array[high], &array[g]);

    *lp = j;

    return g;
}

void dualPivotQuickSort_2 (int *array, int low, int high){

    auto begin = std::chrono::high_resolution_clock::now();

    if (low < high){
        int lp, rp;
        rp = partition(array, low, high, &lp);
        dualPivotQuickSort_2(array, low, lp - 1);
        dualPivotQuickSort_2(array, lp + 1, rp - 1);
        dualPivotQuickSort_2(array, rp + 1, high);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

}