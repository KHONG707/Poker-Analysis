//
// Created by Kristal Hong on 3/20/23.
//

#ifndef POKERANALYSIS_CARDHANDSCORER_H
#define POKERANALYSIS_CARDHANDSCORER_H
#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer {
private:
    static bool isRoyalFlush(CardHand h);
    static bool isStraightFlush(CardHand h);
    static bool isFourOfAKind(CardHand h);
    static bool isFullHouse(CardHand h);
    static bool isFlush(CardHand h);
    static bool isStraight(CardHand h);
    static bool isThreeOfAKind(CardHand h);
    static bool isTwoPair(CardHand h);
    static bool isOnePair(CardHand h);

public:
    CardHandScorer();
    static PokerScore scorePokerHand(CardHand h, bool& noRoyalFlush);
    static PokerScore scorePokerHand(CardHand h);
};


#endif //POKERANALYSIS_CARDHANDSCORER_H
