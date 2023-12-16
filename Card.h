//
// Created by Kristal Hong on 3/19/23.
//

#ifndef POKERANALYSIS_CARD_H
#define POKERANALYSIS_CARD_H
#include <iostream>
#include "Ranks.h"
#include "Suits.h"


class Card {
public:
    Card();
    Card(int card);
    Card(Suits suit, Ranks rank);


    Suits getSuit() const;
    Ranks getRank() const;
    void setSuit(Suits suit);
    void setRank(Ranks rank);
    friend std::ostream& operator << (std::ostream& out, const Card& card);

private:

    Suits suit;
    Ranks rank;
    std::string suit_text;
    std::string rank_text;
};


#endif //POKERANALYSIS_CARD_H
