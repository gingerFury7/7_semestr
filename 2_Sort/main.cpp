#include "stdio.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <random>

int bubbleSort (const int *num, int size){
    int a[size];
    for (int i = 0; i < size; i++){
        a[i] = num[i];
    }

    auto begin = std::chrono::high_resolution_clock::now();
    int k = 0;

    for (int i = 0; i < size - 1; i++){
        for (int j = (size - 1); j > i; j--){
            if (a[j - 1] > a[j]){
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                k++;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return duration.count();
}

int insertSort (const int *num, int size) {
    int a[size];
    for (int i = 0; i < size; i++){
        a[i] = num[i];
    }

    auto begin = std::chrono::steady_clock::now();
    int k = 0;

    for(int i = 1; i < size; i++){
        int key = a[i];
        int j = i - 1;

        while (key < a[j] && j >= 0){
            a[j + 1] = a[j];
            --j;
            k++;
        }
        a[j + 1] = key;
    }

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return duration.count();
}

int selectionSort (const int *num, int size) {
    int a[size];
    for (int i = 0; i < size; i++){
        a[i] = num[i];
    }

    auto begin = std::chrono::steady_clock::now();

    int min;
    int k = 0;

    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min]){
                min = j;
            }
            k++;
        }
        std::swap(a[i], a[min]);
    }

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return duration.count();
}

int main() {

    int N = 70;
    int a[N];

    int durationBuble = 0;
    int durationInsert = 0;
    int durationSelection = 0;

    for (int x = 0; x < 1000; x++) {
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

//    for(int i = 0; i < 2 * N + 1; i++){
//        for(int j = 0; j < N; j++){
//            std::cout << V[i][j] << '\t';
//        }
//        std::cout << '\n';
//    }

        for (int i = 0; i < N; i++) {
            a[i] = V[70][i];
//            std::cout << a[i] << ' ';
        }
        durationBuble += bubbleSort(a, N);
        durationInsert += insertSort(a, N);
        durationSelection += selectionSort(a, N);
    }

    std::cout << "buble: " << durationBuble / 1000 << std::endl;
    std::cout << "Insert: " << durationInsert / 1000 << std::endl;
    std::cout << "selection: " << durationSelection / 1000 << std::endl;

    return 0;
}