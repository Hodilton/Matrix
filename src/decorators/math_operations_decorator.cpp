#ifndef MATRIX_MATH_OPERATION_DECORATOR_CPP
#define MATRIX_MATH_OPERATION_DECORATOR_CPP
#include "./math_operations_decorator.h"

namespace matrix::decorators {

	template <typename T>
	MathOperationsDecorator<T>::MathOperationsDecorator()
		: _matrix(nullptr), _roundingDecorator(nullptr) {
	}

	template <typename T>
	MathOperationsDecorator<T>::MathOperationsDecorator(core::MatrixCore<T>& m)
		: _matrix(&m) {
		_roundingDecorator = new RoundingDecorator<T>(m);
	}

	template<typename T>
	MathOperationsDecorator<T>::~MathOperationsDecorator() {
		delete _roundingDecorator;
	}

	template<typename T>
	core::MatrixCore<T> MathOperationsDecorator<T>::getMinor(size_t row, size_t col) const {
		if (_matrix->getRows() <= 1 || _matrix->getCols() <= 1) {
			throw std::runtime_error("Matrix too small for minor.");
		}

		core::MatrixCore<T> minorMatrix(_matrix->getRows() - 1, _matrix->getCols() - 1);
		size_t newRow = 0, newCol = 0;

		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			if (i == row) continue;
			newCol = 0;
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if (j == col) continue;
				minorMatrix(newRow, newCol) = (*_matrix)(i, j);
				newCol++;
			} newRow++;
		} return minorMatrix;
	}

	template<typename T>
	bool MathOperationsDecorator<T>::isDiagonalDominance() const {
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			T diagonalElement = std::abs((*_matrix)(i, i));
			T sumRow = 0;
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				if (i != j) {
					sumRow += std::abs((*_matrix)(i, j));
				}
			}
			if (diagonalElement < sumRow) {
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
	T MathOperationsDecorator<T>::determinant() const {
		if (_matrix->getRows() != _matrix->getCols()) {
			throw std::runtime_error("Determinant can only be calculated for square matrices.");
		}

		size_t n = _matrix->getRows();
		if (n == 1) return (*_matrix)(0, 0);
		if (n == 2) return (*_matrix)(0, 0) * (*_matrix)(1, 1) - (*_matrix)(0, 1) * (*_matrix)(1, 0);

		T det = 0;
		for (size_t col = 0; col < n; ++col) {
			core::MatrixCore<T> minor = getMinor(0, col);
			MathOperationsDecorator<T> minorDecorator(minor);
			det += (col % 2 == 0 ? 1 : -1) * (*_matrix)(0, col) * minorDecorator.determinant();
		} return det;
	}

	template<typename T>
	matrix::Matrix<T> MathOperationsDecorator<T>::transpose() const {
		matrix::Matrix<T> transposed(_matrix->getCols(), _matrix->getRows());
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				transposed(j, i) = (*_matrix)(i, j);
			}
		} return transposed;
	}

	template<typename T>
	matrix::Matrix<T> MathOperationsDecorator<T>::inverse() const {
		T det = determinant();
		if (det == 0) {
			throw std::runtime_error("Matrix is singular and cannot be inverted.");
		}

		size_t n = _matrix->getRows();
		matrix::Matrix<T> adjugate(n, n);

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < n; ++j) {
				core::MatrixCore<T> minor = getMinor(i, j);
				MathOperationsDecorator<T> minorDecorator(minor);
				T cofactor = ((i + j) % 2 == 0 ? 1 : -1) * minorDecorator.determinant();
				adjugate(j, i) = cofactor / det;
			}
		} return adjugate;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sum() const {
		T sum = 0;
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				sum += (*_matrix)(i, j);
			}
		} return sum;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sumRow(size_t row) const {
		T sum = 0;
		for (const T& val : _matrix->getRow(row)) {
			sum += val;
		} return sum;
	}

	template<typename T>
	T MathOperationsDecorator<T>::sumColumn(size_t col) const {
		T sum = 0;
		for (const T& val : _matrix->getCol(col)) {
			sum += val;
		} return sum;
	}
	
	template<typename T>
	void MathOperationsDecorator<T>::init(T min, T max, unsigned int precision) {
		auto gen = random::Factory::create<random::Type::Double>();
		for (size_t i = 0; i < _matrix->getRows(); ++i) {
			for (size_t j = 0; j < _matrix->getCols(); ++j) {
				T randValue = gen->Get(min, max, precision);
				(*_matrix)(i, j) = randValue;
			}
		}
	}
}

#endif // !MATRIX_MATH_OPERATION_DECORATOR_CPP