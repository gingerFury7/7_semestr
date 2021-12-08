#include "stdio.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <random>

void bubbleSort (const int *num, int size){
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

    std::cout << "----Сортировка обменом---- " << std::endl;
    std::cout << "Длительность работы: " << duration.count() << " ms" << std::endl;
    std::cout << "Количество сравнений: " << k << std::endl;
}

void insertSort (const int *num, int size) {
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

    std::cout << "----Сортировка вставками---- " << std::endl;
    std::cout << "Длительность работы: " << duration.count() << " ms" << std::endl;
    std::cout << "Количество сравнений: " << k << std::endl;
}

void selectionSort (const int *num, int size) {
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

    std::cout << "----Сортировка выбором---- " << std::endl;
    std::cout << "Длительность работы: " << duration.count() << " ms" << std::endl;
    std::cout << "Количество сравнений: " << k << std::endl;
}

int main() {

    int N = 70;
    int a[N];


    std::random_device rd;
    std::mt19937 mt(rd());
    std::vector  <std::vector <int>>  V(2*N+1, std::vector <int> (N) );
    for(int i=0;i < N;i++){ V[N][i] = mt()%(N);}
    for(int j=N+1;j < 2*N+1;j++){
        V[j][0] = V[j-1][0];
        for(int i=1;i < N;i++){
            if(V[j-1][i]>V[j][i-1]){
                V[j][i] = V[j-1][i];
            }
            else{
                V[j][i] = V[j][i-1];
                V[j][i-1] = V[j-1][i];
            }
        }
    }


    for(int j=N-1; j > -1; j--){
        V[j][N-1] = V[j+1][N-1];
        for(int i=N-2; i > -1; i--){
            if(V[j+1][i]>V[j][i+1]){
                V[j][i] = V[j+1][i];
            }
            else{
                V[j][i] = V[j][i+1];
                V[j][i+1] = V[j+1][i];
            }
        }
    }

//    for(int i = 0; i < 2 * N + 1; i++){
//        for(int j = 0; j < N; j++){
//            std::cout << V[i][j] << '\t';
//        }
//        std::cout << '\n';
//    }
    for(int i = 0; i < N; i++){
        a[i] = V[118][i];
        std::cout << a[i] << ' ';
    }
    bubbleSort(a, N);
    insertSort(a, N);
    selectionSort(a, N);

    return 0;
}