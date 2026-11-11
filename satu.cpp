#include <iostream>
using namespace std;

int main() {
    int array[2][3][4];

    int angka = 2;

    for (int i = 0; i < 2; i++){
        if(i >= 1){
            angka = 1;
        }
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                array[i][j][k] = angka;
                angka += 2;
            }
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                cout << array[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                cout << array[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}