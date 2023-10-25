#ifndef ARRAY2T_H_
#define ARRAY2T_H_

#include <iostream>

template <typename T>
class Array2T
{
    private: /* Member Variables */
        unsigned int rows;
        unsigned int cols;
        T * data;
    public: /* Constrctors/Destructors */
        Array2T();
        Array2T(unsigned int _rows, unsigned int _cols);
        Array2T(const Array2T & _src);
        ~Array2T();
    public: /* Overloaded Operators */
        Array2T & operator = (const Array2T & _src);
        T operator [] (unsigned int _rows, unsigned int _cols) const;
        T & operator [] (unsigned int _rows, unsigned int _cols);
    public: /* Getter Methods */
        T getRows() const;
        T getColumns() const;
};

template <typename T>
Array2T<T>::~Array2T()
{
    delete [] this->data;
}

template <typename T>
Array2T<T>::Array2T()
{
    this->rows = 0;
    this->cols = 0;
    this->data = nullptr;
}

template <typename T>
Array2T<T>::Array2T(unsigned int _rows, unsigned int _cols)
{
    this->rows = _rows;
    this->cols = _cols;
    this->data = new T[this->rows * this->cols];
}

template <typename T>
Array2T<T>::Array2T(const Array2T<T> & _src)
{
    this->rows = _src.rows;
    this->cols = _src.cols;
    this->data = new T[this->rows * this->cols];

    for(unsigned int i = 0; i < this->rows; ++i) {
        for(unsigned int j = 0; i < this->cols; ++j) {
            unsigned int idx = i * this->cols + j;
            this->data[idx] = _src[idx];
        }
    }
}

template <typename T>
Array2T<T> & Array2T<T>::operator = (const Array2T & _src)
{
    if(this != & _src) {
        delete [] this->data;
        
        this->rows = _src.rows;
        this->cols = _src.cols;

        this->data = new T[this->rows * this->cols];

        for(unsigned int i = 0; i < this->rows; ++i) {
            for(unsigned int j = 0; j < this->cols; ++j) {
                unsigned int idx = i * this->cols + j;
                this->data[idx] = _src[i, j];
            }
        }
    }
    return * this;
}



template <typename T>
T Array2T<T>::operator [] (unsigned int _rows, unsigned int _cols) const
{
    if(_rows <= this->rows && _cols <= this->cols) {
        return this->data[_rows * this->cols + _cols];
    }
    std::cerr << "[ERR - Array2T const] Invalid index." << std::endl;
    return this->data[0];
}

template <typename T>
T & Array2T<T>::operator [] (unsigned int _row, unsigned int _col)
{
    if(_row <= this->rows && _col <= this->cols) {
        return this->data[_row * this->cols + _col]; 
    }
    std::cerr << "[ERR - Array2T] Invalid index." << std::endl;
    return this->data[0];
}

template <typename T>
T Array2T<T>::getRows() const 
{
   return this->rows;
}

template <typename T>
T Array2T<T>::getColumns() const 
{
   return this->cols;
}

#endif 
