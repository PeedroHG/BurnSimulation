#include <utility>
#include "Matriz.hpp"
#include <queue>

#ifndef INCENDIO_HPP
#define INCENDIO_HPP

class Incendio
{
private:
    struct Posicao
    {
        int x, y;
    };
    queue<Posicao> fogosAtt;
    queue<Posicao> fogos;
    Matriz &floresta;
    bool vento[4];

public:
    Incendio(Matriz &matriz);
    void configuraVento(vector<Posicao> &direcoes);
    int verificaPropagacao(int x, int y);
    bool Propagar();
    void Queimar();
};

#endif