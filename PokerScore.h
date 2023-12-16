//
// Created by Kristal Hong on 3/20/23.
//

#ifndef POKERANALYSIS_POKERSCORE_H
#define POKERANALYSIS_POKERSCORE_H
#include <iostream>
#include <vector>
#include "CardHand.h"

enum Scores {
    ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

    STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

    FOUR_OF_A_KIND, //four cards of the same ranking

    FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

    FLUSH, //five cards of the same suit

    STRAIGHT, //five cards in consecutive ranking

    THREE_OF_A_KIND, //three cards of the same rank

    TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

    ONE_PAIR, //two cards of the same rank

    HIGH_CARD //highest card in the player’s hand
};

class PokerScore {
public:
    PokerScore();
    static int s[10];

    void operator += (const Scores& score);

    void operator += (const PokerScore& scores);

    bool getRoyalFlush();
    friend std::ostream& operator << (std::ostream& out, const PokerScore& score);

private:
    std::vector<Scores> scores;

};


#endif //POKERANALYSIS_POKERSCORE_H
