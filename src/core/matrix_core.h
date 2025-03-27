#ifndef MATRIX_CORE_H
#define MATRIX_CORE_H

#include "./size.h"

#include <vector>
#include <stdexcept>

namespace matrix::core {

    template <typename T>
    class MatrixCore {
    protected:
        Size _size;
        std::vector<std::vector<T>> _elements;
        
    public:
        MatrixCore();
        MatrixCore(size_t rows, size_t cols);
        MatrixCore(Size size);
        MatrixCore(const std::vector<std::vector<T>>& values);
        MatrixCore(const MatrixCore<T>& other);
        ~MatrixCore();

    public:
        size_t getRows() const;
        size_t getCols() const;
        Size getSize() const;

        std::vector<T> getRow(size_t row) const;
        std::vector<T> getCol(size_t col) const;
        void setRow(size_t rowIndex, const std::vector<T>& values);
        void setCol(size_t colIndex, const std::vector<T>& values);

        void resize(size_t newRows, size_t newCols);

        T& operator()(size_t row, size_t col);
        const T& operator()(size_t row, size_t col) const;

    private:
        void takeMemory();
        void freeMemory();
        void init();
    };
}

#include "./matrix_core.cpp"
#endif // !MATRIX_CORE_H