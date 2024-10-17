#include "stdafx.h"
#include "Matrix.h"

int main() {
    SizeMatrix size1(3, 3);
    SizeMatrix size2;
    std::cin >> size2;

    Matrix<double> matrix1(size1);
    Matrix<double> matrix2(size2);
    Matrix<double> matrix3({
        { 1.0, 2.0, 3.0 },
        { 4.0, 5.0, 6.0 },
        { 7.0, 8.0, 9.0 }
    });

    matrix1.initRandomNumbers(-10.0, 10.0);
    matrix2.initRandomNumbers(1.0, 5.0);

    std::cout << "Matrix 1:\n" << matrix1 << "\n";
    std::cout << "Matrix 2:\n" << matrix2 << "\n";

    try {
        Matrix<double> sumMatrix = matrix1 + matrix2;
        std::cout << "Sum of Matrix 1 and Matrix 2:\n" << sumMatrix << "\n";
        matrix1 += matrix2;
        std::cout << "Matrix 1 after += Matrix 2:\n" << matrix1 << "\n";
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }


    matrix3 = matrix1 * 2.0;
    std::cout << "Matrix 3 (Matrix 1 * 2.0):\n" << matrix3 << "\n";

    Matrix<double> transposedMatrix = matrix1.transpose();
    std::cout << "Transposed Matrix 1:\n" << transposedMatrix << "\n";

    try {
        double det = matrix1.determinant();
        std::cout << "Determinant of Matrix 1: " << det << "\n";
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Matrix<double> invMatrix = matrix1.inverse();
        std::cout << "Inverse of Matrix 1:\n" << invMatrix << "\n";
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }

    std::vector<double> newRow = { 1.0, 2.0, 3.0 };
    matrix1.setRow(1, newRow);
    matrix1.setCol(2, { 4.0, 5.0, 6.0 });
    std::cout << "Matrix 1 after setting new row and column:\n" << matrix1 << "\n";

    std::vector<double> row = matrix1.getRow(1);
    std::vector<double> col = matrix1.getCol(2);
    std::cout << "Row 1 of Matrix 1: ";
    for (const auto& elem : row) std::cout << elem << " ";
    std::cout << "\nColumn 2 of Matrix 1: ";
    for (const auto& elem : col) std::cout << elem << " ";
    std::cout << "\n";

    return 0;
}