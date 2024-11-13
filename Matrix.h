#ifndef MATRIX_H
#define MATRIX_H

#include "./Dependencies/random.h"
#include "./Dependencies/file_work/include/json/json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <type_traits>

namespace matrix {

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
			out << "Rows: " << size.getRows() << std::endl;
			out << "Columns: " << size.getCols() << std::endl;
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

		static constexpr T DELTA = 1e-10;
		void roundValues(int precision);
		T roundValue(T value, int precision = 0);

	public:
		Matrix();
		Matrix(unsigned int rows, unsigned int cols);
		Matrix(const std::vector<std::vector<T>>& values);
		Matrix(const SizeMatrix& size);
		Matrix(const Matrix<T>& matrix);
		~Matrix();

		Matrix<T> transpose() const;
		T determinant() const;
		Matrix<T> inverse() const;

		bool isDiagonalDominance() const;
		T norm(const std::vector<T>& vec) const;

		unsigned int getRows() const;
		unsigned int getCols() const;
		std::vector<T> getRow(unsigned int row) const;
		std::vector<T> getCol(unsigned int col) const;
		SizeMatrix getSize() const;

		void setRow(unsigned int rowIndex, const std::vector<T>& values);
		void setCol(unsigned int colIndex, const std::vector<T>& values);

		void resize(unsigned int newRows, unsigned int newCols);

		std::vector<T> getMinInRows() const;
		std::vector<T> getMaxInRows() const;
		std::vector<T> getMinInCols() const;
		std::vector<T> getMaxInCols() const;

		T sum() const;
		T sumRow(size_t row) const;
		T sumColumn(size_t col) const;

		void init(const std::vector<std::vector<T>>& values);
		void print(std::ostream& out) const;
		void initRandomNumbers(T min, T max, unsigned int precision = 2);

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

		bool operator==(const Matrix& other) const;
		bool operator!=(const Matrix& other) const;
		bool operator<(const Matrix& other) const;
		bool operator<=(const Matrix& other) const;
		bool operator>(const Matrix& other) const;
		bool operator>=(const Matrix& other) const;

		T& operator()(const unsigned int& row, const unsigned int& col);
		const T& operator()(const unsigned int& row, const unsigned int& col) const;

		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
		template <typename U>
		friend std::istream& operator>>(const std::istream& in, Matrix<U>& matrix);
	};

	template <typename T>
	class MatrixJsonSerializer {
	public:
		static json toJson(const Matrix<T>& matrix);
		static json toJson(const std::vector<Matrix<T>>& matrices);
		static json toJson(const std::map<std::string, Matrix<T>>& matrices);
	};

	template <typename T>
	class MatrixJsonDeserializer {
	public:
		static Matrix<T> fromJson(const json& j);
		static std::vector<Matrix<T>> fromJsonVec(const json& j);
		static std::map<std::string, Matrix<T>> fromJsonMap(const json& j);
	};
}

#include "Matrix.cpp"
#endif // !MATRIX_H