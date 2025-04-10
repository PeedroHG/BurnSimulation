#include <iostream>
#include "Matriz.hpp"
#include "Incendio.hpp"
#include "Animal.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    string nomeArquivo = "./input/input.dat";
    Matriz mapa;
    mapa.carregarArquivo(nomeArquivo);
    Incendio incendio(mapa);
    Animal animal(mapa);
    // animal.posicionaAnimal();
    
    animal.posicaoAnimal = {4, 0};
    animal.tipoCampoAtual = 1;
    mapa.getMapa()[animal.posicaoAnimal.x][animal.posicaoAnimal.y] = 7;

    system("clear");

    for (int i = 0; i < 6; i++)
    {
        cout << endl;
        animal.movimentaAnimal();
        incendio.Propagar();
        mapa.imprimirMapa();
        incendio.Queimar();
        this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }

    return 0;
}