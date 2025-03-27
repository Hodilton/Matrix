#ifndef MATRIX_CORE_H
#define MATRIX_CORE_H

#include "./size.h"

#include <vector>

namespace matrix::core {

    template <typename T>
    class MatrixCore {
    protected:
        Size _size;
        std::vector<std::vector<T>> _elements;
        
    public:
        MatrixCore(size_t rows, size_t cols);
        MatrixCore(const std::vector<std::vector<T>>& values);

    public:
        size_t getRows() const;
        size_t getCols() const;
        Size getSize() const;

        T& operator()(size_t row, size_t col);
        const T& operator()(size_t row, size_t col) const;
    };
}

#include "./matrix_core.cpp"
#endif // !MATRIX_CORE_H