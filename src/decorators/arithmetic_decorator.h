#ifndef MATRIX_DECORATORS_H
#define MATRIX_DECORATORS_H

#include "../core/matrix_core.h"

namespace matrix::decorators {

    template <typename T>
    class ArithmeticDecorator {
    public:
        core::MatrixCore<T>& matrix;

    public:
        explicit ArithmeticDecorator(core::MatrixCore<T>& m);

        core::MatrixCore<T> operator+(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator-(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator*(const core::MatrixCore<T>& other) const;
        core::MatrixCore<T> operator+(const T& value) const;
        core::MatrixCore<T> operator-(const T& value) const;
        core::MatrixCore<T> operator*(const T& value) const;
        core::MatrixCore<T> operator/(const T& value) const;
    };
}

#include "./arithmetic_decorator.cpp"
#endif // !MATRIX_DECORATORS_H