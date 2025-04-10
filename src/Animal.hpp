#include "Matriz.hpp"
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
public:
    struct Posicao
    {
        int x, y;
    };
    Posicao posicaoAnimal;
    int tipoCampoAtual;
    Matriz &floresta;
    vector<vector<bool>> visitados = vector<vector<bool>>(floresta.getLinhas(), vector<bool>(floresta.getColunas(), false));
public:
    Animal(Matriz &matriz);
    void movimentaAnimal();
};

#endif