#include "Array2T.h"
#include "ArrayT.h"
#include "CardT.h"
#include "ConcentrationT.h"

#include <iostream>
#include <cinttypes>

const unsigned int TEST_PLAYERS = 2;
const unsigned int MAX_CARDS = 6;
const unsigned int MAX_ROWS = 3;
const unsigned int MAX_COLS = 2;

const bool DEBUG = false;

const int cards[] = { 1, 1, 4, 4, 6, 6 };  

int main()
{
    ArrayT<CardT<int>> deck(MAX_CARDS);

    for(unsigned int i = 0; i < MAX_CARDS; ++i) {
        deck.pushBack(CardT<int>(cards[i]));
    }

    ConcentrationT<CardT<int>> game(MAX_ROWS, MAX_COLS, TEST_PLAYERS, deck);

    game.play();
    game.report();

    return 0;
}