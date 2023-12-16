//
// Created by Kristal Hong on 4/2/23.
//

#ifndef POKERANALYSIS_FONT_H
#define POKERANALYSIS_FONT_H

#include <SFML/Graphics.hpp>

class Font {
public:
    static sf::Font& getFont();

private:
    static sf::Font font;
    static void loadFont();
};



#endif //POKERANALYSIS_FONT_H
