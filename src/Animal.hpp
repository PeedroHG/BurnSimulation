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
    int tipoCampoAnterior;
    int passos = 0;
    Matriz &floresta;
    vector<vector<bool>> visitados = vector<vector<bool>>(floresta.getLinhas(), vector<bool>(floresta.getColunas(), false));

public:
    Animal(Matriz &matriz);
    bool dentroDosLimites(int x, int y);
    Posicao escolherMelhorPosicao(const vector<Posicao> &posicoes);
    void dispersaUmidade();
    void movimentaAnimal();

    int getPassos() const { return passos; }
};

#endif