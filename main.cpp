#include "./include/Matrix.h"

#include <Windows.h>
using namespace matrix;

int main() {
    SetConsoleOutputCP(1251);

    Matrix<double> matrix({
       {2, -1, 0},
       {1,  3, 2},
       {0,  1, 1}
    });

    std::cout << "Исходная матрица:\n" << matrix << std::endl;
    std::cout << "Определитель: " << matrix.math->determinant() << std::endl;

    Matrix<double> matrix_inv = matrix.math->inverse();
    std::cout << "\nОбратная матрица:\n" << matrix_inv << std::endl;

    Matrix<double> matrix_i = matrix * matrix_inv; matrix_i.rounder->allElementsEqualToZero();
    std::cout << "Исходная * Обратная:\n" << matrix_i << std::endl;

	return 0;
}