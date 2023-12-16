//
// Created by Kristal Hong on 3/19/23.
//

#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
    //All 52 cards shuffled

    resetDeck();
}

void Deck::shuffle()
{
//    srand(time(0));
    for (int i = 0; i < DECK_SIZE; ++i)
    {
        //random position of deck
        int randomize = i + (rand() % (DECK_SIZE - i));
        std::swap(deck[i], deck[randomize]);
    }
    cardIndex = 0;
}

Card Deck::dealCard()
{

    return (deck[cardIndex++]);
    //deals one card from the deck and returns it
    //fetch the current top card, increment cardIndex by one
    //after fetching the current card.
    //just one card at a time
}


std::ostream& operator << (std::ostream& out, const Deck& deck)
{
    for (int i = 0; i < 52; ++i)
    {
        out<< "Card "<< (i+1) << ": " << deck.deck[i];
        out << std::endl;
    }
    return out;
}

void Deck::resetDeck()
{
    for(int i = 0; i < DECK_SIZE; i++)
    {
        deck[i] = Card(i);
    }
    shuffle();
    cardIndex = 0;
}