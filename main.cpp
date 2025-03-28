#include "./include/Matrix.h"

#include <iostream>
#include <Windows.h>
using namespace matrix;

int main() {
    SetConsoleOutputCP(1251);

    Matrix<double> matrix({
       {2, -1, 0},
       {1,  3, 2},
       {0,  1, 1}
    });

    std::cout << "Исходная матрица:\n" << matrix << "\n";
    double det = matrix.math->determinant();
    std::cout << "Определитель: " << det << std::endl;

    Matrix<double> matrix_inv = matrix.math->inverse();
    std::cout << matrix_inv << std::endl;

    Matrix<double> I = matrix * matrix_inv;
    std::cout << "Единичная матрица:\n" << I << "\n";

	return 0;
}