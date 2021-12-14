#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE_FIELD = 7;

int masX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int masY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void Print (int mas[][SIZE_FIELD]){
    for (int i = 0; i < SIZE_FIELD; i++) {
        for (int j = 0; j < SIZE_FIELD; j++){
            cout << setw(3) << mas[i][j];
        }
        cout << "\n";
    }
}

void Horse (int mas[][SIZE_FIELD], int num, int i0, int j0) {
    static int kol = 0;
    kol++;
    mas[i0][j0] = num++;
    for (int i = 0; i < 8; i++){
        int iNew = i0 + masY[i];
        int jNew = j0 + masX[i];

        if(num > SIZE_FIELD * SIZE_FIELD){
            cout << kol << "\n";
            Print(mas);
            exit(0);
        }
        if ((iNew < 0) || (iNew > SIZE_FIELD - 1) || (jNew < 0) || (jNew > SIZE_FIELD - 1) || (mas[iNew][jNew] != 0))
            continue;
        Horse(mas, num, iNew, jNew);
        mas[iNew][jNew] = 0;
    }
}


int main() {
    int Matr[SIZE_FIELD][SIZE_FIELD] = {};
    Horse(Matr, 1, 0, 6);

    return 0;
}
