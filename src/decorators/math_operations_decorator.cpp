#ifndef MATRIX_MATH_OPERATION_DECORATOR_CPP
#define MATRIX_MATH_OPERATION_DECORATOR_CPP
#include "./math_operations_decorator.h"

namespace matrix::decorators {

	template <typename T>
	MathOperationsDecorator<T>::MathOperationsDecorator()
		: _matrix(nullptr) {
	}

	template <typename T>
	MathOperationsDecorator<T>::MathOperationsDecorator(core::MatrixCore<T>& matrix)
		: _matrix(&matrix) {
	}

	template<typename T>
	MathOperationsDecorator<T>::~MathOperationsDecorator() {
	}

	template<typename T>
	Matrix<T> MathOperationsDecorator<T>::getMinor(size_t row, size_t col) const {
		const size_t rows = _matrix->getRows();
		const size_t cols = _matrix->getCols();

		if (rows <= 1 || cols <= 1) {
			throw std::runtime_error("Matrix too small for minor.");
		}

		Matrix<T> minor(rows - 1, cols - 1);
		size_t minorRow = 0, minorCol = 0;

		for (size_t i = 0; i < rows; ++i) {
			if (i == row) continue;
			minorCol = 0;
			for (size_t j = 0; j < cols; ++j) {
				if (j == col) continue;
				minor(minorRow, minorCol) = (*_matrix)(i, j);
				minorCol++;
			} minorRow++;
		} return minor;
	}

	template<typename T>
	bool MathOperationsDecorator<T>::isDiagonalDominance() const {
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			T diag = std::abs((*_matrix)(i, i));
			T sumRow = 0;
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if (i != j) {
					sumRow += std::abs((*_matrix)(i, j));
				}
			}
			if (diag < sumRow) {
				return false;
			}
		} return true;
	}

	template<typename T>
	T MathOperationsDecorator<T>::norm(const std::vector<T>& vec) const {
		T sum = 0;
		for (const T& val : vec) {
			sum += val * val;
		} return std::sqrt(sum);
	}

	template<typename T>
	T MathOperationsDecorator<T>::normSquared() const {
		T sum = 0;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				sum += (*_matrix)(i, j) * (*_matrix)(i, j);
			}
		} return sum;
	}	

	template<typename T>
	T MathOperationsDecorator<T>::determinant() const {
		if (_matrix->getRows() != _matrix->getCols()) {
			throw std::runtime_error("Determinant can only be calculated for square matrices.");
		}

		size_t n = _matrix->getRows();
		if (n == 1) return (*_matrix)(0, 0);
		if (n == 2) {
			return (*_matrix)(0, 0) * (*_matrix)(1, 1)
				 - (*_matrix)(0, 1) * (*_matrix)(1, 0);
		}

		T det = 0;
		for (size_t col = 0; col < n; ++col) {
			Matrix<T> minor = getMinor(0, col);
			det += (col % 2 == 0 ? 1 : -1)
				 * (*_matrix)(0, col)
				 * minor.math->determinant();
		} return det;
	}

	template<typename T>
	Matrix<T> MathOperationsDecorator<T>::transpose() const {
		Matrix<T> transposed(_matrix->getCols(), _matrix->getRows());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				transposed(j, i) = (*_matrix)(i, j);
			}
		} return transposed;
	}

	template<typename T>
	Matrix<T> MathOperationsDecorator<T>::inverse() const {
		T det = determinant();
		if (det == 0) {
			throw std::runtime_error("Matrix is singular and cannot be inverted.");
		}

		size_t n = _matrix->getRows();
		Matrix<T> adjugate(n, n);

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < n; ++j) {
				Matrix<T> minor = getMinor(i, j);
				T factor = ((i + j) % 2 == 0 ? 1 : -1) * minor.math->determinant();
				adjugate(j, i) = factor / det;
			}
		} return adjugate;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sum() const {
		T total = 0;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				total += (*_matrix)(i, j);
			}
		} return total;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sumRow(size_t row) const {
		T total = 0;
		for (const T& val : _matrix->getRow(row)) {
			total += val;
		} return total;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sumColumn(size_t col) const {
		T total = 0;
		for (const T& val : _matrix->getCol(col)) {
			total += val;
		} return total;
	}
	
	template<typename T>
	void MathOperationsDecorator<T>::init(T min, T max, unsigned int precision) {
		auto gen = random::Factory::create<random::Type::Double>();
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				T value = gen->Get(min, max, precision);
				(*_matrix)(i, j) = value;
			}
		}
	}
}

#endif // !MATRIX_MATH_OPERATION_DECORATOR_CPP