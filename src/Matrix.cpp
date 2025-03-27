#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "../include/matrix.h"

namespace matrix {

	template<typename T>
	inline matrix::Matrix<T>::Matrix(size_t rows, size_t cols)
		: core::MatrixCore<T>(rows, cols), arithmeticDecorator(*this) {
    }

	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& values)
		: core::MatrixCore<T>(values), arithmeticDecorator(*this) {
    }

	template<typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
	{
		core::MatrixCore<T> resultImpl = arithmeticDecorator + other;
		return Matrix<T>(resultImpl);
	}
}

#endif // !MATRIXL_CPP