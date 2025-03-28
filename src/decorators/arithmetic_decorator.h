#ifndef MATRIX_ARITHMETIC_DECORATOR_H
#define MATRIX_ARITHMETIC_DECORATOR_H

#include "../core/matrix_core.h"

namespace matrix::decorators {

    template <typename T>
    class ArithmeticDecorator {
    private:
        core::MatrixCore<T>* _matrix;

    public:
        ArithmeticDecorator();
        explicit ArithmeticDecorator(core::MatrixCore<T>& m);

    public:
        core::MatrixCore<T> operator+(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator-(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator*(const core::MatrixCore<T>& other) const;

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