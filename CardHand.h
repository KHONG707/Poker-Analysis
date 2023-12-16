//
// Created by Kristal Hong on 3/19/23.
//

#ifndef POKERANALYSIS_CARDHAND_H
#define POKERANALYSIS_CARDHAND_H
#include "Card.h"
#include "Deck.h"
#include <vector>

class CardHand {
public:
    CardHand();
    CardHand(const std::vector<Card>& c);
    std::vector<Card> getPlayerCard() const;
    void addCard(Card c); //adds card c to hand

    void sortRank(); //sort the card so that cards in increasing order
    void resetHand();


    friend std::ostream& operator << (std::ostream& out, const CardHand& cardHand);

private:
    std::vector<Card> playerCards;
};



#endif //POKERANALYSIS_CARDHAND_H
