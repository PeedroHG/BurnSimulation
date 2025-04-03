#include "Matriz.hpp"
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

void Matriz::carregarArquivo(const string &caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << endl;
        return;
    }

    arquivo >> this->linhas >> this->colunas >> this->linhaInitChama >> this->colunaInitChama;
    mapa.assign(this->linhas, vector<int>(this->colunas));

    for (auto &linha : mapa) {
        for (auto &celula : linha) {
            arquivo >> celula;
        }
    }
}


void Matriz::imprimirMapa() const
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

int Matriz::getLinhas() const { return linhas; }

int Matriz::getColunas() const { return colunas; }

int Matriz::getLinhaInitChama() const { return linhaInitChama; }

int Matriz::getColunaInitChama() const { return colunaInitChama; }
