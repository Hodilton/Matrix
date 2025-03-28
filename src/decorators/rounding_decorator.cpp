#ifndef MATRIX_ROUNDING_DECORATOR_CPP
#define MATRIX_ROUNDING_DECORATOR_CPP
#include "rounding_decorator.h"

namespace matrix::decorators {

    template <typename T>
    RoundingDecorator<T>::RoundingDecorator()
        : _matrix(nullptr) {
    }

    template <typename T>
    RoundingDecorator<T>::RoundingDecorator(core::MatrixCore<T>& m)
        : _matrix(&m) {
    }

    template <typename T>
    T RoundingDecorator<T>::roundValue(T value, unsigned int precision) const {
        T factor = std::pow(10, precision);
        return std::round(value * factor) / factor;
    }

    template<typename T>
    bool RoundingDecorator<T>::isEqual(T a, T b) const {
        return std::fabs(a - b) < EPSILON;
    }

    template <typename T>
    void RoundingDecorator<T>::roundAll(unsigned int precision) {
        for (size_t i = 0; i < _matrix->getRows(); ++i) {
            for (size_t j = 0; j < _matrix->getCols(); ++j) {
                (*_matrix)(i, j) = roundValue((*_matrix)(i, j), precision);
            }
        }
    }

    template <typename T>
    core::MatrixCore<T> RoundingDecorator<T>::getRounded(unsigned int precision) const {
        core::MatrixCore<T> roundedMatrix = *_matrix;
        RoundingDecorator<T> tempDecorator(roundedMatrix);
        tempDecorator.roundAll(precision);
        return roundedMatrix;
    }

    template <typename T>
    void RoundingDecorator<T>::roundElement(size_t row, size_t col, unsigned int precision) {
        (*_matrix)(row, col) = roundValue((*_matrix)(row, col), precision);
    }

    template <typename T>
    T RoundingDecorator<T>::getRoundedElement(size_t row, size_t col, unsigned int precision) const {
        return roundValue((*_matrix)(row, col), precision);
    }

    template <typename T>
    void RoundingDecorator<T>::roundRow(size_t row, unsigned int precision) {
        for (size_t j = 0; j < _matrix->getCols(); ++j) {
            (*_matrix)(row, j) = roundValue((*_matrix)(row, j), precision);
        }
    }

    template <typename T>
    std::vector<T> RoundingDecorator<T>::getRoundedRow(size_t row, unsigned int precision) const {
        std::vector<T> roundedRow = _matrix->getRow(row);
        for (T& val : roundedRow) {
            val = roundValue(val, precision);
        }
        return roundedRow;
    }

    template <typename T>
    void RoundingDecorator<T>::roundColumn(size_t col, unsigned int precision) {
        for (size_t i = 0; i < _matrix->getRows(); ++i) {
            (*_matrix)(i, col) = roundValue((*_matrix)(i, col), precision);
        }
    }

    template <typename T>
    std::vector<T> RoundingDecorator<T>::getRoundedColumn(size_t col, unsigned int precision) const {
        std::vector<T> roundedCol = _matrix->getCol(col);
        for (T& val : roundedCol) {
            val = roundValue(val, precision);
        }
        return roundedCol;
    }

    template<typename T>
    void RoundingDecorator<T>::allElementsEqualToZero() const {
        for (size_t i = 0; i < _matrix->getRows(); ++i) {
            for (size_t j = 0; j < _matrix->getCols(); ++j) {
                if (isEqual((*_matrix)(i, j), T(0))) {
                    (*_matrix)(i, j) = T(0);
                }
            }
        }
    }

    template <typename T>
    core::MatrixCore<T> RoundingDecorator<T>::roundMatrix(const core::MatrixCore<T>& matrix, unsigned int precision) {
        core::MatrixCore<T> roundedMatrix = matrix;
        RoundingDecorator<T> tempDecorator(roundedMatrix);
        tempDecorator.roundAll(precision);
        return roundedMatrix;
    }
}

#endif // !MATRIX_ROUNDING_DECORATOR_CPP