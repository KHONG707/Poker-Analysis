#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "CardHand.h"
#include "PokerScore.h"
#include "CardHandScorer.h"
#include "Application.h"

int main() {
    srand(time(0));
    Deck deck;

    std::cout << deck;
    std::cout << std::endl;

    Card dealtCard;
    CardHand theCards;
    PokerScore pokerScore;

    bool noRoyalFlush = true;


    while(noRoyalFlush) {
//        keep iterating until a royal flush is obtained
        for (int j = 0; j < 5; j++) {
            dealtCard = deck.dealCard();
            theCards.addCard(dealtCard);
        }
        theCards.sortRank();
//        std::cout << theCards << std::endl;
        pokerScore += CardHandScorer::scorePokerHand(theCards, noRoyalFlush);
        deck.resetDeck();
        //Clear hand for a new check
        theCards.resetHand();
    }


    std::cout << pokerScore << std::endl;


////Test
//    CardHand test({{CLUBS, KING}, {DIAMONDS, NINE}, {CLUBS, JACK}, {HEARTS, QUEEN}, {HEARTS, TEN}});
//    test.sortRank();
//    pokerScore = CardHandScorer::scorePokerHand(test);
//    std::cout << test << std::endl;
//    std::cout << pokerScore << std::endl;



    Application::run();
    return 0;
}
