#include "Incendio.hpp"
#include "Config.hpp"
#include <iostream>

Incendio::Incendio(Matriz &matriz) : floresta(matriz)
{
    int x = matriz.getLinhaInitChama();
    int y = matriz.getColunaInitChama();

    Posicao inicio = {x, y};

    fogos.push(inicio);
    fogosAtt.push(inicio);
    matriz.getMapa()[x][y] = 2; 
}


bool Incendio::verificaPropagacao(int x, int y)
{
    if (x >= 0 && x < floresta.getLinhas() && y >= 0 && y < floresta.getColunas() && floresta.getMapa()[x][y] != 0 && floresta.getMapa()[x][y] != 2 && floresta.getMapa()[x][y] != 3 && floresta.getMapa()[x][y] != 4 && floresta.getMapa()[x][y] != 7)
    {
        return true;
    }
    return false;
}

void Incendio::configuraVento(vector<Posicao> &direcoes)
{
    if (VENTO_ESQUERDA && VENTO_DIREITA)
    {
        cout << "Vento configurado para duas direções opostas ao mesmo tempo: esquerda e direita.\n";
        exit(0);
    }
    if (VENTO_CIMA && VENTO_BAIXO)
    {
        cout << "Vento configurado para duas direções opostas ao mesmo tempo: cima e baixo.\n";
        exit(0);
    }

    if (VENTO_ESQUERDA)
        direcoes.push_back({0, -1});
    if (VENTO_DIREITA)
        direcoes.push_back({0, 1});
    if (VENTO_CIMA)
        direcoes.push_back({-1, 0});
    if (VENTO_BAIXO)
        direcoes.push_back({1, 0});

    if (direcoes.empty())
    {
        direcoes = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    }
}

void Incendio::Propagar()
{   
    Queimar();
    vector<Posicao> direcoes;
    configuraVento(direcoes);

    auto &mapa = floresta.getMapa();

    while (!fogos.empty())
    {
        Posicao atual = fogos.front();
        fogos.pop();

        for (Posicao d : direcoes)
        {
            int nx = atual.x + d.x;
            int ny = atual.y + d.y;
            if (verificaPropagacao(nx, ny))
            {
                mapa[nx][ny] = 2;
                fogosAtt.push({nx, ny});
            }
        }
    }
}

void Incendio::Queimar()
{
    auto &mapa = floresta.getMapa();

    while (!fogosAtt.empty())
    {
        fogos.push(fogosAtt.front());
        mapa[fogosAtt.front().x][fogosAtt.front().y] = 3;
        fogosAtt.pop();
    }
}