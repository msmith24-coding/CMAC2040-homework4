#ifndef CONCENTRATIONT_H_
#define CONCENTRATIONT_H_

#include <iostream>
#include <string>
#include <sstream>

#include "ArrayT.h"
#include "Array2T.h"

struct Coord2
{
    int x;
    int y;
};

template <typename T>
class ConcentrationT
{
    private:
        unsigned int rows;
        unsigned int cols;
        unsigned int players;
        ArrayT<T> deck;
        Array2T<T> data;

        bool isRunning;

    public:
        ConcentrationT() = default;
        ConcentrationT(unsigned int _rows, unsigned int _cols, unsigned int _players, ArrayT<T> & _deck);
        ~ConcentrationT() = default;
    public:
        void play();
        void report();
    private:
        void displayData();
        Coord2 promptLocation();
        std::string displayRowData(unsigned int _col);
};

template <typename T>
ConcentrationT<T>::ConcentrationT(unsigned int _rows, unsigned int _cols, unsigned int _players, ArrayT<T> & _deck)
{
    this->rows = _rows;
    this->cols = _cols;
    this->players = _players;
    this->deck = _deck;
    this->data = Array2T<T>(_rows, _cols);
    this->isRunning = true;
}

template <typename T>
void ConcentrationT<T>::play()
{
    this->isRunning = true;

    this->deck.shuffle();

    unsigned int index = 0;
    for(unsigned int i = 0; i < this->rows; ++i) {
        for(unsigned int j = 0; j < this->cols; ++j) {
            this->data[i, j].setValue(this->deck[index].getValue());
            //std::cout << this->data[i, j].getValue() << std::endl;
            ++index;
        }
    }

    while(this->isRunning) {
        this->promptLocation();
        this->isRunning = false;
    }
    
}

template <typename T>
void ConcentrationT<T>::report()
{

}

template <typename T>
void ConcentrationT<T>::displayData()
{
    for(unsigned int i = 0; i < this->cols; ++i) {
        std::cout << "   " << i;
    }

    std::cout << "\n"; 

    for(unsigned int i = 0; i < this->rows; ++i) {
        std::cout << i << "  " << this->displayRowData(i);
    }

    std::cout << std::endl;   
}

template <typename T>
Coord2 ConcentrationT<T>::promptLocation()
{
    Coord2 result;
    std::string cardLocation;

    this->displayData();

    result.x = 0;
    result.y = 1;   

    return result;
}

template <typename T>
std::string ConcentrationT<T>::displayRowData(unsigned int _row)
{
    std::string result;
    std::stringstream ss;

    for(unsigned int i = 0; i < this->cols; ++i) {
        ss << this->data[_row, i].getValue() << "   ";
    }

    ss << std::endl;

    result = ss.str();

    return result;
}

#endif


