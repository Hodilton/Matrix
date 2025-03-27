#ifndef MATRIX_IMPL_H
#define MATRIX_IMPL_H

#include "./size.h"

#include <vector>

namespace matrix::core {

    template <typename T>
    class MatrixImpl {
    protected:
        Size _size;
        std::vector<std::vector<T>> _elements;
        
    public:
        MatrixImpl(size_t rows, size_t cols);
        MatrixImpl(const std::vector<std::vector<T>>& values);

    public:
        size_t getRows() const;
        size_t getCols() const;
        Size getSize() const;

        T& operator()(size_t row, size_t col);
        const T& operator()(size_t row, size_t col) const;
    };
}

#include "./matrix_impl.cpp"
#endif // !MATRIX_IMPL_H