#include "Matriz.hpp"
#include "Config.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Matriz::Matriz()
{
    linhas = 0;
    colunas = 0;
    linhaInitChama = 0;
    colunaInitChama = 0;
    mapa.resize(linhas, vector<int>(colunas, 0));
}

void Matriz::carregarArquivo(const string &caminhoArquivo)
{
    ifstream arquivo(caminhoArquivo);
    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << endl;
        return;
    }

    arquivo >> this->linhas >> this->colunas >> this->linhaInitChama >> this->colunaInitChama >> this->linhaInitAnimal >> this->colunaInitAnimal;
    mapa.assign(this->linhas, vector<int>(this->colunas));

    mapa[this->linhaInitChama][this->colunaInitChama] = 2;
    for (auto &linha : mapa)
    {
        for (auto &celula : linha)
        {
            arquivo >> celula;
        }
    }

    if (mapa[this->linhaInitAnimal][this->colunaInitAnimal] != 0 && mapa[this->linhaInitAnimal][this->colunaInitAnimal] != 1)
    {
        cerr << "Erro: A posicao inicial do animal nao esta sobre um campo (0) ou (1)." << endl;
        exit(1);
    }
}

void Matriz::imprimirMapaTerminal()
{
    for (auto &linha : mapa)
    {
        for (auto &valor : linha)
        {
            if (valor == 0)
            {
                cout << EMPTY_SYMBOL;
            }
            else if (valor == 1)
            {
                cout << TREE_SYMBOL;
            }
            else if (valor == 2)
            {
                cout << BURNING_SYMBOL;
            }
            else if (valor == 3)
            {
                cout << BURNT_SYMBOL;
            }
            else if (valor == 4)
            {
                cout << WATER_SYMBOL;
            }
            else if (valor == 7)
            {
                cout << ANIMAL_SYMBOL;
            }
            else if (valor == 9)
            {
                cout << DEAD_ANIMAL_SYMBOL;
            }
        }
        cout << "\n";
    }
}

void Matriz::imprimirMapaArquivo(ofstream &arquivo)
{
    for (auto &linha : mapa)
    {
        for (auto &valor : linha)
        {
            if (valor == 0)
            {
                arquivo << EMPTY_SYMBOL;
            }
            else if (valor == 1)
            {
                arquivo << TREE_SYMBOL;
            }
            else if (valor == 2)
            {
                arquivo << BURNING_SYMBOL;
            }
            else if (valor == 3)
            {
                arquivo << BURNT_SYMBOL;
            }
            else if (valor == 4)
            {
                arquivo << WATER_SYMBOL;
            }
            else if (valor == 7)
            {
                arquivo << ANIMAL_SYMBOL;
            }
            else if (valor == 9)
            {
                arquivo << DEAD_ANIMAL_SYMBOL;
            }
        }
        arquivo << "\n";
    }
}
int Matriz::getLinhas() const { return linhas; }

int Matriz::getColunas() const { return colunas; }

int Matriz::getLinhaInitChama() const { return linhaInitChama; }

int Matriz::getColunaInitChama() const { return colunaInitChama; }

int Matriz::getLinhaInitAnimal() const { return linhaInitAnimal; }

int Matriz::getColunaInitAnimal() const { return colunaInitAnimal; }