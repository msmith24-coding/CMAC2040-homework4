#include "Array2T.h"
#include "ArrayT.h"
#include "CardT.h"
#include "ConcentrationT.h"
#include "AbilityT.h"

#include <iostream>
#include <string>
#include <cinttypes>

const unsigned int MAX_PLAYERS = 2;
const unsigned int MAX_CARDS = 8;
const unsigned int MAX_ROWS = 4;
const unsigned int MAX_COLS = 2;

const bool DEBUG = false;

const AbilityT cards[] = { AbilityT::STRONG, AbilityT::STRONG, AbilityT::WEAK, AbilityT::WEAK, AbilityT::ATTRACTIVE, AbilityT::ATTRACTIVE, AbilityT::CLEVER, AbilityT::CLEVER };  

int main()
{
    ArrayT<CardT<AbilityT>> deck(MAX_CARDS);

    for(unsigned int i = 0; i < MAX_CARDS; ++i) {
        deck.pushBack(CardT<AbilityT>(cards[i]));
    }

    ConcentrationT<CardT<AbilityT>> game(MAX_ROWS, MAX_COLS, MAX_PLAYERS, deck);

    game.play();
    game.report();

    return 0;
}