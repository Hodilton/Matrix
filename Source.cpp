#include "stdafx.h"
#include "CMatrix.h"

int main() {
    srand(unsigned(time(NULL)));

    CMatrix<int> matrixOne(3, 2);
    matrixOne.InititalizeRandomNumbers();
    cout << matrixOne << endl;

    cout << matrixOne(1, 1) << endl;
    cout << matrixOne(5, 1) << endl;

    CMatrix<int> matrixSecond(2, 3);
    matrixSecond.InititalizeRandomNumbers();
    cout << matrixSecond << endl;

    CMatrix<int> matrixResult = matrixOne * matrixSecond;
    cout << matrixResult << endl;

    return 0;
}