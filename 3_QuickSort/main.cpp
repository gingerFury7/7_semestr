#include <iostream>

void swap (int i, int j){
    int temp = j;
    j = i;
    i = temp;
}

void quickSort (int *array, int low, int high){
    int i = low;
    int j = high;
    int pivot = array[(i+j) / 2];
    int temp;

    while (i <= j){
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j){
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}


void dualPivotQuickSort (int *array, int low, int high){
    if (array[low] > array[high])
        swap(array[low], array[high]);

    int j = low + 1;
    int k = low + 1;
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

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

int main()
{
    int array[] = {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
    int n = sizeof(array)/sizeof(array[0]);

    std::cout << "Before Quick Sort :" << std::endl;
    printArray(array, n);

//    quickSort(array, 0, n);
    dualPivotQuickSort(array, 0, n - 1);

    std::cout << "After Quick Sort :" << std::endl;
    printArray(array, n);
    return (0);


}