//
// Created by Kristal Hong on 3/20/23.
//

#include "PokerScore.h"

int PokerScore::s[10];

PokerScore::PokerScore()
{
    //
}

void PokerScore::operator += (const Scores& score)
{
    switch (score) {
        case ROYAL_FLUSH:
            s[ROYAL_FLUSH]++;
            break;
        case STRAIGHT_FLUSH:
            s[STRAIGHT_FLUSH]++;
            break;
        case FOUR_OF_A_KIND:
            s[FOUR_OF_A_KIND]++;
            break;
        case FULL_HOUSE:
            s[FULL_HOUSE]++;
            break;
        case FLUSH:
            s[FLUSH]++;
            break;
        case STRAIGHT:
            s[STRAIGHT]++;
            break;
        case THREE_OF_A_KIND:
            s[THREE_OF_A_KIND]++;
            break;
        case TWO_PAIR:
            s[TWO_PAIR]++;
            break;
        case ONE_PAIR:
            s[ONE_PAIR]++;
            break;
        case HIGH_CARD:
            s[HIGH_CARD]++;
            break;
    }
    scores.push_back(score);
}


//bool operator == (const PokerScore& p, Scores score)
//{
//    return (p == score);
//}

std::ostream& operator << (std::ostream& out, const PokerScore& score)
{
    int s[10] = {0};

    for (const auto& scores : score.scores) {

        switch (scores) {
            case ROYAL_FLUSH:
                s[ROYAL_FLUSH]++;
                break;
            case STRAIGHT_FLUSH:
                s[STRAIGHT_FLUSH]++;
                break;
            case FOUR_OF_A_KIND:
                s[FOUR_OF_A_KIND]++;
                break;
            case FULL_HOUSE:
                s[FULL_HOUSE]++;
                break;
            case FLUSH:
                s[FLUSH]++;
                break;
            case STRAIGHT:
                s[STRAIGHT]++;
                break;
            case THREE_OF_A_KIND:
                s[THREE_OF_A_KIND]++;
                break;
            case TWO_PAIR:
                s[TWO_PAIR]++;
                break;
            case ONE_PAIR:
                s[ONE_PAIR]++;
                break;
            case HIGH_CARD:
                s[HIGH_CARD]++;
                break;
        }
    }


        out << "ROYAL_FLUSH: " << s[0] << std::endl
        << "STRAIGHT_FLUSH: " << s[1] << std::endl
        << "FOUR_OF_A_KIND: " << s[2] << std::endl
        << "FULL_HOUSE: " << s[3] << std::endl
        << "FLUSH: " << s[4] << std::endl
        << "STRAIGHT: " << s[5] << std::endl
        << "THREE_OF_A_KIND: " << s[6] << std::endl
        << "TWO_PAIR: " << s[7] << std::endl
        << "ONE_PAIR: " << s[8] << std::endl
        << "HIGH_CARD: " << s[9] << std::endl;
    return out;
}



void PokerScore::operator += (const PokerScore& pokerScore)
{
    for (int i = 0; i < pokerScore.scores.size(); i++)
    {
        //bring the switch case here, and use the pokerScore.scores[i] to increment the score.
        switch (pokerScore.scores[i]) {
            case ROYAL_FLUSH:
                s[ROYAL_FLUSH]++;
                break;
            case STRAIGHT_FLUSH:
                s[STRAIGHT_FLUSH]++;
                break;
            case FOUR_OF_A_KIND:
                s[FOUR_OF_A_KIND]++;
                break;
            case FULL_HOUSE:
                s[FULL_HOUSE]++;
                break;
            case FLUSH:
                s[FLUSH]++;
                break;
            case STRAIGHT:
                s[STRAIGHT]++;
                break;
            case THREE_OF_A_KIND:
                s[THREE_OF_A_KIND]++;
                break;
            case TWO_PAIR:
                s[TWO_PAIR]++;
                break;
            case ONE_PAIR:
                s[ONE_PAIR]++;
                break;
            case HIGH_CARD:
                s[HIGH_CARD]++;
                break;
        }
        scores.push_back(pokerScore.scores[i]);
    }
}

