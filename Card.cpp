//
// Created by Kristal Hong on 3/19/23.
//

#include "Card.h"
Card::Card()
{

}

Card::Card(int card)
{

    if (card >= 0 && card <= 12) {
        setSuit(SPADES);

        setRank(Ranks(card));
    }

    if (card >= 13 && card <= 25)
    {
        setSuit(HEARTS);
        card = card - 13;
        setRank(Ranks(card));

    }

    if (card >= 26 && card <= 38)
    {
        card = card - 26;
        setRank(Ranks(card));
        setSuit(CLUBS);
    }

    if (card >= 39 && card <= 51)
    {
        card = card - 39;
        setRank(Ranks(card));
        setSuit(DIAMONDS);
    }

    //get enums by an indexed integer
    //0- 51
    //0 -12; spades;
    //13-25; hearts; -13
    //36-48; clubs; -26
    //49-51; diamond; -38
}

Card::Card(Suits suit, Ranks rank) : suit(suit), rank(rank)
{
    setRank(rank);
    setSuit(suit);
}


Suits Card::getSuit() const
{
    return suit;
}

Ranks Card::getRank() const
{
    return rank;

}

void Card::setSuit(Suits suit)
{
    this->suit = suit;
    switch(suit) {
        case HEARTS:
            suit_text = "HEARTS";
            break;
        case DIAMONDS:
            suit_text = "DIAMONDS";
            break;
        case CLUBS:
            suit_text = "CLUBS";
            break;
        case SPADES:
            suit_text = "SPADES";
            break;
        case LAST_SUIT:
            suit_text = "LAST SUIT";
            break;
        default:
            suit_text = "none";
    }
}

void Card::setRank(Ranks rank)
{
    this->rank = rank;

    switch(rank){
        case ACE:
            rank_text = "ACE";
            break;
        case TWO:
            rank_text = "TWO";
            break;
        case THREE:
            rank_text = "THREE";
            break;
        case FOUR:
            rank_text = "FOUR";
            break;
        case FIVE:
            rank_text =  "FIVE";
            break;
        case SIX:
            rank_text = "SIX";
            break;
        case SEVEN:
            rank_text = "SEVEN";
            break;
        case EIGHT:
            rank_text = "EIGHT";
            break;
        case NINE:
            rank_text = "NINE";
            break;
        case TEN:
            rank_text = "TEN";
            break;
        case JACK:
            rank_text = "JACK";
            break;
        case QUEEN:
            rank_text = "QUEEN";
            break;
        case KING:
            rank_text = "KING";
            break;
        case LAST_RANK:
            rank_text = "LAST_RANK";
            break;
        default:
            rank_text = "none";
    }
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    out << card.rank_text << " of " << card.suit_text << "\n";

    return out;
}