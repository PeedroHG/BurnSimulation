#include "Matriz.hpp"
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:
    struct Posicao
    {
        int x, y;
    };
    Posicao posicaoAnimal;
    Matriz &floresta;

    vector<Posicao> scanPosicoesSeguras();
public:
    Animal(Matriz &matriz);
    void posicionaAnimal();
};

#endif