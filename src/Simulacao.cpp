#include "Simulacao.hpp"
#include <iostream>

void Simulacao::Simular() {
    floresta.imprimirMapa();
    cout << endl;

    for (int i = 0; i < 10; i++) {
        animal.movimentaAnimal();
        incendio.Propagar();
        floresta.imprimirMapa();
        incendio.Queimar();
        cout << endl;
    }
}