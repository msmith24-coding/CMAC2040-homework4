#include "Array2T.h"
#include "ArrayT.h"
#include "CardT.h"
#include "ConcentrationT.h"

#include <iostream>
#include <string>
#include <cinttypes>

const unsigned int TEST_PLAYERS = 2;
const unsigned int MAX_CARDS = 8;
const unsigned int MAX_ROWS = 4;
const unsigned int MAX_COLS = 2;

const bool DEBUG = false;

const std::string cards[] = { "cat", "cat", "dog", "dog", "fish", "fish", "lizard", "lizard" };  

int main()
{
    ArrayT<CardT<std::string>> deck(MAX_CARDS);

    for(unsigned int i = 0; i < MAX_CARDS; ++i) {
        deck.pushBack(CardT<std::string>(cards[i]));
    }

    ConcentrationT<CardT<std::string>> game(MAX_ROWS, MAX_COLS, TEST_PLAYERS, deck);

    game.play();
    game.report();

    return 0;
}