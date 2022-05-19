//
// Created by Juan Diego Castro Padilla on 19/05/22.
//

#ifndef S9_SINGLETON_SINGLETON_H
#define S9_SINGLETON_SINGLETON_H

#include <iostream>
#include <string>

/*
    Patron Singleton

    1. Crear un puntero al un objeto de su misma clase como atributo de clase
    2. Deshabilitar el constructor haciendolo privado
    3. Generar un metodo de clase para construir el objeto
*/

class Singleton{
private:

    std::string text {};
    inline static Singleton* instance = nullptr;
    explicit Singleton(std::string value):text(value){};

public:

    inline static Singleton* get_instance(std::string value = "Default"){
        if (instance == nullptr){
            instance = new Singleton(value);
        }
        return instance;
    }

    [[nodiscard]] std::string get_text() const {
        return text;
    }

    void set_text(const std::string& value){
        text = value;
    }

    ~Singleton(){
        delete instance;
    }
};

#endif //S9_SINGLETON_SINGLETON_H
