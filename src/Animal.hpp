#include "Matriz.hpp"
#include <fstream>
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
    string estadoAnimal = "Vivo";
    int tipoCampoAnterior;
    int esperaRestante = 2;
    int passos = 0;
    Matriz &floresta;
    vector<Posicao> caminhoAnimal;
    vector<vector<bool>> visitados = vector<vector<bool>>(floresta.getLinhas(), vector<bool>(floresta.getColunas(), false));

public:
    Animal(Matriz &matriz);
    bool dentroDosLimites(int x, int y);
    Posicao escolherMelhorPosicao(const vector<Posicao> &posicoes);
    void dispersaUmidade();
    void movimentaAnimal(ostream &arquivo);
    bool estaCercadoPorFogo();

    vector<Posicao> &getCaminhoAnimal() { return caminhoAnimal; }
    string getEstadoAnimal() const { return estadoAnimal; }
    void setEstadoAnimal(const string &estado) { estadoAnimal = estado; }
    Posicao getPosicaoDoAnimal() const { return posicaoAnimal; }
    void setTipoCampoAnterior(int tipo) { tipoCampoAnterior = tipo; }
    void setEsperaRestante(int espera) { esperaRestante = espera; }
    int getPassos() const { return passos; }
};

#endif