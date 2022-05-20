//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_APLICCATION_H
#define S9_SFML_APLICCATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "component.h"
#include "render.h"
#include "lable.h"
#include "button.h"
#include <iostream>

class apliccation {
private:

    std::vector<std::shared_ptr<component_t>> componentes;

public:

    apliccation()
    {
        componentes.push_back(std::make_shared<label_t>(10, 10, 200, 50));
        componentes.push_back(std::make_shared<button_t>(10, 80, 200, 50));
    }

    void run()
    {
        auto window = render<sf::RenderWindow>::
        get_instance(sf::VideoMode(1000, 1000),"Patrones")->get();
        std::cout << window << std::endl;

        while (window->isOpen())
        {

            sf::Event event {};
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    std::cout << "Evento close" << std::endl;
                    window->close();
                }
            }

            window->clear(sf::Color::Blue);
            for (const auto& c : componentes){
                c->draw();
            }
            window->display();

        }
    }

};


#endif //S9_SFML_APLICCATION_H
