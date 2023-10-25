#ifndef ARRAYT_H_
#define ARRAYT_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <strings.h>

template<typename T>
class ArrayT
{
    private: /* Member Variables */
        unsigned int size = 0;
        unsigned int capacity = 0;
        T * data = nullptr;
    public: /* Constructors/Destructors */
        ArrayT() = default;
        ArrayT(unsigned int _capacity);
        ArrayT(const ArrayT & _src);
        ~ArrayT();
    public: /* Overloaded Operators */
        ArrayT & operator = (const ArrayT & _src);
        T & operator [] (unsigned int _index);
    public: /* Utility Methods */
        void pushBack(T element);
        void popBack();
        void shuffle();
        void shuffle(unsigned int depth);
    public: /* Getter Methods */
        unsigned int getSize() const;
        unsigned int getCapacity() const;
};

template<typename T>
ArrayT<T>::ArrayT(unsigned int _capacity)
{
    std::srand(time(nullptr));
    this->capacity = _capacity;
    this->data = new T[this->capacity];
}

template<typename T>
ArrayT<T>::ArrayT(const ArrayT & _src)
{
    this->size = _src.size;
    this->capacity = _src.capacity;

    this->data = new T[this->capacity];
    for(unsigned int i = 0; i < this->size; ++i) {
        this->data[i] = _src.data[i];
    }
}

template<typename T>
ArrayT<T>::~ArrayT()
{
    delete [] this->data;
}

template<typename T>
ArrayT<T> & ArrayT<T>::operator = (const ArrayT & _src)
{
    if(this != &_src) {
        this->size = _src.size;
        this->capacity = _src.capacity;

        if(this->data != nullptr) {
            delete [] this->data;
        }
        this->data = new T[this->capacity];
        for(unsigned int i = 0; i < this->size; ++i) {
            this->data[i] = _src.data[i];
        }
    }
    return * this;
}

template<typename T>
T & ArrayT<T>::operator [] (unsigned int _index)
{
    if(_index <= this->size) {
        return data[_index];
    }
    std::cerr << "[ERR - ArrayT] Invalid index." << std::endl;
    return this->data[0];
}

template<typename T>
void ArrayT<T>::pushBack(T element)
{
    T * tmp = nullptr;
    if(this->size == this->capacity) {
        ++this->capacity;
        tmp = new T[this->capacity];

        for(unsigned int i = 0; i < this->size; ++i) {
            tmp[i] = this->data[i];
        }
        
        delete [] this->data;
        this->data = tmp;
        tmp = nullptr;
    }
    this->data[this->size] = element;
    ++this->size;
}

template<typename T>
void ArrayT<T>::popBack()
{
    if(this->size > 0) {
        --this->size;
    }
}

template<typename T>
void ArrayT<T>::shuffle()
{
    unsigned int index = 0;
    T * tmpData = new T[this->capacity];

    tmpData = this->data;

    for(unsigned int i = 0; i < this->capacity; ++i) {
        index = rand() % this->capacity;
        T tmpValue = tmpData[i];
        tmpData[i] = tmpData[index];
        tmpData[index] = tmpValue;
    }

    this->data = tmpData;

}

template<typename T>
void ArrayT<T>::shuffle(unsigned int depth)
{
    unsigned int i = 0;
    while(i < depth) {
        this->shuffle();
        ++i;
    }
}

template<typename T>
unsigned int ArrayT<T>::getSize() const
{
    return this->size;
}

template<typename T>
unsigned int ArrayT<T>::getCapacity() const
{
    return this->capacity;
}

#endif
