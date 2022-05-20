//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SFML_COMPONENT_H
#define S9_SFML_COMPONENT_H


class component_t {

protected:
    float x = 0, y = 0;
    float width = 0, height = 0;

public:
    component_t(float x, float y, float w, float h):x(x), y(y), width(w), height(h) {}
    virtual void draw() = 0;

};


#endif //S9_SFML_COMPONENT_H
