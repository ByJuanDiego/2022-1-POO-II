//
// Created by Juan Diego Castro Padilla on 30/03/22.
//

#ifndef SEMANA2_PERSONA_H
#define SEMANA2_PERSONA_H

#include <iostream>
using namespace std;

class Persona {

    // Atributos de objeto
    string nombre;
    string dni;

    // Atributo de Clase
    inline static string clase = "persona";

public:

    // Constructores
    Persona();
    Persona(string&& nombre, string&& dni);

    // Metodos disponibles para tipos constantes
    string get_nombre() const;
    string get_dni() const;

    // Metodos no disponible en tipos constantes
    void set_nombre(string&& value);
    void set_dni(string&& value);

    // Metodos de clase (Metodos estaticos)
    static string get_clase();
    static int sumar(int a, int b);

};


#endif //SEMANA2_PERSONA_H
