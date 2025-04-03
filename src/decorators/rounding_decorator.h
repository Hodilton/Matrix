#ifndef MATRIX_ROUNDING_DECORATOR_H
#define MATRIX_ROUNDING_DECORATOR_H

#include "../core/matrix_core.h"

#include <cmath>

namespace matrix {
    template <typename T>
    class Matrix;
}

namespace matrix::decorators {

    template <typename T>
    class RoundingDecorator {
    private:
        core::MatrixCore<T>* _matrix;

    public:
        RoundingDecorator();
        explicit RoundingDecorator(core::MatrixCore<T>& matrix);
        ~RoundingDecorator();

    public:
        void roundAll(unsigned int precision = 2);
        Matrix<T> getRounded(unsigned int precision = 2) const;

        void roundElement(size_t row, size_t col, unsigned int precision = 2);
        T getRoundedElement(size_t row, size_t col, unsigned int precision = 2) const;

        void roundRow(size_t row, unsigned int precision = 2);
        std::vector<T> getRoundedRow(size_t row, unsigned int precision = 2) const;

        void roundColumn(size_t col, unsigned int precision = 2);
        std::vector<T> getRoundedColumn(size_t col, unsigned int precision = 2) const;

        void allElementsEqualToZero() const;
        Matrix<T> getAllElementsEqualToZero() const;

        static Matrix<T> roundMatrix(const Matrix<T>& matrix, unsigned int precision = 2);

    private:
        T roundValue(T value, unsigned int precision) const;

        static constexpr T EPSILON = 1e-6;
        bool isEqual(T a, T b) const;
    };
}

#include "./rounding_decorator.cpp"
#endif // !MATRIX_ROUNDING_DECORATOR_H