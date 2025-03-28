#ifndef MATRIX_MATH_OPERATION_DECORATOR_H
#define MATRIX_MATH_OPERATION_DECORATOR_H

#include "../core/matrix_core.h"
#include "./rounding_decorator.h"

#include "./CPlusPlus-Dependencies/random.h"

namespace matrix {
    template <typename T>
    class Matrix;
}

namespace matrix::decorators {

    template <typename T>
    class MathOperationsDecorator {
    private:
        core::MatrixCore<T>* _matrix;
        RoundingDecorator<T>* _roundingDecorator;

    public:
        MathOperationsDecorator();
        MathOperationsDecorator(core::MatrixCore<T>& m);
        ~MathOperationsDecorator();

    public:
        core::MatrixCore<T> getMinor(size_t row, size_t col) const;

        bool isDiagonalDominance() const;
        T norm(const std::vector<T>& vec) const;
        T determinant() const;

        matrix::Matrix<T> transpose() const;
        matrix::Matrix<T> inverse() const;

        T sum() const;
        T sumRow(size_t row) const;
        T sumColumn(size_t col) const;

 /*     std::vector<T> getMinInRows() const;
        std::vector<T> getMaxInRows() const;
        std::vector<T> getMinInCols() const;
        std::vector<T> getMaxInCols() const;*/

        void init(T min, T max, unsigned int precision = 2);
    };
}

#include "./math_operations_decorator.cpp"
#endif // !MATRIX_MATH_OPERATION_DECORATOR_H