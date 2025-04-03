#ifndef MATRIX_ARITHMETIC_DECORATOR_H
#define MATRIX_ARITHMETIC_DECORATOR_H

#include "../core/matrix_core.h"

namespace matrix {
    template <typename T>
    class Matrix;
}

namespace matrix::decorators {

    template <typename T>
    class ArithmeticDecorator {
    private:
        core::MatrixCore<T>* _matrix;

    public:
        ArithmeticDecorator();
        explicit ArithmeticDecorator(core::MatrixCore<T>& matrix);
        ~ArithmeticDecorator();

    public:
        Matrix<T> operator+(const Matrix<T>& other) const;
        Matrix<T> operator-(const Matrix<T>& other) const;
        Matrix<T> operator*(const Matrix<T>& other) const;

        Matrix<T> operator+(const T& value) const;
        Matrix<T> operator-(const T& value) const;
        Matrix<T> operator*(const T& value) const;
        Matrix<T> operator/(const T& value) const;

        ArithmeticDecorator<T>& operator+=(const core::MatrixCore<T>& other);
        ArithmeticDecorator<T>& operator-=(const core::MatrixCore<T>& other);
        ArithmeticDecorator<T>& operator*=(const core::MatrixCore<T>& other);

        ArithmeticDecorator<T>& operator+=(const T& value);
        ArithmeticDecorator<T>& operator-=(const T& value);
        ArithmeticDecorator<T>& operator*=(const T& value);
        ArithmeticDecorator<T>& operator/=(const T& value);
    };
}

#include "./arithmetic_decorator.cpp"
#endif // !MATRIX_ARITHMETIC_DECORATOR_H