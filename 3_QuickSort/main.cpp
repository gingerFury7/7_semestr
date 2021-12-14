#include <iostream>
#include <chrono>
#include <vector>
#include <random>
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
    int N = 30000;
    int arrayA[N];
    int arrayB[N];

    int M = 1;


//    for (int x = 0; x < M; x++) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::vector<std::vector<int>> V(2 * N + 1, std::vector<int>(N));
        for (int i = 0; i < N; i++) { V[N][i] = mt() % (N); }
        for (int j = N + 1; j < 2 * N + 1; j++) {
            V[j][0] = V[j - 1][0];
            for (int i = 1; i < N; i++) {
                if (V[j - 1][i] > V[j][i - 1]) {
                    V[j][i] = V[j - 1][i];
                } else {
                    V[j][i] = V[j][i - 1];
                    V[j][i - 1] = V[j - 1][i];
                }
            }
        }


        for (int j = N - 1; j > -1; j--) {
            V[j][N - 1] = V[j + 1][N - 1];
            for (int i = N - 2; i > -1; i--) {
                if (V[j + 1][i] > V[j][i + 1]) {
                    V[j][i] = V[j + 1][i];
                } else {
                    V[j][i] = V[j][i + 1];
                    V[j][i + 1] = V[j + 1][i];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            arrayA[i] = V[N][i];
            arrayB[i] = V[N][i];
//            std::cout << arrayA[i] << ' ';
        }
//        std::cout << std::endl;

        auto begin = std::chrono::high_resolution_clock::now();
        quickSort(arrayA, 0, N - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto durationQuick = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        auto begin1 = std::chrono::high_resolution_clock::now();
        dualPivotQuickSort_2(arrayB, 0, N - 1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto durationDualPivotQuick = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
//    }

    std::cout << "QuickSort: " << durationQuick.count() << std::endl;
//    printArray(arrayA, N);
    std::cout << "DualPivotQuickSort: " << durationDualPivotQuick.count() << std::endl;
//    printArray(arrayB, N);

    return (0);

}