//
// Created by Kristal Hong on 3/29/23.
//

#ifndef POKERANALYSIS_APPLICATION_H
#define POKERANALYSIS_APPLICATION_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <vector>

class Application {
public:
    static void run();
    static void addComponent(Component& component);
private:
    static sf::RenderWindow window;
    //no need to make object, only use it once
    //belongs to class not object
    static std::vector<Component*> components;
};


#endif //POKERANALYSIS_APPLICATION_H
