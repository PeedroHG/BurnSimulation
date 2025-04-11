#include <iostream>
#include "Matriz.hpp"
#include "Incendio.hpp"
#include "Animal.hpp"
#include <chrono>
#include <thread>
#include "Simulacao.hpp"

using namespace std;

int main()
{
    srand(time(0));
    string nomeArquivo = "./input/input.dat";
    Matriz mapa;
    mapa.carregarArquivo(nomeArquivo);

    Incendio incendio(mapa);
    Animal animal(mapa);
    Simulacao simulacao(mapa, incendio, animal);
    simulacao.Simular();
    return 0;
}