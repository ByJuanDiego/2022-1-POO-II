#include "Elipse.h"
#include "Rectangulo.h"
#include <vector>

/* Requisitos del polimorfismo por herencia
 1. Herencia                             -> Definicion de clase
 2. Virtualizacion / Sobreescritura      -> Definicion de la clase
 3. Uso de punteros                      -> Instanciacion de objetos
 */

int main() {

    /* Utilidades del polimorfismo
     - Generar coleccionnes polimorficas
     - Generar funciones polimorficas
     */

    vector<Figura*> vector_figuras;
    vector_figuras.push_back(new Rectangulo);
    vector_figuras.push_back(new Elipse);
    vector_figuras.push_back(new Rectangulo);
    vector_figuras.push_back(new Elipse);

    for (const auto &figura:vector_figuras)
        figura->dibujar();
    

    return 0;
}
