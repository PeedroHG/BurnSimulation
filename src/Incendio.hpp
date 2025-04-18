#include <utility>
#include "Matriz.hpp"
#include <queue>

#ifndef INCENDIO_HPP
#define INCENDIO_HPP

class Incendio
{
public:
    struct Posicao
    {
        int x, y;
    };

private:
    queue<Posicao> fogos;
    queue<Posicao> fogosAtt;
    Matriz &floresta;
    bool vento[4];

public:
    Incendio(Matriz &matriz);
    void configuraVento(vector<Posicao> &direcoes);
    int verificaPropagacao(int x, int y);
    int Propagar();
    void Queimar();

    queue<Posicao> &getFogos() { return fogos; }
    queue<Posicao> &getFogosAtt() { return fogosAtt; }
    queue<Posicao> getCopiaFogosAtt() const
    {
        return fogosAtt;
    }
};

#endif