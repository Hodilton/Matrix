#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include "stdafx.h"
#include "random.h"

class SizeMatrix {
private:
	unsigned int _rows;
	unsigned int _cols;
public:
	SizeMatrix(unsigned int rows = 1, unsigned int cols = 1) : _rows(rows), _cols(cols) {}
	SizeMatrix(const SizeMatrix& size) { this->_rows = size._rows; this->_cols = size._cols; }

	void setRows(unsigned int rows) { _rows = rows; }
	void setCols(unsigned int cols) { _cols = cols; }
	unsigned int getRows() const { return _rows; }
	unsigned int getCols() const { return _cols; }

	SizeMatrix& operator=(const SizeMatrix& size) {
		this->_rows = size._rows;
		this->_cols = size._cols;
		return *this;
	}

	friend std::istream& operator>>(std::istream& in, SizeMatrix& size) {
		std::cout << "Enter the number of rows: ";
		in >> size._rows;
		std::cout << "Enter the number of columns: ";
		in >> size._cols;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const SizeMatrix& size) {
		out << "Rows: " << size.getRows() << endl;
		out << "Columns: " << size.getCols() << endl;
		return out;
	}
};

template <typename T> 
class Matrix {
private:
	T** _elements;
	SizeMatrix _size;
	
	void takeMemory();
	void freeMemory();
	void initToZeros();

	Matrix<T> getMinor(unsigned int row, unsigned int col) const;

public:
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const std::vector<std::vector<T>>& values);
	Matrix(const SizeMatrix& size);
	Matrix(const Matrix<T>& matrix);
	~Matrix();

	Matrix<T> transpose() const;
	T determinant() const;
	Matrix<T> inverse() const;

	unsigned int getRows() const;
	unsigned int getCols() const;
	std::vector<T> getRow(unsigned int row) const;
	std::vector<T> getCol(unsigned int col) const;
	SizeMatrix getSize() const;

	void setRow(unsigned int rowIndex, const std::vector<T>& values);
	void setCol(unsigned int colIndex, const std::vector<T>& values);

	void init(const std::vector<std::vector<T>>& values);
	void print(std::ostream& out) const;
	void initRandomNumbers(T min, T max, int precision = 2);

	Matrix<T>& operator=(const Matrix<T>& matrix);

	Matrix<T> operator+(const Matrix<T>& matrix) const;
	Matrix<T> operator-(const Matrix<T>& matrix) const;
	Matrix<T> operator*(const Matrix<T>& matrix) const;

	Matrix<T>& operator+=(const Matrix<T>& matrix);
	Matrix<T>& operator-=(const Matrix<T>& matrix);
	Matrix<T>& operator*=(const Matrix<T>& matrix);

	Matrix<T> operator+(const T& value);
	Matrix<T> operator-(const T& value);
	Matrix<T> operator*(const T& value);
	Matrix<T> operator/(const T& value);

	Matrix<T>& operator+=(const T& value);
	Matrix<T>& operator-=(const T& value);
	Matrix<T>& operator*=(const T& value);
	Matrix<T>& operator/=(const T& value);

	T& operator()(const unsigned int& row, const unsigned int& col);
	const T& operator()(const unsigned int& row, const unsigned int& col) const;

	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
	template <typename U>
	friend std::istream& operator>>(const std::istream& in, Matrix<U>& matrix);
};

#include "Matrix.cpp"
#endif // !MATRIX_H