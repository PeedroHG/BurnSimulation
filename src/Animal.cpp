#include "Animal.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

Animal::Animal(Matriz &matriz) : floresta(matriz)
{
    int x = matriz.getLinhaInitAnimal();
    int y = matriz.getColunaInitAnimal();

    posicaoAnimal = {x, y};

    auto &mapa = floresta.getMapa();
    tipoCampoAnterior = mapa[x][y];
    mapa[x][y] = 7;
}

bool Animal::dentroDosLimites(int x, int y)
{
    return x >= 0 && x < floresta.getLinhas() &&
           y >= 0 && y < floresta.getColunas();
}

bool Animal::estaCercadoPorFogo() {
    int x = posicaoAnimal.x;
    int y = posicaoAnimal.y;

    int fogoAoRedor = 0;
    int vizinhosValidos = 0;

    int dx[] = {-1, 1, 0, 0}; // cima, baixo, esquerda, direita
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dentroDosLimites(nx, ny)) {
            vizinhosValidos++;
            if (floresta.getMapa()[nx][ny] == 2) {  // se for fogo
                fogoAoRedor++;
            }
        }
    }

    return vizinhosValidos > 0 && fogoAoRedor == vizinhosValidos;
}

void Animal::movimentaAnimal()
{
    auto &mapa = floresta.getMapa();
    visitados[posicaoAnimal.x][posicaoAnimal.y] = true;

    vector<Posicao> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<Posicao> visaoAnimal;

    if (tipoCampoAnterior == 0 && esperaRestante > 0)
    {
        int sorteio = rand() % 2;
        if(sorteio == 1)
        {
            esperaRestante--;
            return;
        }
    }

    for (Posicao d : direcoes)
    {
        int nx = posicaoAnimal.x + d.x;
        int ny = posicaoAnimal.y + d.y;

        if (dentroDosLimites(nx, ny) && visitados[nx][ny] == false && mapa[nx][ny] != 2)
        {
            visaoAnimal.push_back({nx, ny});
        }
        else
        {
            continue;
        }
    }

    Posicao next = {-1, -1};

    next = escolherMelhorPosicao(visaoAnimal);

    // Volta o mapa para o campo anterior
    mapa[posicaoAnimal.x][posicaoAnimal.y] = tipoCampoAnterior;

    // Guarda o tipo do campo q ta indo
    tipoCampoAnterior = mapa[next.x][next.y];

    // Atualiza a matriz com o animal
    mapa[next.x][next.y] = 7;

    // Atualiza o animal
    posicaoAnimal = next;
    passos++;

    if (tipoCampoAnterior == 4)
    {
        tipoCampoAnterior = 0;
        dispersaUmidade();
    }
}

void Animal::dispersaUmidade()
{
    auto &mapa = floresta.getMapa();
    vector<Posicao> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (Posicao d : direcoes)
    {
        int nx = posicaoAnimal.x + d.x;
        int ny = posicaoAnimal.y + d.y;

        if (dentroDosLimites(nx, ny))
        {
            mapa[nx][ny] = 1;
        }
    }
}

Animal::Posicao Animal::escolherMelhorPosicao(const vector<Posicao> &posicoes)
{
    const auto &mapa = floresta.getMapa();
    Posicao melhorPosicao = {-1, -1};
    int melhorPrioridade = -1;

    for (const auto &pos : posicoes)
    {
        int valor = mapa[pos.x][pos.y];

        int prioridade = -1;
        if (valor == 4)
            prioridade = 3;
        else if (valor == 0 || valor == 1)
            prioridade = 2;
        else if (valor == 3)
            prioridade = 1;

        if (prioridade > melhorPrioridade)
        {
            melhorPrioridade = prioridade;
            melhorPosicao = pos;
        }
    }

    return melhorPosicao;
}
