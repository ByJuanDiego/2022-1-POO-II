#include "Elipse.h"
#include "Rectangulo.h"
#include <vector>

/* Requisitos del polimorfismo por herencia
 1. Herencia                             -> Definicion de clase
 2. Virtualizacion / Sobreescritura      -> Definicion de la clase
 3. Uso de punteros                      -> Instanciacion de objetos
 */

void mover_figura(Figura* figura, int dx, int dy){
    figura->set_x(figura->get_x() + dx);
    figura->set_y(figura->get_y() + dy);
}

void identificar_clase(Figura* figura) {
    if (dynamic_cast<Elipse*>(figura) != nullptr){
        cout << "Es elipse" << endl;
    } else if (dynamic_cast<Rectangulo*>(figura) != nullptr){
        cout << "Es Rectangulo" << endl;
    } else{
        cout << "No es ninguno" << endl;
    }

}

int main() {

    /* Utilidades del polimorfismo
     - Generar coleccionnes polimorficas
     - Generar funciones polimorficas
     */

    vector<Figura*> vector_figuras;
    vector_figuras.push_back(new Rectangulo(1, 2));
    vector_figuras.push_back(new Elipse (2, 0));

    for (const auto &figura:vector_figuras)
        mover_figura(figura, 1, -1);

    for (const auto &figura:vector_figuras) {
        identificar_clase(figura);
        figura -> dibujar();
        cout << "x: " << figura->get_x() << " y: " << figura->get_y() << endl << endl;
    }

    return 0;
}
