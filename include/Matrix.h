#ifndef MATRIX_H
#define MATRIX_H

#include "../src/core/matrix_core.h"

#include "../src/decorators/arithmetic_decorator.h"
#include "../src/decorators/comparison_decorator.h"
#include "../src/decorators/math_operations_decorator.h"
#include "../src/decorators/serialization_decorator.h"
#include "../src/decorators/rounding_decorator.h"

namespace matrix {

    template <typename T>
    class Matrix {
    private:
        core::MatrixCore<T>* _core;
        decorators::ArithmeticDecorator<T>* _arithmetic;
        decorators::ComparisonDecorator<T>* _comparison;
        decorators::SerializationDecorator<T>* _serialization;

    public:
        decorators::MathOperationsDecorator<T>* math;
        decorators::RoundingDecorator<T>* rounder;

    public:
        Matrix();
        Matrix(size_t rows, size_t cols);
        Matrix(const Size& size);
        Matrix(const std::vector<std::vector<T>>& values);
        Matrix(const Matrix<T>& other);
        ~Matrix();

    private:
        void initDecorators();

    public:
        size_t getRows() const;
        size_t getCols() const;
        Size getSize() const;

        std::vector<T> getRow(size_t row) const;
        std::vector<T> getCol(size_t col) const;
        void setRow(size_t rowIndex, const std::vector<T>& values);
        void setCol(size_t colIndex, const std::vector<T>& values);

        void resize(size_t newRows, size_t newCols);

        bool isSquare() const;
        bool isSymmetric() const;
        bool isZero() const;
        bool isIdentity() const;

        T& operator()(size_t row, size_t col);
        const T& operator()(size_t row, size_t col) const;

    public:
        Matrix<T> operator+(const Matrix<T>& other) const;
        Matrix<T> operator-(const Matrix<T>& other) const;
        Matrix<T> operator*(const Matrix<T>& other) const;

        Matrix<T> operator+(const T& value) const;
        Matrix<T> operator-(const T& value) const;
        Matrix<T> operator*(const T& value) const;
        Matrix<T> operator/(const T& value) const;

        Matrix<T>& operator+=(const Matrix<T>& other);
        Matrix<T>& operator-=(const Matrix<T>& other);
        Matrix<T>& operator*=(const Matrix<T>& other);

        Matrix<T>& operator+=(const T& value);
        Matrix<T>& operator-=(const T& value);
        Matrix<T>& operator*=(const T& value);
        Matrix<T>& operator/=(const T& value);

    public:
        bool operator==(const Matrix<T>& other) const;
        bool operator!=(const Matrix<T>& other) const;
        bool operator<(const Matrix<T>& other) const;
        bool operator<=(const Matrix<T>& other) const;
        bool operator>(const Matrix<T>& other) const;
        bool operator>=(const Matrix<T>& other) const;

    public:
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
        template<typename U>
        friend std::istream& operator>>(const std::istream& in, Matrix<U>& matrix);
    };
}

#include "../src/matrix.cpp"
#endif // !MATRIX_H