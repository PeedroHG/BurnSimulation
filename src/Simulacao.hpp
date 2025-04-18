#include "Matriz.hpp"
#include "Animal.hpp"
#include "Incendio.hpp"
#include "Config.hpp"
#ifndef SIMULACAO_HPP
#define SIMULACAO_HPP

using namespace std;
class Simulacao
{
private:
    Matriz &floresta;
    Incendio &incendio;
    Animal &animal;

public:
    Simulacao(Matriz &matriz, Incendio &incendio, Animal &animal);
    void limpaTerminal();
    void Simular();
    void SimularTerminal();
    void MatrixToCharMap(ofstream& arquivo);
};
#endif