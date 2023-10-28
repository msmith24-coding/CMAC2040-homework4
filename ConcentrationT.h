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

        bool player1Turn;

        unsigned int player1Pts;
        unsigned int player2Pts;

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

    this->player1Pts = 0;
    this->player2Pts = 0;

    this->player1Turn = true;

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
            this->data[i, j].setFlipped(false);
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

        if(this->player1Turn) {
            std::cout << "It is your turn player 1." << std::endl;
        } else {
            std::cout << "It is your turn player 2." << std::endl;
        }

        this->displayData();

        do {
            location0 = this->promptLocation();
            if(!this->data[location0.x, location0.y].getFlipped()) {
                this->data[location0.x, location0.y].setFlipped(true);
                shouldCheck = false;
            } else {
                std::cout << "You have already flipped this card. Select a new one." << std::endl;
                std::cout << std::endl;
            }
            this->displayData();
        } while(shouldCheck);

        shouldCheck = true;
        do {
            location1 = this->promptLocation();
            if(!this->data[location1.x, location1.y].getFlipped()) {
                this->data[location1.x, location1.y].setFlipped(true);
                shouldCheck = false;
            } else {
                std::cout << "You have already flipped this card. Select a new one." << std::endl;
                std::cout << std::endl;
            }
            this->displayData();
        } while(shouldCheck);

        T item0 = this->data[location0.x, location0.y];
        T item1 = this->data[location1.x, location1.y];

        if(item0.getValue() == item1.getValue()) {
            std::cout << "You found a match, have a point!" << std::endl;
            std::cout << std::endl;

            if(this->player1Turn) {
                this->player1Pts++;
            } else {
                this->player2Pts++;
            }

            foundMatch = true;
            ++matches;
        }

        if(!foundMatch) {
            this->player1Turn = !this->player1Turn;
            std::cout << "You failed to find a match." << std::endl;
            std::cout << std::endl;
            this->data[location0.x, location0.y].setFlipped(false);
            this->data[location1.x, location1.y].setFlipped(false);
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
    if(this->player1Pts > this->player2Pts) {
        std::cout << "Player 1 won with " << this->player1Pts << "." << std::endl;
    } else if (this->player1Pts < this->player2Pts){
        std::cout << "Player 2 won with " << this->player2Pts << "." << std::endl;
    } else {
        std::cout << "Player 1 and Player 2 tied." << std::endl;
    }
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

    std::cout << "Enter a card: ";
    std::getline(std::cin, cardLocation);

    std::cout << std::endl;

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
        if(!this->data[_row, i].getFlipped()) {
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


