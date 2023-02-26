#pragma once
#ifndef _CMATRIX_H_
#define _CMATRIX_H_
#include "stdafx.h"

class SizeMatrix {
private:
	unsigned _row;
	unsigned _column;
public:
	SizeMatrix(unsigned row = 1, unsigned column = 1) : _row(row), _column(column) {}
	SizeMatrix(const SizeMatrix& size) { this->_row = size._row; this->_column = size._column; }

	void SetRow(unsigned row) { this->_row = row; }
	void SetColumn(unsigned column) { this->_column = column; }
	unsigned GetRow() const { return this->_row; }
	unsigned GetColumn() const { return this->_column; }

	SizeMatrix& operator=(const SizeMatrix& size) {
		this->_row = size._row;
		this->_column = size._column;
		return *this;
	}

	friend istream& operator>>(istream& in, SizeMatrix& size) {
		vector<string> text;

		text.push_back("Enter the number of rows: ");
		size.SetRow(CConsole<int>::ReadNumber(text, in, 1));
		text.push_back(to_string(size.GetRow()));

		text.push_back("\nEnter the number of columns: ");
		size.SetColumn(CConsole<int>::ReadNumber(text, in, 1));
		text.clear();

		return in;
	}

	friend ostream& operator<<(ostream& out, SizeMatrix& size) {
		out << "Rows: " << size.GetRow() << endl;
		out << "Columns: " << size.GetColumn() << endl;
		return out;
	}
};

template <typename T> 
class CMatrix {
private:
	T** _matrix;
	SizeMatrix _size;
	
	void TakeMemoryMatrix();
	void FreeMemoryMatrix();
	void InititalizeZeros();
public:
	CMatrix(unsigned row = 1, unsigned column = 1);
	CMatrix(const SizeMatrix& size);
	CMatrix(const CMatrix<T>& matrix);
	~CMatrix();

	//CMatrix<T> transpose();
	void Print(ostream& out) const;
	void InititalizeRandomNumbers() const;

	unsigned GetRow() const;
	unsigned GetColumn() const;
	SizeMatrix GetSize() const;

	const CMatrix<T>& operator=(const CMatrix<T>& matrix);

	//CMatrix<T> operator+(const CMatrix<T>& matrix);
	//CMatrix<T>& operator+=(const CMatrix<T>& matrix);
	//CMatrix<T> operator-(const CMatrix<T>& matrix);
	//CMatrix<T>& operator-=(const CMatrix<T>& matrix);
	const CMatrix<T> operator*(const CMatrix<T>& matrix);
	//CMatrix<T>& operator*=(const CMatrix<T>& matrix);

	//CMatrix<T> operator+(const T& value);
	//CMatrix<T> operator-(const T& value);
	//CMatrix<T> operator*(const T& value);
	//CMatrix<T> operator/(const T& value);

	T& operator()(const unsigned& row, const unsigned& column);
	const T& operator()(const unsigned& row, const unsigned& column) const;

	template<typename T>
	friend ostream& operator<<(ostream& out, const CMatrix& matrix);
	//friend istream& operator>>(istream&, CMatrix<T>& matrix);
};

#include "CMatrix.cpp"
#endif // !_CMATRIX_H_