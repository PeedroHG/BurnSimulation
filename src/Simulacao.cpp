#include "Simulacao.hpp"
#include <iostream>

void Simulacao::Simular() {
    cout << "Mapa Inicial:" << endl;
    floresta.imprimirMapa();
    cout << endl;

    for (int i = 0; i < 2; i++) {
        animal.movimentaAnimal();
        cout << "Movimentação do Animal:" << endl;
        floresta.imprimirMapa();
        cout << "Propagação dos Fogos:" << endl;
        incendio.Propagar();
        floresta.imprimirMapa();

        cout << endl;
    }
}