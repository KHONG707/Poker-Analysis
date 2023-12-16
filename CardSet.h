//
// Created by Kristal Hong on 3/30/23.
//

#ifndef POKERANALYSIS_CARDSET_H
#define POKERANALYSIS_CARDSET_H
#include "SFMLCard.h"
#include "PokerScore.h"
#include "vector"

class CardSet: public sf::Drawable {
private:
    const static int NUM_CARDS = 5;
    std::vector<SFMLCard> cardSet;
    Scores pokerScore;
    void setRoyalFlush();
    void setStraightFlush();
    void setFourOfKind();
    void setFullHouse();
    void setFlush();
    void setStraight();
    void setThreeOfKind();
    void setTwoPair();
    void setOnePair();
    void setLowCard();


    void adjustPos(float start_x, const float start_y);
public:
    CardSet();
    CardSet(Scores pokerScore);
    void setInitPos(int x, int y);
    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //POKERANALYSIS_CARDSET_H
