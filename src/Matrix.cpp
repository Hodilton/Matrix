#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "../include/matrix.h"

namespace matrix {

	template<typename T>
	inline matrix::Matrix<T>::Matrix(size_t rows, size_t cols)
		: core::MatrixImpl<T>(rows, cols), arithmeticDecorator(*this) {
    }

	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& values)
		: core::MatrixImpl<T>(values), arithmeticDecorator(*this) {
    }

	template<typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
	{
		core::MatrixImpl<T> resultImpl = arithmeticDecorator + other;
		return Matrix<T>(resultImpl);
	}

    template<typename T>
    core::MatrixImpl<T>& Matrix<T>::getMatrixImpl() {
        return *this;
    }

    template<typename T>
    decorators::ArithmeticDecorator<T>& Matrix<T>::getArithmeticDecorator() {
        return arithmeticDecorator;
    }
}

#endif // !MATRIXL_CPP