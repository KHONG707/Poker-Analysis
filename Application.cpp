//
// Created by Kristal Hong on 3/29/23.
//

#include "Application.h"
//#include "SFMLCard.h"
#include "CardSet.h"
#include "PokerProbability.h"

sf::RenderWindow Application::window;
//actually creating it bc it's a static private
std::vector<Component*> Application::components;

void Application::run()
{
    window.create({1024, 720, 32}, "Poker Cards");
    window.setFramerateLimit(60);

    CardSet c1(ROYAL_FLUSH);
    CardSet c2(STRAIGHT_FLUSH);
    CardSet c3(FOUR_OF_A_KIND);
    CardSet c4(FULL_HOUSE);
    CardSet c5(FLUSH);
    CardSet c6(STRAIGHT);
    CardSet c7(THREE_OF_A_KIND);
    CardSet c8(TWO_PAIR);
    CardSet c9(ONE_PAIR);
    CardSet c10(HIGH_CARD);
    PokerProbability scoring(PokerScore::s);

    c2.setInitPos(5, 60);
    c3.setInitPos(5, 120);
    c4.setInitPos(5,180);
    c5.setInitPos(5,240);
    c6.setInitPos(5,300);
    c7.setInitPos(5, 360);
    c8.setInitPos(5,420);
    c9.setInitPos(5,480);
    c10.setInitPos(5,540);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            //if there is input/event happening, exits or skips if none found
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        for(Component* c : components)
        {
            window.draw(*c);
        }
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        window.draw(c4);
        window.draw(c5);
        window.draw(c6);
        window.draw(c7);
        window.draw(c8);
        window.draw(c9);
        window.draw(c10);

        window.draw(scoring);

        window.display();
    }

}

void Application::addComponent(Component &component)
{
    components.push_back(&component);
}
