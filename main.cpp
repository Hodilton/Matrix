#include "./include/Matrix.h"

#include <iostream>

int main() {
    matrix::Matrix<int> m1(2, 2);
    matrix::Matrix<int> m2(2, 2);

    std::cout << "Address of MatrixImpl in m1: " << &m1.getMatrixImpl() << std::endl;
    std::cout << "Address of ArithmeticDecorator in m1: " << &m1.getArithmeticDecorator() << std::endl;

    std::cout << "Address of MatrixImpl in m2: " << &m2.getMatrixImpl() << std::endl;
    std::cout << "Address of ArithmeticDecorator in m2: " << &m2.getArithmeticDecorator() << std::endl;

	return 0;
}