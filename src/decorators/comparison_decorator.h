#ifndef MATRIX_COMPARISON_DECORATOR_H
#define MATRIX_COMPARISON_DECORATOR_H

#include "../core/matrix_core.h"

#include <cmath>

namespace matrix {
    template <typename T>
    class Matrix;
}

namespace matrix::decorators {

    template <typename T>
    class ComparisonDecorator {
    private:
        core::MatrixCore<T>* _matrix;

    public:
        ComparisonDecorator();
        explicit ComparisonDecorator(core::MatrixCore<T>& matrix);
        ~ComparisonDecorator();

    public:
        bool isSameSize(const Matrix<T>& other) const;

        bool isSquare() const;
        bool isSymmetric() const;
        bool isZero() const;
        bool isIdentity() const;

    public:
        bool operator==(const Matrix<T>& other) const;
        bool operator!=(const Matrix<T>& other) const;
        bool operator<(const Matrix<T>& other) const;
        bool operator<=(const Matrix<T>& other) const;
        bool operator>(const Matrix<T>& other) const;
        bool operator>=(const Matrix<T>& other) const;

    private:
        static constexpr T EPSILON = 1e-6;
        bool isEqual(T a, T b) const;
    };
}

#include "./comparison_decorator.cpp"
#endif // !MATRIX_COMPARISON_DECORATOR_H