#ifndef MATRIX_SIZE_H
#define MATRIX_SIZE_H

namespace matrix {

    class Size {
    private:
        size_t _rows;
        size_t _cols;

    public:
        Size() : _rows(1), _cols(1) { }
        Size(size_t rows, size_t cols) : _rows(rows), _cols(cols) { }

    public:
        size_t getRows() const { return _rows; }
        size_t getCols() const { return _cols; }
    };
}

#endif // MATRIX_SIZE_H