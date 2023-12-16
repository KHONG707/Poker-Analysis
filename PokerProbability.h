//
// Created by Kristal Hong on 4/2/23.
//

#ifndef POKERANALYSIS_POKERPROBABILITY_H
#define POKERANALYSIS_POKERPROBABILITY_H
#include <SFML/Graphics.hpp>
#include "CardHandScorer.h"
#include "CardHand.h"
#include "Font.h"
#include "PokerScore.h"
#include <cmath>

class PokerProbability : public sf::Drawable
{
public:
    PokerProbability();
    PokerProbability(int s[10]);
    void setText(const std::string& text);
    void setTopPosition(float x, float y);
    void setBottomPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::string setScoreText(int num);
private:
    sf::Text probability[10];
};


#endif //POKERANALYSIS_POKERPROBABILITY_H
