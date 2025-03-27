#pragma once

#include "../core/matrix_impl.h"

namespace Matrix::Decorators {

    template <typename T>
    class MathOperationsDecorator : public Core::MatrixImpl<T> {
    public:
        using Core::MatrixImpl<T>::MatrixImpl;

        Matrix<T> transpose() const;
        T determinant() const;
        Matrix<T> inverse() const;

        T sum() const;
        T sumRow(size_t row) const;
        T sumColumn(size_t col) const;
    };
}