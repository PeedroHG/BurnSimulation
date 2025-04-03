#include <utility>
#include "Matriz.hpp"
#include <queue>

class Incendio
{
private:
    struct Posicao
    {
        int x, y;
    };
    queue<Posicao> fogos;
    Matriz &floresta;
    bool vento[4];

public:
    Incendio(Matriz &matriz);
    bool verificaPropagacao(int x, int y);
    void Propagar();
};
