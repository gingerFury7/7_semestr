#include <iostream>
#include "dualPivotQuckSort.h"
#include "quickSort.h"

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    int array[] = {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
    int n = 10;

    std::cout << "Before Quick Sort:" << std::endl;
    printArray(array, n);

    quickSort(array, 0, n);
//    dualPivotQuickSort_2(array, 0, n);

    std::cout << "After Quick Sort:" << std::endl;
    printArray(array, n);
    return (0);

}