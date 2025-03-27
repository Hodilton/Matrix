#ifndef MATRIX_DECORATORS_H
#define MATRIX_DECORATORS_H

#include "../core/matrix_impl.h"

namespace matrix::decorators {

    template <typename T>
    class ArithmeticDecorator {
    private:
        core::MatrixImpl<T>& matrix;

    public:
        explicit ArithmeticDecorator(core::MatrixImpl<T>& m);

        core::MatrixImpl<T> operator+(const core::MatrixImpl<T>& other) const;
        core::MatrixImpl<T> operator-(const core::MatrixImpl<T>& other) const;
        core::MatrixImpl<T> operator*(const core::MatrixImpl<T>& other) const;
        core::MatrixImpl<T> operator+(const T& value) const;
        core::MatrixImpl<T> operator-(const T& value) const;
        core::MatrixImpl<T> operator*(const T& value) const;
        core::MatrixImpl<T> operator/(const T& value) const;
    };
}

#include "./arithmetic_decorator.cpp"
#endif // !MATRIX_DECORATORS_H