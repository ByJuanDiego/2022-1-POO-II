//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_BUTTON_H
#define S9_SFML_BUTTON_H

#include "component.h"
#include "render.h"
#include <SFML/Graphics.hpp>

class button_t: public component_t {
public:

    // button_t(float x, float y, float w, float h): component_t(x, y, w, h) {}
    using component_t::component_t;

    void draw() override
    {
        auto window = render<sf::RenderWindow>::get_instance()->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Yellow);
        window->draw(shape);
    }

};


#endif //S9_SFML_BUTTON_H
