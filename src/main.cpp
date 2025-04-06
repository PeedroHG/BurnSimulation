#include <iostream>
#include "Matriz.hpp"
#include "Incendio.hpp"
using namespace std;

int main() {
    string nomeArquivo = "./input/input.dat";
    Matriz mapa;
    mapa.carregarArquivo(nomeArquivo);
    Incendio incendio(mapa);

    for(int i = 0; i < 6; i++){
        cout << endl;
        incendio.Propagar();
    }

    return 0;
}