#include "Simulacao.hpp"
#include "Config.hpp"
#include <iostream>

void Simulacao::Simular() {
    cout << "Mapa Inicial:" << endl;
    floresta.imprimirMapa();
    cout << endl;

    for (int i = 0; i < MAX_ITERACOES; i++) 
    {
        animal.movimentaAnimal();
        cout << "Movimentação do Animal:" << endl;
        floresta.imprimirMapa();

        cout << "Propagação dos Fogos:" << endl;
        bool propagou = incendio.Propagar();
        floresta.imprimirMapa();

        if (!propagou) {
            cout << "\n🔥 Fogo extinto. Encerrando simulação.\n";
            cout << "🦌 Passos do animal: " << animal.getPassos() << endl;
            break;
        }

        cout << endl;
    }
}
