#include "Elipse.h"
#include "Rectangulo.h"

/* Requisitos del olimorfismo por herencia

 1. Herencia                             -> Definicion de clase
 2. Virtualizacion / Sobreescritura      -> Definicion de la clase
 3. Uso de punteros                      -> Instanciacion de objetos
 */

int main() {

    Figura* figura;

    figura = new Elipse;
    figura->dibujar();

    figura = new Rectangulo;
    figura->dibujar();

    return 0;
}
