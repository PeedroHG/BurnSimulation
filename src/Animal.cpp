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
    auto &mapa = floresta.getMapa();

    if (posicoes.empty())
    {
        cout << "Não há posições seguras para posicional o animal\n";
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, posicoes.size() - 1);

    this->posicaoAnimal = posicoes[dist(gen)];

    this->tipoCampoAtual = mapa[posicaoAnimal.x][posicaoAnimal.y];
    mapa[posicaoAnimal.x][posicaoAnimal.y] = 7;
}


void Animal::movimentaAnimal()
{
    auto &mapa = floresta.getMapa();
    visitados[posicaoAnimal.x][posicaoAnimal.y] = true;

    // cout << endl;
    // for (int i = 0; i < floresta.getLinhas(); i++)
    // {
    //     for (int j = 0; j < floresta.getColunas(); j++)
    //     {
    //         cout << visitados[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<Posicao> direcoes = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<Posicao> visaoAnimal;

    for (Posicao d : direcoes)
    {
        int nx = posicaoAnimal.x + d.x;
        int ny = posicaoAnimal.y + d.y;
        if(nx < 0 || nx >= floresta.getLinhas() || ny < 0 || ny >= floresta.getColunas() || visitados[nx][ny] == true){
            continue;
        } else {
            visaoAnimal.push_back({nx, ny});
        };
    }

    Posicao next = {-1, -1};

    for (Posicao d : visaoAnimal)
    {
        if (mapa[d.x][d.y] == 4)
        {
            next = d;
            break;
        }
        else if (mapa[d.x][d.y] == 0 || mapa[d.x][d.y] == 1)
        {
            next = d;    
            break;
        } else if (mapa[d.x][d.y] == 3)
        {
            next = d;
            break;
        } else {
            cout << "Animal sem movimento\n";
        }
    }

    //cout << "Animal movendo para: " << next.x << " " << next.y << endl;
    tipoCampoAtual = mapa[next.x][next.y];
    mapa[next.x][next.y] = 7;
    //cout << "Tipo de campo atual: " << tipoCampoAtual << endl;
    mapa[posicaoAnimal.x][posicaoAnimal.y] = tipoCampoAtual;
    posicaoAnimal = next;
}