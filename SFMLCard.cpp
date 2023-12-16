//
// Created by Kristal Hong on 3/29/23.
//

#include "SFMLCard.h"


sf::Texture SFMLCard::texture;

SFMLCard::SFMLCard()
{
    //
}

SFMLCard::SFMLCard(Ranks rank, Suits suit)
{
    texture.loadFromFile("PlayingCardImages.png");

    intRect.width = 2925/13;
    intRect.height = 1260/4;
    updateCard(rank, suit);

    background.setTexture(texture);
    background.setScale(0.45f,0.45f);
}

void SFMLCard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(background);
}


sf::Rect<float> SFMLCard::getGlobalBounds() const {
    return background.getGlobalBounds();
}

void SFMLCard::updateCard(Ranks rank, Suits suit)
{
    intRect.left = rank * intRect.width;
    intRect.top = suit*intRect.height;
    background.setTextureRect(intRect);
}

void SFMLCard::setPosition(sf::Vector2f position) {
    background.setPosition(position);
}
