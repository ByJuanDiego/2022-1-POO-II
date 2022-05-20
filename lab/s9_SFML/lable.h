//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_LABLE_H
#define S9_SFML_LABLE_H

#include "component.h"
#include <SFML/Graphics.hpp>
#include "render.h"
#include <iostream>

class label_t: public component_t {
public:

    using component_t::component_t;

    void draw() override
    {
        auto window = render<sf::RenderWindow>::get_instance()->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Red);
        window->draw(shape);
    }

};



#endif //S9_SFML_LABLE_H
