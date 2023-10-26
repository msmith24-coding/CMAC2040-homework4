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
        Array2T<bool> flipData;

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
    this->flipData = Array2T<bool>(_rows, _cols);
    this->isRunning = true;
}

template <typename T>
void ConcentrationT<T>::play()
{
    unsigned int matches = 0;
    this->isRunning = true;

    this->deck.shuffle();

    unsigned int index = 0;
    for(unsigned int i = 0; i < this->rows; ++i) {
        for(unsigned int j = 0; j < this->cols; ++j) {
            this->flipData[i, j] = false;
        }
    }

    index = 0;
    for(unsigned int i = 0; i < this->rows; ++i) {
        for(unsigned int j = 0; j < this->cols; ++j) {
            this->data[i, j].setValue(this->deck[index].getValue());
            //std::cout << this->data[i, j].getValue() << std::endl;
            ++index;
        }
    }

    while(this->isRunning) {
        Coord2 location0;
        Coord2 location1;
        
        bool foundMatch = false;

        
        bool shouldCheck = true;
        do {
            location0 = this->promptLocation();
            if(!this->flipData[location0.x, location0.y]) {
                this->flipData[location0.x, location0.y] = true;
                shouldCheck = false;
            } else {
                std::cout << "You have already flipped this card. Select a new one." << std::endl;
                std::cout << std::endl;
            }
        } while(shouldCheck);

        shouldCheck = true;
        do {
            location1 = this->promptLocation();
            if(!this->flipData[location1.x, location1.y]) {
                this->flipData[location1.x, location1.y] = true;
                shouldCheck = false;
            } else {
                std::cout << "You have already flipped this card. Select a new one." << std::endl;
                std::cout << std::endl;
            }
        } while(shouldCheck);

        T item0 = this->data[location0.x, location0.y];
        T item1 = this->data[location1.x, location1.y];

        if(item0.getValue() == item1.getValue()) {
            foundMatch = true;
            ++matches;
        }

        this->displayData();

        std::cout << "---" << std::endl;
        std::cout << std::endl;

        if(!foundMatch) {
            this->flipData[location0.x, location0.y] = false;
            this->flipData[location1.x, location1.y] = false;
        }

        if(matches >= (this->rows * this->cols) / 2) {
            this->isRunning = false;
        }

    }
    
}

template <typename T>
void ConcentrationT<T>::report()
{
    std::cout << "You found all the matches." << std::endl;
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

    std::cout << "Enter a card: ";
    std::getline(std::cin, cardLocation);

    std::string xLoc = cardLocation.substr(0, cardLocation.find(','));
    std::string yLoc = cardLocation.substr(cardLocation.find(',') + 1);
 
    result.x = std::stoi(xLoc);
    result.y = std::stoi(yLoc);

    //std::cout << result.x << ", " << result.y << std::endl;

    return result;
}

template <typename T>
std::string ConcentrationT<T>::displayRowData(unsigned int _row)
{
    std::string result;
    std::stringstream ss;

    for(unsigned int i = 0; i < this->cols; ++i) {
        if(!this->flipData[_row, i]) {
            ss << "x" << "   ";
        } else {
            ss << this->data[_row, i].getValue() << "   ";
        }
    }

    ss << std::endl;

    result = ss.str();

    return result;
}

#endif


