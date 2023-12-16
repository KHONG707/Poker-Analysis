//
// Created by Kristal Hong on 3/19/23.
//

#ifndef POKERANALYSIS_DECK_H
#define POKERANALYSIS_DECK_H
#include <iostream>
#include "Card.h"


class Deck
{
public:
    Deck();

    Card dealCard(); // returns the next card in the deck

    void shuffle(); // puts cards in random order
    friend std::ostream& operator << (std::ostream& out, const Deck& deck); // prints all the cards to the console

    void resetDeck();

private:
    const int DECK_SIZE = 52;// this is the size of the deck
    int cardIndex; //marks the index of the next card in the deck
    Card deck[52];// this is the final deck of cards
};


#endif //POKERANALYSIS_DECK_H
