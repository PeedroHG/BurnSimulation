#include "Animal.hpp"
#include <iostream>
#include <random>

Animal::Animal(Matriz &matriz) : floresta(matriz)
{
}

vector<Animal::Posicao> Animal::scanPosicoesSeguras()
{
    auto &mapa = floresta.getMapa();
    vector<Animal::Posicao> seguras;

    for (int i = 0; i < floresta.getLinhas(); i++)
    {
        for (int j = 0; j < floresta.getColunas(); j++)
        {
            if (mapa[i][j] == 0 || mapa[i][j] == 1)
            {
                seguras.push_back({i, j});
            }
        }
    }
    return seguras;
};

void Animal::posicionaAnimal()
{
    vector<Animal::Posicao> posicoes = scanPosicoesSeguras();

    if (posicoes.empty())
    {
        cout << "Não há posições seguras para posicional o animal\n";
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, posicoes.size() - 1);

    posicaoAnimal = posicoes[dist(gen)];
    floresta.getMapa()[posicaoAnimal.x][posicaoAnimal.y] = 7;
}