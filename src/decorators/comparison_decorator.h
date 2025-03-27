#pragma once

#include "../core/matrix_impl.h"

namespace Matrix::Decorators {

    template <typename T>
    class ComparisonDecorator : public Core::MatrixImpl<T> {
    public:
        using Core::MatrixImpl<T>::MatrixImpl;

        bool operator==(const Matrix<T>& other) const;
        bool operator!=(const Matrix<T>& other) const;
        bool operator<(const Matrix<T>& other) const;
        bool operator<=(const Matrix<T>& other) const;
        bool operator>(const Matrix<T>& other) const;
        bool operator>=(const Matrix<T>& other) const;
    };
}