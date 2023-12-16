//
// Created by Kristal Hong on 3/20/23.
//

#include "CardHandScorer.h"

CardHandScorer::CardHandScorer() {
    //
}


PokerScore CardHandScorer::scorePokerHand(CardHand h)
{
    PokerScore pokerScoring;
    if (isRoyalFlush(h))
    {
        //add the ROYAL_FLUSH score inside the pokerScore tip use the pokerScore += RoyalFlush
        pokerScoring += Scores::ROYAL_FLUSH;
        pokerScoring += Scores::STRAIGHT_FLUSH;
        pokerScoring += Scores::FLUSH;
        pokerScoring += Scores::STRAIGHT;
    }
    //
    else if (isStraightFlush(h))
    {
        pokerScoring += Scores::STRAIGHT_FLUSH;
        pokerScoring += Scores::FLUSH;
        pokerScoring += Scores::STRAIGHT;
    }
    else if (isFullHouse(h))
    {
        pokerScoring += Scores::FULL_HOUSE;
        pokerScoring += Scores::THREE_OF_A_KIND;
        pokerScoring += Scores::ONE_PAIR;
    }


    else if (isFourOfAKind(h))
    {
        pokerScoring += Scores::FOUR_OF_A_KIND;
        pokerScoring += Scores::THREE_OF_A_KIND;
        pokerScoring += Scores::TWO_PAIR;
        pokerScoring += Scores::ONE_PAIR;
    }

   else if (isFlush(h))
    {
        pokerScoring += Scores::FLUSH;

        pokerScoring += Scores::TWO_PAIR;
        pokerScoring += Scores::ONE_PAIR;
    }
    else if (isStraight(h))
    {
        pokerScoring += Scores::STRAIGHT;
    }
    else if (isTwoPair(h))
    {
        pokerScoring += Scores::TWO_PAIR;
        pokerScoring += Scores::ONE_PAIR;
    }
    else if (isThreeOfAKind(h))
    {
        pokerScoring += Scores::THREE_OF_A_KIND;
        pokerScoring += Scores::ONE_PAIR;
    }
    else if (isOnePair(h))
    {
        pokerScoring += Scores::ONE_PAIR;
    }


    pokerScoring += Scores::HIGH_CARD;

    return pokerScoring;
}


bool CardHandScorer::isRoyalFlush(CardHand h)
{
    /*
     * TODO: cards MUST BE SORTED BEFORE RUNNING THIS FUNCTION

     check if all suits are the same - get the suit from one card of the hand,
     and compare it with the rest of the cards from the card
     */

    const std::vector<Card> playerHand = h.getPlayerCard();

    const Suits firstCardSuit = playerHand[0].getSuit();
    for(int i = 0; i < 5; i++)
    {
        if (firstCardSuit != playerHand[i].getSuit())
        {
            return false;
        }
    }
//
//     * bool true if ACE -> bool true if next card is 10 -> if card afterward is not in order -> false
//     if ACE -> go to next card, if card is 10, if any card is not in order then false
//
//     take enum of card rank -> compare
//

    bool hasAceRank = (playerHand[0].getRank() == ACE);
    bool hasTenRank = (playerHand[1].getRank() == TEN);
    bool hasJackRank = (playerHand[2].getRank() == JACK);
    bool hasQueenRank = (playerHand[3].getRank() == QUEEN);
    bool hasKingRank = (playerHand[4].getRank() == KING);

    return (hasAceRank && hasTenRank && hasJackRank && hasQueenRank && hasKingRank);
}


bool CardHandScorer::isStraightFlush(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();

    const Suits firstCardSuit = playerHand[0].getSuit();
    for(int i = 1; i < 5; i++)
    {
        if (firstCardSuit != playerHand[i].getSuit())
        {
            return false;
        }
    }

    ////if rank are in increasing order
//    for(int i = 0; i < 4; i++)
//    {
//        if (playerHand[i].getRank() >= playerHand[i + 1].getRank()) {
//            return false;
//        }
//    }
    for(int i = 0; i < 4; i++)
    {
        if ((playerHand[i].getRank() + 1) != playerHand[i+1].getRank() ) {
            return false;
        }
    }

//    for(int i = 0; i < 4; i++)
//    {
//        if (playerHand[i].getRank() != playerHand[i+1].getRank()+1) {
//            return false;
//        }
//    }


    return true;
}


bool CardHandScorer::isFourOfAKind(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();
    int pairCounter = 0;
    for(int i = 0; i < 4; i++)
    {
        if (playerHand[i].getRank() == playerHand[i+1].getRank())
        {
            pairCounter++;
        }
    }
    if (pairCounter == 3)
    {
        return true;
    }
    return false;



//    const std::vector<Card> playerHand = h.getPlayerCard();
//
//    const Ranks firstCardRank = playerHand[0].getRank();
//    int counter = 0;
//    for(int i = 0; i < 5; i++)
//    {
//        if (playerHand[j].getRank() == playerHand[i].getRank())
//        {
//            counter++;
//        }
//    }
//    if (counter != 4)
//    {
//        return false;
//    }
//    return true;
}


bool CardHandScorer::isFullHouse(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();

    bool firstPair = playerHand[0].getRank() == playerHand[1].getRank() &&
                     playerHand[1].getRank() == playerHand[2].getRank() &&
                     playerHand[3].getRank() == playerHand[4].getRank();

    bool secondPair = playerHand[0].getRank() == playerHand[1].getRank() &&
                      playerHand[2].getRank() == playerHand[3].getRank() &&
                      playerHand[3].getRank() == playerHand[4].getRank();

    return (firstPair || secondPair);


//    const Ranks firstCardRank = playerHand[0].getRank();
//    int counter = 0;
//    for(int i = 0; i < 5; i++)
//    {
//        if (firstCardRank != playerHand[i].getRank())
//        {
//            return false;
//        } else {
//            counter++;
//        }
//    }
//    counter++;
//    for (int i = 0; i < 5; i++)
//    {
//        if (playerHand[counter].getRank() != playerHand[counter + i].getRank())
//        {
//            return false;
//        } else {
//            counter++;
//        }
//    }
//    return true;

}

bool CardHandScorer::isFlush(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();

    const Suits firstCardSuit = playerHand[0].getSuit();
    for(int i = 1; i < 4; i++)
    {
        if (firstCardSuit != playerHand[i].getSuit())
        {
            return false;
        }
    }
    return true;
}


bool CardHandScorer::isStraight(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();
    ////if rank are in increasing order
//    for(int i = 0; i < 4; i++)
//    {
//        if (playerHand[i].getRank() >= playerHand[i + 1].getRank()) {
//            return false;
//        }
//    }
//    return true;
    for(int i = 0; i < 4; i++)
    {
        if ((playerHand[i].getRank() + 1) != playerHand[i+1].getRank()) {
            return false;
        }
    }

    return true;
}


bool CardHandScorer::isThreeOfAKind(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();
    int pairCounter = 0;
    for(int i = 0; i < 4; i++)
    {
        if (playerHand[i].getRank() == playerHand[i+1].getRank())
        {
            pairCounter++;
        }
    }
    if (pairCounter != 2)
    {
        return false;
    }
    return true;
//    const std::vector<Card> playerHand = h.getPlayerCard();
//
//    const Ranks firstCardRank = playerHand[0].getRank();
//    int counter = 0;
//    for(int i = 0; i < 5; i++)
//    {
//        if (firstCardRank == playerHand[i].getRank())
//        {
//            counter++;
//        }
//    }
//    if (counter != 3)
//    {
//        return false;
//    }
//    return true;
}


bool CardHandScorer::isTwoPair(CardHand h)
{
    const std::vector<Card> playerHand = h.getPlayerCard();

    bool possibleFirstPair = playerHand[0].getRank() == playerHand[1].getRank() &&
                             playerHand[2].getRank() == playerHand[3].getRank();

    bool possibleSecondPair = playerHand[0].getRank() == playerHand[1].getRank() &&
                              playerHand[3].getRank() == playerHand[4].getRank();

    bool possibleThirdPair = playerHand[1].getRank() == playerHand[2].getRank() &&
                             playerHand[3].getRank() == playerHand[4].getRank();


    return (possibleFirstPair || possibleSecondPair || possibleThirdPair);

//    for(int i = 0; i < 5; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            if (playerHand[i].getRank() == playerHand[j].getRank())
//            {
//                counter++;
//            }
//        }
//    }
//    return false;
}


bool CardHandScorer::isOnePair(CardHand h){
    const std::vector<Card> playerHand = h.getPlayerCard();


//    bool possibleFirstPair = playerHand[0].getRank() == playerHand[1].getRank() ||
//                             playerHand[1].getRank() == playerHand[2].getRank() ||
//                             playerHand[2].getRank() == playerHand[3].getRank() ||
//                              playerHand[3].getRank() == playerHand[4].getRank();
//
//
//    return (possibleFirstPair);

    for(int i = 0; i < 4; i++)
    {
        if (playerHand[i].getRank() == playerHand[i+1].getRank())
        {
            return true;
        }
    }
    return false;
}




PokerScore CardHandScorer::scorePokerHand(CardHand h, bool & noRoyalFlush) {
    noRoyalFlush = !isRoyalFlush(h);

    return scorePokerHand(h);
}
