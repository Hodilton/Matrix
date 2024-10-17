#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :_size(rows, cols) {
    this->takeMemory();
    this->initToZeros();
}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& values) {
    unsigned int rows = values.size();
    unsigned int cols = rows > 0 ? values[0].size() : 0;

    this->_size.setRows(rows);
    this->_size.setCols(cols);

    this->takeMemory();
    this->init(values);
}

template<typename T>
Matrix<T>::Matrix(const SizeMatrix& size) :_size(size) {
    this->takeMemory();
    this->initToZeros();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) {
    this->freeMemory();
    this->_size = matrix._size;
    this->takeMemory();

    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            this->_elements[i][j] = matrix._elements[i][j];
        }
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    this->freeMemory();
}

template<typename T>
void Matrix<T>::takeMemory() {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    this->_elements = new T * [rows];
    for (unsigned int i = 0; i < rows; i++) {
        this->_elements[i] = new T[cols];
    }
}

template<typename T>
void Matrix<T>::freeMemory() {
    if (this->_elements != nullptr) {
        unsigned int rows = this->_size.getRows();
        for (unsigned int i = 0; i < rows; i++) {
            if (this->_elements[i] != nullptr) {
                delete[] this->_elements[i];
                this->_elements[i] = nullptr;
            }
        }
        delete[] this->_elements;
        this->_elements = nullptr;
    }
}

template<typename T>
void Matrix<T>::initToZeros() {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            this->_elements[i][j] = 0;
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::getMinor(unsigned int row, unsigned int col) const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();
    Matrix<T> result(rows - 1, cols - 1);

    for (unsigned int i = 0, row_minor = 0; i < rows; ++i) {
        if (i == row) continue;

        for (unsigned int j = 0, col_minor = 0; j < cols; ++j) {
            if (j == col) continue;

            result(row_minor + 1, col_minor + 1) = this->_elements[i][j];
            ++col_minor;
        }
        ++row_minor;
    }
    return result;
}

template<typename T>
void Matrix<T>::roundValues(int precision) {
    for (unsigned int i = 0; i < this->_size.getRows(); i++) {
        for (unsigned int j = 0; j < this->_size.getCols(); j++) {

            if (std::fabs(this->_elements[i][j]) < this->DELTA) {
                this->_elements[i][j] = 0;
            }
            else {
                T roundedValue = this->roundValue(this->_elements[i][j], precision);
                this->_elements[i][j] = roundedValue;
            }
        }
    }
}

template<typename T>
T Matrix<T>::roundValue(T value, int precision) {
    T scale = std::pow(10, precision);
    if (std::fabs(value) < DELTA) {
        return 0;
    }
    return std::round(value * scale) / scale;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();
    Matrix<T> result(rows, cols);

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[j][i] = this->_elements[i][j];
        }
    }
    return result;
}

template<typename T>
T Matrix<T>::determinant() const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (rows != cols) {
        throw std::invalid_argument("The determinant can only be calculated for a square matrix!");
    }
    if (rows == 1) {
        return this->_elements[0][0];
    }

    T det = 0;
    for (unsigned int i = 0; i < cols; ++i) {
        Matrix<T> minor = this->getMinor(0, i);
        det += ((i % 2 == 0 ? 1 : -1) * this->_elements[0][i] * minor.determinant());
    }
    return det;
}

template<typename T>
Matrix<T> Matrix<T>::inverse() const {
    T det = this->determinant();

    if (det == 0) {
        throw std::invalid_argument("The inverse matrix does not exist (the determinant is zero)!");
    }

    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();
    Matrix<T> result(rows, cols);

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            Matrix<T> minor = getMinor(i, j);
            result._elements[j][i] = (1 / det) * ((i + j) % 2 == 0 ? 1 : -1) * minor.determinant();
        }
    }
    return result;
}

template<typename T>
unsigned int Matrix<T>::getRows() const {
    return this->_size.getRows();
}

template<typename T>
unsigned int Matrix<T>::getCols() const {
    return this->_size.getCols();
}

template<typename T>
std::vector<T> Matrix<T>::getRow(unsigned int row) const {
    unsigned int rows = this->_size.getRows();
    if (row > rows || row < 1) {
        throw std::out_of_range("Некорректный номер строки.");
    }

    unsigned int cols = this->_size.getCols();
    std::vector<T> result(cols);
    for (unsigned int i = 0; i < cols; ++i) {
        result[i] = this->_elements[row - 1][i];
    }
    return result;
}

template<typename T>
std::vector<T> Matrix<T>::getCol(unsigned int col) const {
    unsigned int cols = this->_size.getCols();
    if (col > cols || col < 1) {
        throw std::out_of_range("Некорректный номер столбца.");
    }

    unsigned int rows = this->_size.getRows();
    std::vector<T> result(rows);
    for (unsigned int i = 0; i < rows; ++i) {
        result[i] = _elements[i][col - 1];
    }
    return result;
}

template<typename T>
SizeMatrix Matrix<T>::getSize() const {
    return this->_size;
}

template<typename T>
void Matrix<T>::setRow(unsigned int rowIndex, const std::vector<T>& values) {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (rowIndex >= rows) {
        throw std::out_of_range("Row index out of bounds.");
    }
    if (values.size() != cols) {
        throw std::invalid_argument("Number of values does not match the number of columns.");
    }

    for (unsigned int col = 0; col < cols; ++col) {
        this->_elements[rowIndex][col] = values[col];
    }
}

template<typename T>
void Matrix<T>::setCol(unsigned int colIndex, const std::vector<T>& values) {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (colIndex >= cols) {
        throw std::out_of_range("Column index out of bounds.");
    }
    if (values.size() != rows) {
        throw std::invalid_argument("Number of values does not match the number of rows.");
    }

    for (unsigned int row = 0; row < rows; ++row) {
        this->_elements[row][colIndex] = values[row];
    }
}

template<typename T>
void Matrix<T>::init(const std::vector<std::vector<T>>& values) {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (values.size() != rows || values[0].size() != cols) {
        throw std::invalid_argument("Size of input does not match matrix size.");
    }

    for (unsigned int i = 0; i < rows; ++i) {
        setRow(i, values[i]);
    }
}

template<typename T>
void Matrix<T>::print(std::ostream& out) const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            out << this->_elements[i][j] << "\t";
        } out << std::endl;
    }
}

template<typename T>
void Matrix<T>::initRandomNumbers(T min, T max, int precision) {
    if constexpr (!std::is_arithmetic_v<T>) {
        std::cout << "InititalizeRandomNumbers skipped: Unsupported type for random generation." << std::endl;
        return;
    }

    auto gen = random::Factory::Create<T>();

    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if constexpr (/*std::is_same_v<T, double>*/std::is_floating_point_v<T>) {
                auto* doubleGenPtr = dynamic_cast<random::DoubleRandomGenerator*>(gen.get());
                this->_elements[i][j] = doubleGenPtr->GetWithPrecision(min, max, precision);
            }
            else {
                this->_elements[i][j] = gen->Get(min, max);
            }
        }
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
    this->freeMemory();
    this->_size = matrix._size;
    this->takeMemory();
    
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            this->_elements[i][j] = matrix._elements[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& matrix) const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (rows != matrix.getRows() || cols != matrix.getCols()) {
        throw std::runtime_error("Matrix sizes must match for addition.");
    }

    Matrix<T> result(this->_size.getRows(), this->_size.getCols());
    
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] = this->_elements[i][j] + matrix._elements[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matrix) const {
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    if (rows != matrix.getRows() || cols != matrix.getCols()) {
        throw std::invalid_argument("Matrix sizes must match for subtraction.");
    }

    Matrix<T> result(rows, cols);

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] = this->_elements[i][j] - matrix._elements[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matrix) const {
    if (this->_size.getCols() != matrix._size.getRows()) {
        throw std::invalid_argument("Matrices cannot be multiplied!");
    }

    unsigned int resultRows = this->_size.getRows();
    unsigned int resultCols = matrix._size.getCols();
    Matrix<T> result(resultRows, resultCols);

    for (unsigned int i = 0; i < resultRows; i++) {
        for (unsigned int j = 0; j < resultCols; j++) {
            for (unsigned int k = 0; k < this->_size.getCols(); k++) {
                result._elements[i][j] += this->_elements[i][k] * matrix._elements[k][j];
            }
        }
    }
    result.roundValues(6);
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& matrix) {
    *this = *this + matrix;
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& matrix) {
    *this = *this - matrix;
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& matrix) {
    *this = *this * matrix;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& value) {
    Matrix<T> result(*this);
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] += value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& value) {
    Matrix<T> result(*this);
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] -= value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value) {
    Matrix<T> result(*this);
    unsigned int rows = result._size.getRows();
    unsigned int cols = result._size.getCols();

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] *= value;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& value) {
    if (value == 0) {
        throw std::invalid_argument("Division by zero.");
    }

    Matrix<T> result(*this);
    unsigned int rows = this->_size.getRows();
    unsigned int cols = this->_size.getCols();

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            result._elements[i][j] /= value;
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const T& value) {
    *this = *this + value;
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const T& value) {
    *this = *this - value;
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& value) {
    *this = *this * value;
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T& value) {
    *this = *this / value;
    return *this;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned int& row, const unsigned int& col) {
    if (row > this->_size.getRows() || col > this->_size.getCols() || row < 1 || col < 1) {
        throw std::out_of_range("Matrix subscript out of bounds.");
    }

    return this->_elements[row - 1][col - 1];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned int& row, const unsigned int& col) const {
    if (row > this->_size.getRows() || col > this->_size.getCols() || row < 1 || col < 1) {
        throw std::out_of_range("Matrix subscript out of bounds.");
    }

    return this->_elements[row - 1][col - 1];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    matrix.print(out);
    return out;
}

template<typename T>
std::istream& operator>>(const std::istream& in, Matrix<T>& matrix) {
    unsigned int rows = matrix.getRows();
    unsigned int cols = matrix.getCols();

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            std::cout << "Enter element (" << i + 1 << ", " << j + 1 << "): ";
            in >> matrix._elements[i][j];
        }
    }
    return in;
}

#endif // !MATRIX_CPP