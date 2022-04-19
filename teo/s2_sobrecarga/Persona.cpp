//
// Created by Juan Diego Castro Padilla on 30/03/22.
//

#include "Persona.h"

Persona::Persona() = default;

Persona::Persona(string&& nombre, string&& dni): nombre(nombre), dni(dni){
}

string Persona::get_nombre() const{
    return nombre;
}

string Persona::get_dni() const{
    return dni;
}

void Persona::set_nombre(string&& value){
    nombre = value;
}

void Persona::set_dni(string&& value){
    dni = value;
}

string Persona::get_clase(){
    return clase;
}

int Persona::sumar(int a, int b){
    return (a+b);
}
