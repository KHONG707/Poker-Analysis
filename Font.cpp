//
// Created by Kristal Hong on 4/2/23.
//

#include "Font.h"
sf::Font Font::font;

void Font::loadFont()
{
    font.loadFromFile("OpenSans-Bold.ttf");
}


sf::Font& Font::getFont()
{
    loadFont();
    return font;
}