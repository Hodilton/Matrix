#ifndef MATRIX_H
#define MATRIX_H

#include "../src/core/size.h"
#include "../src/core/matrix_core.h"

#include "../src/decorators/arithmetic_decorator.h"
//#include "../src/decorators/comparison_decorator.h"
//#include "../src/decorators/math_operations_decorator.h"
//#include "../src/decorators/serialization_decorator.h"

namespace matrix {

    template <typename T>
    class Matrix : public core::MatrixCore<T>{
    private:
        decorators::ArithmeticDecorator<T> arithmeticDecorator;
        //std::unique_ptr<Decorators::ComparisonDecorator<T>> comparisonDecorator;
        //std::unique_ptr<Decorators::MathOperationsDecorator<T>> mathOperationsDecorator;
        //std::unique_ptr<Decorators::SerializationDecorator<T>> serializationDecorator;

    public:
        Matrix(size_t rows, size_t cols);
        Matrix(const std::vector<std::vector<T>>& values);

        Matrix<T> operator+(const Matrix<T>& other) const;
        //Matrix<T> operator-(const Matrix<T>& other) const;
        //Matrix<T> operator*(const Matrix<T>& other) const;
        //Matrix<T> operator+(const T& value) const;
        //Matrix<T> operator-(const T& value) const;
        //Matrix<T> operator*(const T& value) const;
        //Matrix<T> operator/(const T& value) const;

        //bool operator==(const Matrix<T>& other) const;
        //bool operator!=(const Matrix<T>& other) const;
        //bool operator<(const Matrix<T>& other) const;
        //bool operator<=(const Matrix<T>& other) const;
        //bool operator>(const Matrix<T>& other) const;
        //bool operator>=(const Matrix<T>& other) const;

        //Matrix<T> transpose() const;
        //T determinant() const;
        //Matrix<T> inverse() const;
        //T sum() const;
        //T sumRow(size_t row) const;
        //T sumColumn(size_t col) const;

        //json toJson() const;
        //static Matrix<T> fromJson(const json& j);
    };
}

#include "../src/matrix.cpp"
#endif // !MATRIX_H