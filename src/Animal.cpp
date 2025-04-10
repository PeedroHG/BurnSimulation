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

    unsigned int aux = visaoAnimal.size();
    unsigned int aux2 = 0;

    for (const auto& pos : visaoAnimal) {
        std::cout << "Visao Animal - x: " << pos.x << ", y: " << pos.y << std::endl;
    }

    for (Posicao d : visaoAnimal)
    {
        cout << d.x << " " << d.y << endl;

        if (mapa[d.x][d.y] == 4)
        {
            next = d;
            break;
        }
        else if (mapa[d.x][d.y] == 0 || mapa[d.x][d.y] == 1)
        {
            next = d;
            break;
        }
        else if (mapa[d.x][d.y] == 3)
        {
            next = d;
            break;
        }
        else
        {
            aux2++;
            continue;
        }
    }

    if(aux2 == aux) {
        cout << "Animal morto" << endl;
    }

    tipoCampoAtual = mapa[next.x][next.y];
    mapa[next.x][next.y] = 7;
    mapa[posicaoAnimal.x][posicaoAnimal.y] = tipoCampoAtual;
    posicaoAnimal = next;
}