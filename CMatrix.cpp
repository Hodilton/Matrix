#ifndef _CMATRIX_CPP_
#define _CMATRIX_CPP_
#include "CMatrix.h"

template<typename T>
void CMatrix<T>::TakeMemoryMatrix()
{
    int row = this->GetRow();
    int column = this->GetColumn();

    this->_matrix = new T * [row];
    for (int i = 0; i < row; i++)
        this->_matrix[i] = new T[column];
}

template<typename T>
void CMatrix<T>::FreeMemoryMatrix()
{
    int row = this->GetRow();

    for (int i = 0; i < row; i++)
        delete[] this->_matrix[i];
    delete[] this->_matrix;
}

template<typename T>
void CMatrix<T>::InititalizeZeros()
{
    int row = this->GetRow();
    int column = this->GetColumn();

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            this->_matrix[i][j] = 0;
        }
    }
}

template<typename T>
inline CMatrix<T>::CMatrix(unsigned row, unsigned column)
{
    this->_size.SetRow(row);
    this->_size.SetColumn(column);

    this->TakeMemoryMatrix();
    this->InititalizeZeros();
}

template<typename T>
CMatrix<T>::CMatrix(const SizeMatrix& size)
{
    this->_size = size;

    this->TakeMemoryMatrix();
    this->InititalizeZeros();
}

template<typename T>
CMatrix<T>::CMatrix(const CMatrix<T>& matrix)
{
    this->FreeMemoryMatrix();
    this->_size = matrix._size;
    this->TakeMemoryMatrix();
    
    int row = this->_size.GetRow();
    int column = this->_size.GetColumn();

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            this->_matrix[i][j] = matrix._matrix[i][j];
        }
    }
}

template<typename T>
CMatrix<T>::~CMatrix()
{
    this->FreeMemoryMatrix();
}

template<typename T>
void CMatrix<T>::Print(ostream& out) const
{
    int row = this->GetRow();
    int column = this->GetColumn();

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            out << this->_matrix[i][j] << "\t";
        }
        out << endl;
    }

}

template<typename T>
void CMatrix<T>::InititalizeRandomNumbers() const
{
    int row = this->GetRow();
    int column = this->GetColumn();

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            this->_matrix[i][j] = CRandom<T>::Get();
        }
    }
}

template<typename T>
unsigned CMatrix<T>::GetRow() const
{
    return this->_size.GetRow();
}

template<typename T>
unsigned CMatrix<T>::GetColumn() const
{
    return this->_size.GetColumn();
}

template<typename T>
SizeMatrix CMatrix<T>::GetSize() const
{
    return this->_size;
}

template<typename T>
const CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& matrix)
{
    this->FreeMemoryMatrix();
    this->_size = matrix._size;
    this->TakeMemoryMatrix();
    
    int row = this->GetRow();
    int column = this->GetColumn();

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < column; j++) {

            this->_matrix[i][j] = matrix._matrix[i][j];
        }
    }

    return *this;
}

template<typename T>
const CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& matrix)
{
    CMatrix<T> matrixResult;

    if (this->GetColumn() != matrix.GetRow()) {
        cout << "Matrices cannot be multiplied!" << endl;
        return matrixResult;
    }

    int rowResult = this->GetRow();
    int columnResult = matrix.GetColumn();

    matrixResult._size.SetRow(rowResult);
    matrixResult._size.SetColumn(columnResult);
    matrixResult.TakeMemoryMatrix();

    int multiplyElement = 0;
    int multiplyLine = this->GetColumn();

    for (int row = 0; row < rowResult; row++) {

        for (int column = 0; column < columnResult; column++, multiplyElement = 0) {

            for (int iter = 0; iter < multiplyLine; iter++) {

                multiplyElement += this->_matrix[row][iter] * matrix._matrix[iter][column];
            }

            matrixResult._matrix[row][column] = multiplyElement;
        }
    }

    return matrixResult;
}

template<typename T>
T& CMatrix<T>::operator()(const unsigned& row, const unsigned& column)
{
    T temp = 0;

    if (row > this->GetRow() || column > this->GetColumn() || row < 1 || column < 1) {
        cout << "Error, out of bounds." << endl;
        system("pause");
        return temp;
    }

    return this->_matrix[row - 1][column - 1];
}

template<typename T>
const T& CMatrix<T>::operator()(const unsigned& row, const unsigned& column) const
{
    T temp = 0;

    if (row > this->GetRow() || column > this->GetColumn() || row < 1 || column < 1) {
        cout << "Error, out of bounds." << endl;
        system("pause");
        return temp;
    }

    return this->_matrix[row - 1][column - 1];
}

template<typename T>
inline ostream& operator<<(ostream& out, const CMatrix<T>& matrix)
{
    matrix.Print(out);
    return out;
}

#endif // !_CMATRIX_CPP_