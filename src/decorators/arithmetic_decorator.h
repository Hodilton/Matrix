#ifndef MATRIX_ARITHMETIC_DECORATOR_H
#define MATRIX_ARITHMETIC_DECORATOR_H

#include "../core/matrix_core.h"
#include "./rounding_decorator.h"

namespace matrix {
    template <typename T>
    class Matrix;
}

namespace matrix::decorators {

    template <typename T>
    class ArithmeticDecorator {
    private:
        core::MatrixCore<T>* _matrix;
        RoundingDecorator<T>* _roundingDecorator;

    public:
        ArithmeticDecorator();
        explicit ArithmeticDecorator(core::MatrixCore<T>& m);
        ~ArithmeticDecorator();

    public:
        core::MatrixCore<T> operator+(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator-(const core::MatrixCore<T>& other) const;
        Matrix<T> operator*(const Matrix<T>& other) const;

        core::MatrixCore<T> operator+(const T& value) const;
        core::MatrixCore<T> operator-(const T& value) const;
        core::MatrixCore<T> operator*(const T& value) const;
        core::MatrixCore<T> operator/(const T& value) const;

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