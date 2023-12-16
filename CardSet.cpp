//
// Created by Kristal Hong on 3/30/23.
//

#include "CardSet.h"
CardSet::CardSet()
{
    //
}

CardSet::CardSet(Scores pokerScore) {
    this->pokerScore = pokerScore;
    switch (static_cast<int> (this->pokerScore)) {
        case ROYAL_FLUSH:
            setRoyalFlush();
        case STRAIGHT_FLUSH:
            setStraightFlush();
        case FOUR_OF_A_KIND:
            setFourOfKind();
        case FULL_HOUSE:
            setFullHouse();
        case FLUSH:
            setFlush();
        case STRAIGHT:
            setStraight();
        case THREE_OF_A_KIND:
            setThreeOfKind();
        case TWO_PAIR:
            setTwoPair();
        case ONE_PAIR:
            setOnePair();
        case HIGH_CARD:
            setLowCard();
    }
    adjustPos(5 ,5);
}

void CardSet::setRoyalFlush() {
    Suits suits[NUM_CARDS] = {DIAMONDS, DIAMONDS, DIAMONDS, DIAMONDS, DIAMONDS};
    Ranks ranks[NUM_CARDS] = {TEN, JACK, QUEEN, KING, ACE};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setStraightFlush() {
    Suits suits[NUM_CARDS] = {HEARTS, HEARTS, HEARTS, HEARTS, HEARTS};
    Ranks ranks[NUM_CARDS] = {FOUR, FIVE, SIX, SEVEN, EIGHT};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setFourOfKind() {
    Suits suits[NUM_CARDS] = {DIAMONDS, HEARTS, SPADES, CLUBS, CLUBS};
    Ranks ranks[NUM_CARDS] = {QUEEN, QUEEN, QUEEN, QUEEN, TEN};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setFullHouse() {
    Suits suits[NUM_CARDS] = {HEARTS, DIAMONDS, DIAMONDS, SPADES, HEARTS};
    Ranks ranks[NUM_CARDS] = {KING, KING, THREE, THREE, THREE};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setFlush() {
    Suits suits[NUM_CARDS] = {SPADES, SPADES, SPADES, SPADES, SPADES};
    Ranks ranks[NUM_CARDS] = {ACE, TWO, SIX, JACK, NINE};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setStraight() {
    Suits suits[NUM_CARDS] = {CLUBS, CLUBS, DIAMONDS, CLUBS, HEARTS};
    Ranks ranks[NUM_CARDS] = {KING, QUEEN, JACK, TEN, NINE};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setThreeOfKind() {
    Suits suits[NUM_CARDS] = {HEARTS, CLUBS, CLUBS, SPADES, HEARTS};
    Ranks ranks[NUM_CARDS] = {JACK, FIVE, EIGHT, EIGHT, EIGHT};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setTwoPair() {
    Suits suits[NUM_CARDS] = {DIAMONDS, SPADES, HEARTS, CLUBS, HEARTS};
    Ranks ranks[NUM_CARDS] = {ACE, SEVEN, SEVEN, QUEEN, QUEEN};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setOnePair() {
    Suits suits[NUM_CARDS] = {DIAMONDS, HEARTS, CLUBS, CLUBS, SPADES};
    Ranks ranks[NUM_CARDS] = {TWO, SIX, TEN, JACK, JACK};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}

void CardSet::setLowCard() {
    Suits suits[NUM_CARDS] = {DIAMONDS, CLUBS, CLUBS, SPADES, HEARTS};
    Ranks ranks[NUM_CARDS] = {SEVEN, FIVE, THREE, FOUR, TWO};
    for (int i = 0; i < NUM_CARDS; i++) {
        cardSet.push_back(SFMLCard(ranks[i], suits[i]));
    }
}


void CardSet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < NUM_CARDS; i++) {
        target.draw(cardSet[i]);
    }
}

void CardSet::adjustPos(float start_x, const float start_y) {
    float interval_width = 20;
    float width_card = 0;
    for (int i = 0; i < NUM_CARDS; i++) {
        start_x += width_card + interval_width;
        cardSet[i].setPosition({start_x,start_y});
        width_card = cardSet[i].getGlobalBounds().width;
    }
}

void CardSet::setInitPos(int x, int y) {
    adjustPos(x, y);
}
