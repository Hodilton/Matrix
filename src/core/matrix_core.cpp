#ifndef MATRIX_CORE_CPP
#define MATRIX_CORE_CPP
#include "./matrix_core.h"

namespace matrix::core {

	template<typename T>
	MatrixCore<T>::MatrixCore()
		: _size(0, 0) {
	}

	template<typename T>
	inline MatrixCore<T>::MatrixCore(size_t rows, size_t cols)
		: _size(rows, cols) {
		takeMemory();
		init();
	}

	template<typename T>
	MatrixCore<T>::MatrixCore(Size size)
		: _size(size) {
		takeMemory();
		init();
	}

	template<typename T>
	MatrixCore<T>::MatrixCore(const std::vector<std::vector<T>>& values)
		: _size(values.size(), values.empty() ? 0 : values[0].size()), _elements(values) {
	}

	template<typename T>
	MatrixCore<T>::MatrixCore(const MatrixCore<T>& other)
		: _size(other._size), _elements(other._elements) {
	}

	template<typename T>
	MatrixCore<T>::~MatrixCore() {
		freeMemory();
	}

	template<typename T>
	size_t MatrixCore<T>::getRows() const {
		return _size.getRows();
	}

	template<typename T>
	size_t MatrixCore<T>::getCols() const {
		return _size.getCols();
	}

	template<typename T>
	Size MatrixCore<T>::getSize() const {
		return _size;
	}

	template<typename T>
	std::vector<T> MatrixCore<T>::getRow(size_t row) const {
		if (row >= _size.getRows()) {
			throw std::out_of_range("Row index out of range.");
		} return _elements[row];
	}

	template<typename T>
	std::vector<T> MatrixCore<T>::getCol(size_t col) const {
		if (col >= _size.cols) {
			throw std::out_of_range("Column index out of range");
		}

		std::vector<T> column(_size.getRows());
		for (size_t i = 0; i < _size.getRows(); i++) {
			column[i] = _elements[i][col];
		} return column;
	}

	template<typename T>
	void MatrixCore<T>::setRow(size_t rowIndex, const std::vector<T>& values) {
		if (rowIndex >= _size.getRows() || values.size() != _size.getCols()) {
			throw std::invalid_argument("Invalid row index or size mismatch.");
		} _elements[rowIndex] = values;
	}

	template<typename T>
	void MatrixCore<T>::setCol(size_t colIndex, const std::vector<T>& values) {
		if (colIndex >= _size.getCols() || values.size() != _size.getRows()) {
			throw std::invalid_argument("Invalid column index or size mismatch.");
		}
		for (size_t i = 0; i < _size.getRows(); i++) {
			_elements[i][colIndex] = values[i];
		}
	}

	template<typename T>
	void MatrixCore<T>::resize(size_t newRows, size_t newCols) {
		std::vector<std::vector<T>> newElements(newRows, std::vector<T>(newCols, T{}));

		size_t minRows = std::min(newRows, _size.getRows());
		size_t minCols = std::min(newCols, _size.getCols());

		for (size_t i = 0; i < minRows; i++) {
			for (size_t j = 0; j < minCols; j++) {
				newElements[i][j] = _elements[i][j];
			}
		}

		_size = Size(newRows, newCols);
		_elements = std::move(newElements);
	}

	template<typename T>
	T& MatrixCore<T>::operator()(size_t row, size_t col) {
		if (row > _size.getRows() || col > _size.getCols()) {
			throw std::out_of_range("Matrix index out of range.");
		} return _elements[row][col];
	}

	template<typename T>
	const T& MatrixCore<T>::operator()(size_t row, size_t col) const {
		if (row > _size.getRows() || col > _size.getCols()) {
			throw std::out_of_range("Matrix subscript out of bounds.");
		}

		return _elements[row][col];
	}

	template<typename T>
	MatrixCore<T> MatrixCore<T>::operator=(const MatrixCore<T>& other) {
		if (this != &other) {
			this->_size = other._size;
			this->_elements = other._elements;
		} return *this;
	}

	template<typename T>
	void MatrixCore<T>::takeMemory() {
		_elements.resize(_size.getRows(), std::vector<T>(_size.getCols()));
	}

	template<typename T>
	void MatrixCore<T>::freeMemory() {
		_elements.clear();
		_elements.shrink_to_fit();
		this->_size = Size(0, 0);
	}

	template<typename T>
	void MatrixCore<T>::init() {
		for (size_t i = 0; i < _size.getRows(); i++) {
			for (size_t j = 0; j < _size.getCols(); j++) {
				_elements[i][j] = T{};
			}
		}
	}
}

#endif // !MATRIX_CORE_CPP