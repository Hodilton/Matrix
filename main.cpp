#include "./include/Matrix.h"

#include <iostream>

void testMatrix() {
    using namespace matrix;

    Matrix<int> m1;
    Matrix<int> m2(3, 4);

    Size size(2, 3);
    Matrix<int> m3(size);

    std::vector<std::vector<int>> values = { {1, 2, 3}, {4, 5, 6} };
    Matrix<int> m4(values);

    Matrix<int> m5(m4);

    m4(0, 1) = 99;
    m4.resize(4, 5);
}

int main() {
    testMatrix();

	return 0;
}