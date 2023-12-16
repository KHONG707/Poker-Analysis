
// Created by Kristal Hong on 4/2/23.


#include "PokerProbability.h"
PokerProbability::PokerProbability()
{
    //
}

PokerProbability::PokerProbability(int s[10])
{
    float probabilityScore[10];

    for (int i = 0; i< Scores::HIGH_CARD + 1; i++)
    {
        probabilityScore[i] = (float)1/ ((float)(s[i])/(float)(s[HIGH_CARD]));
//        probabilityScore[i] = (float)1/ (float)(pokerScore.getScore(Scores(i))/pokerScore.getScore(HIGH_CARD));

        std::string probabilityText = (setScoreText(i) + std::to_string((int)round(probabilityScore[i])) + " : 1");
        probability[i].setFont(Font::getFont());
        probability[i].setString(probabilityText);
        probability[i].setPosition(650,30+(i*65));
        probability[i].setFillColor(sf::Color::White);
        probability[i].setCharacterSize(18);
    }
}



void PokerProbability::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for (const sf::Text& probabilityScore : probability)
    {
        window.draw(probabilityScore);
    }
}


void PokerProbability::setText(const std::string& text)
{
    for (int i = 0; i < Scores::HIGH_CARD + 1; i++) {
        probability[i].setString(text);
    }

}

void PokerProbability::setTopPosition(float x, float y)
{
    for (int i = 0; i < Scores::HIGH_CARD + 1; i++)
    {
        probability[i].setPosition(x, y);
    }

}

std::string PokerProbability::setScoreText(int num)
{
    switch (num)
    {
        case ROYAL_FLUSH:
            return "Royal Flush: ";
        case STRAIGHT_FLUSH:
            return "Straight Flush: ";
        case FOUR_OF_A_KIND:
            return "Four of a Kind: ";
        case FULL_HOUSE:
            return "Full House: ";
        case FLUSH:
            return "Flush: ";
        case STRAIGHT:
            return "Straight: ";
        case THREE_OF_A_KIND:
            return "Three of a Kind: ";
        case TWO_PAIR:
            return "Two Pair: ";
        case ONE_PAIR:
            return "One Pair: ";
        case HIGH_CARD:
            return "High Card: ";
    }
}

