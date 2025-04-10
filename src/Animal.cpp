#include "Animal.hpp"
#include <iostream>
#include <random>

Animal::Animal(Matriz &matriz) : floresta(matriz)
{
    this->posicaoAnimal = {matriz.getLinhaInitAnimal(), matriz.getColunaInitAnimal()};
    tipoCampoAtual = floresta.getMapa()[posicaoAnimal.x][posicaoAnimal.y];
    floresta.getMapa()[posicaoAnimal.x][posicaoAnimal.y] = 7;
}

void Animal::movimentaAnimal()
{
    auto &mapa = floresta.getMapa();
    visitados[posicaoAnimal.x][posicaoAnimal.y] = true;

    vector<Posicao> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<Posicao> visaoAnimal;

    for (Posicao d : direcoes)
    {
        int nx = posicaoAnimal.x + d.x;
        int ny = posicaoAnimal.y + d.y;
        if (nx < 0 || nx >= floresta.getLinhas() || ny < 0 || ny >= floresta.getColunas() || visitados[nx][ny] == true || mapa[nx][ny] == 2)
        {
            continue;
        }
        else
        {
            visaoAnimal.push_back({nx, ny});
        };
    }

    Posicao next = {-1, -1};


    next = escolherMelhorPosicao(visaoAnimal);

    tipoCampoAtual = mapa[next.x][next.y];
    mapa[next.x][next.y] = 7;
    mapa[posicaoAnimal.x][posicaoAnimal.y] = tipoCampoAtual;
    posicaoAnimal = next;
}

Animal::Posicao Animal::escolherMelhorPosicao(const vector<Posicao>& posicoes) {
    const auto& mapa = floresta.getMapa();
    Posicao melhorPosicao = {-1, -1};
    int melhorPrioridade = -1;

    for (const auto& pos : posicoes) {
        int valor = mapa[pos.x][pos.y];

        int prioridade = -1;
        if (valor == 4)            prioridade = 3;
        else if (valor == 0 || valor == 1) prioridade = 2;
        else if (valor == 3)       prioridade = 1;

        if (prioridade > melhorPrioridade) {
            melhorPrioridade = prioridade;
            melhorPosicao = pos;
        }
    }

    return melhorPosicao;
}
