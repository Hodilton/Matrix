#pragma once

namespace matrix {

    class Size {
    private:
        size_t _rows;
        size_t _cols;

    public:
        Size();
        Size(size_t rows, size_t cols);

    public:
        size_t getRows() const;
        size_t getCols() const;
    };
}