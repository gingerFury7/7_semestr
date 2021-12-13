#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>

void filling_D (char *s, int size, int D[255]) {
    int i;

    for (i = 0; i <= 255; i++ ){
        D[i] = size;
    }

    for (i = 0; i < size - 1; i++){
        D[(int) s[i]] = size - i - 1;
    }
}

void search_BM (char *t, char *s){
    int n = strlen(t);
    int m = strlen(s);

    auto begin = std::chrono::high_resolution_clock::now();
    int D[255];
    filling_D(s, m, D);

    int j = m;
    int i = m;
    int res = -1;
    int k = 0;

    while (j > 0 && i < n) {
        j = m;
        res = i;
        while (j > 0 && t[res - 1] == s[j - 1]){
            res--;
            j--;
            k++;
        }
        k++;
        i += D[(int) t[i - 1]];
    };

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

    std::cout << "----Алгоритм Бойера-Мура----" << std::endl;
    std::cout << "Количество выполнений цикла: " << k << std::endl;
    std::cout << "Позиция в строке: " << res + 1 << std::endl;
    std::cout << duration.count() << std::endl;
}

void search_Direct(char *t, char *s){

    auto begin = std::chrono::high_resolution_clock::now();

    int n = strlen(t);
    int m = strlen(s);
    int res = -1;
    int k = 0;
    int i, j;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            k++;
            if (t[i + j] != s[j]) {
                break;
            }
        }
        if (j == m) {
            k++;
            res = i;
        }
    };

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);


    std::cout << "----Алгоритм \"Грубой силы\"----" << std::endl;
    std::cout << "Количество выполнений цикла: " << k << std::endl;
    std::cout << "Позиция в строке: " << res + 1 << std::endl;
    std::cout << duration.count() << std::endl;
}

int main(){
    srand(time(NULL));
    int n = 1000000;
    int m = 9;
    char txt[n];
    char s[m];
    for(int i = 0; i < n; i++)
        txt[i] = char('A' + rand() % ('D' - 'A'));
    for (int i = 0; i < m; i++)
        s[i]= char('A' + rand() % ('D' - 'A'));
    search_BM(txt, s);
    search_Direct(txt, s);
    return 0;
}