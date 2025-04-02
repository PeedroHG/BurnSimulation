#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main() {
    string nomeArquivo = "./input/input.dat";
    Matriz mapa;
    mapa.carregarArquivo(nomeArquivo);
    cout << mapa.getLinhas() << endl;
    cout << mapa.getColunas() << endl;
    cout << mapa.getLinhaInitChama() << endl;
    cout << mapa.getColunaInitChama() << endl;
    return 0;
}