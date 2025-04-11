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

int Incendio::verificaPropagacao(int x, int y)
{
    if (x < 0 || x >= floresta.getLinhas() || y < 0 || y >= floresta.getColunas())
        return 0;

    int valor = floresta.getMapa()[x][y];

    if (valor == 1)
        return 1; // pode propagar

    if (valor == 7)
        return 2; // tentou atingir o animal

    return 0; // demais casos: água, queimado, vazio, fogo, etc.
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

bool Incendio::Propagar()
{
    Queimar();

    vector<Posicao> direcoes;
    configuraVento(direcoes);
    bool morto = false;
    auto &mapa = floresta.getMapa();
    bool houvePropagacao = false;

    while (!fogos.empty())
    {
        Posicao atual = fogos.front();
        fogos.pop();

        for (Posicao d : direcoes)
        {
            int nx = atual.x + d.x;
            int ny = atual.y + d.y;

            int resultadoPropagacao = verificaPropagacao(nx, ny);

            if (resultadoPropagacao == 1)
            {
                mapa[nx][ny] = 2;
                fogosAtt.push({nx, ny});
                houvePropagacao = true;
            }
            else if (resultadoPropagacao == 2)
            {
                morto = true;
            }
        }
    }

    if (morto)
    {
        cout << "Animal morreu queimado e tem mais uma vida!\n";
    }
    return houvePropagacao;
}

void Incendio::Queimar()
{
    auto &mapa = floresta.getMapa();

    while (!fogosAtt.empty())
    {
        Posicao p = fogosAtt.front();
        fogosAtt.pop();

        if (mapa[p.x][p.y] == 2)
        {
            mapa[p.x][p.y] = 3;
            fogos.push(p);
        }
    }
}