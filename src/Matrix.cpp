#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "../include/matrix.h"

namespace matrix {

	template<typename T>
	Matrix<T>::Matrix()
		: _core(new core::MatrixCore<T>()) {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::Matrix(size_t rows, size_t cols)
		: _core(new core::MatrixCore<T>(rows, cols)) {
		initDecorators();
    }

	template<typename T>
	Matrix<T>::Matrix(const Size& size)
		: _core(new core::MatrixCore<T>(size)) {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::Matrix(const std::vector<std::vector<T>>& values)
		: _core(new core::MatrixCore<T>(values)) {
		initDecorators();
    }

	template<typename T>
	Matrix<T>::Matrix(const Matrix<T>& other)
		: _core(new core::MatrixCore<T>(*other._core)) {
		initDecorators();
	}

	template<typename T>
	Matrix<T>::~Matrix() {
        delete _core;
		delete _arithmetic;
        delete _comparison;
		delete _serialization;

        delete math;
        delete rounder;

        this->_core->~MatrixCore();
	}

	template<typename T>
	void Matrix<T>::initDecorators() {
		_arithmetic = new decorators::ArithmeticDecorator<T>(*_core);
        _comparison = new decorators::ComparisonDecorator<T>(*_core);
		_serialization = new decorators::SerializationDecorator<T>(*_core);

        math = new decorators::MathOperationsDecorator<T>(*_core);
        rounder = new decorators::RoundingDecorator<T>(*_core);
	}

    template<typename T>
    size_t Matrix<T>::getRows() const {
        return _core->getRows();
    }

    template<typename T>
    size_t Matrix<T>::getCols() const {
        return _core->getCols();
    }

    template<typename T>
    Size Matrix<T>::getSize() const {
        return _core->getSize();
    }

    template<typename T>
    std::vector<T> Matrix<T>::getRow(size_t row) const {
        return _core->getRow(row);
    }

    template<typename T>
    std::vector<T> Matrix<T>::getCol(size_t col) const {
        return _core->getCol(col);
    }

    template<typename T>
    void Matrix<T>::setRow(size_t rowIndex, const std::vector<T>& values) {
        _core->setRow(rowIndex, values);
    }

    template<typename T>
    void Matrix<T>::setCol(size_t colIndex, const std::vector<T>& values) {
        _core->setCol(colIndex, values);
    }

    template<typename T>
    void Matrix<T>::resize(size_t newRows, size_t newCols) {
        _core->resize(newRows, newCols);
    }

    template<typename T>
    bool Matrix<T>::isSquare() const {
        return _comparison->isSquare();
    }

    template<typename T>
    bool Matrix<T>::isSymmetric() const {
        return _comparison->isSymmetric();
    }

    template<typename T>
    bool Matrix<T>::isZero() const {
        return _comparison->isZero();
    }

    template<typename T>
    bool Matrix<T>::isIdentity() const {
        return _comparison->isIdentity();
    }

    template<typename T>
    T& Matrix<T>::operator()(size_t row, size_t col) {
        return (*_core)(row, col);
    }

    template<typename T>
    const T& Matrix<T>::operator()(size_t row, size_t col) const {
        return (*_core)(row, col);
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator=(const Matrix<T>& other) {
        if (this != &other) {
            this->~Matrix();
            this->_core = new core::MatrixCore<T>(*other._core);
            //*_core = *(other._core);
            this->initDecorators();
        } return *this;
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
        return _arithmetic->operator+(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
        return _arithmetic->operator-(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
        return _arithmetic->operator*(other);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator+(const T& value) const {
        return _arithmetic->operator+(value);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator-(const T& value) const {
        return _arithmetic->operator-(value);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator*(const T& value) const {
        return _arithmetic->operator*(value);
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator/(const T& value) const {
        return _arithmetic->operator/(value);
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& other) {
        _arithmetic->operator+=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& other) {
        _arithmetic->operator-=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& other) {
        _arithmetic->operator*=(other);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator+=(const T& value) {
        _arithmetic->operator+=(value);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator-=(const T& value) {
        _arithmetic->operator-=(value);
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator*=(const T& value) {
        _arithmetic->operator*=(value);
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator/=(const T& value) {
        _arithmetic->operator/=(value);
        return *this;
    }

    template<typename T>
    bool Matrix<T>::operator==(const Matrix<T>& other) const {
        return _comparison->operator==(other);
    }

    template<typename T>
    bool Matrix<T>::operator!=(const Matrix<T>& other) const {
        return _comparison->operator!=(other);
    }

    template<typename T>
    bool Matrix<T>::operator<(const Matrix<T>& other) const {
        return _comparison->operator<(other);
    }

    template<typename T>
    bool Matrix<T>::operator<=(const Matrix<T>& other) const {
        return _comparison->operator<=(other);
    }

    template<typename T>
    bool Matrix<T>::operator>(const Matrix<T>& other) const {
        return _comparison->operator>(other);
    }

    template<typename T>
    bool Matrix<T>::operator>=(const Matrix<T>& other) const {
        return _comparison->operator>=(other);
    }

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
		if (matrix._serialization) {
			matrix._serialization->print(out);
		} return out;
	}

	template<typename T>
	std::istream& operator>>(const std::istream& in, Matrix<T>& matrix) {
		if (matrix._serialization) {
			matrix._serialization->read(in);;
		} return in;
	}
}

#endif // !MATRIXL_CPP