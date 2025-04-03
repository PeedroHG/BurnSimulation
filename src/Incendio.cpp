#include "Incendio.hpp"
#include <iostream>

Incendio::Incendio(Matriz &matriz) : floresta(matriz)
{
    fogos.push({matriz.getLinhaInitChama(), matriz.getColunaInitChama()});
}

bool Incendio::verificaPropagacao(int x, int y)
{
    if (x >= 0 && x < floresta.getLinhas() && y >= 0 && y < floresta.getColunas() && floresta.getMapa()[x][y] != 0 && floresta.getMapa()[x][y] != 2 && floresta.getMapa()[x][y] != 3 && floresta.getMapa()[x][y] != 4)
    {
        return true;
    }
    return false;
}

void Incendio::Propagar()
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    auto &mapa = floresta.getMapa();

    while (!fogos.empty())
    {
        Posicao atual = fogos.front();
        fogos.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];
            if (verificaPropagacao(nx, ny))
            {
                mapa[nx][ny] = 2;
                fogos.push({nx, ny});
            }
        }

        floresta.imprimirMapa();
        cout << endl;
    }
}