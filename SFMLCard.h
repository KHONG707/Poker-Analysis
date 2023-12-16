//
// Created by Kristal Hong on 3/29/23.
//

#ifndef POKERANALYSIS_SFMLCARD_H
#define POKERANALYSIS_SFMLCARD_H
#include "Component.h"
#include "Suits.h"
#include "Ranks.h"

class SFMLCard : public Component
{
public:
    SFMLCard();
    SFMLCard(Ranks rank, Suits suit);

    void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setPosition(sf::Vector2f position);
    sf::Rect<float> getGlobalBounds() const;

private:
    sf::Sprite background;
    sf::IntRect intRect;
    static sf::Texture texture; //holds the image

    void updateCard(Ranks rank, Suits suit);
};

#endif //POKERANALYSIS_SFMLCARD_H
