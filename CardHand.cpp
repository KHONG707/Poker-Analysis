//
// Created by Kristal Hong on 3/19/23.
//


#include "CardHand.h"


CardHand::CardHand() {
    //
}


CardHand::CardHand(const std::vector<Card>& c)
{
    playerCards = c;
}

std::vector<Card> CardHand::getPlayerCard() const
{
    return playerCards;
}



void CardHand::addCard(Card c)
{
    playerCards.push_back(c);
}



//Sort cards by rank
void CardHand::sortRank()
{
    for (int i = 0; i < playerCards.size() - 1; i++)
    {
        for (int j = 0; j < playerCards.size() - i - 1; j++)
        {
            if (playerCards[j].getRank() > playerCards[j+1].getRank())
            {
                Card temp = playerCards[j];
                playerCards[j] = playerCards[j + 1];
                playerCards[j+1] = temp;
            }
        }
    }
}





std::ostream& operator<<(std::ostream& out, const CardHand& cardHand)
{
    for (const auto& card : cardHand.playerCards)
    {
        out << card << std::endl;
    }

    return out;
}


void CardHand::resetHand()
{
    while (!playerCards.empty())
    {
        playerCards.pop_back();
    }
}

