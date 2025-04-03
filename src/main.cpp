#include <iostream>
#include "Matriz.hpp"
#include "Incendio.hpp"
using namespace std;

int main() {
    string nomeArquivo = "./input/input.dat";
    Matriz mapa;
    mapa.carregarArquivo(nomeArquivo);
    Incendio incendio(mapa);

    cout << endl;
    incendio.Propagar();

    return 0;
}