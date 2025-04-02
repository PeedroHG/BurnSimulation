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

void Matriz::carregarArquivo(const string &caminhoArquivo)
{
    ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << endl;
        return;
    }

    // Dimensões da matriz e posição inicial
    string linha;

    getline(arquivo, linha);
    istringstream dimensoes(linha);
    dimensoes >> this->linhas >> this->colunas;

    getline(arquivo, linha);
    dimensoes.clear();
    dimensoes.str(linha);
    dimensoes >> this->linhaInitChama >> this->colunaInitChama;

    // Alocação da matriz
    mapa.resize(this->linhas, vector<int>(this->colunas, 0));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            arquivo >> mapa[i][j];
        }
    }

    arquivo.close();
}

int Matriz::getLinhas() const { return linhas; }

int Matriz::getColunas() const { return colunas; }

int Matriz::getLinhaInitChama() const { return linhaInitChama; }

int Matriz::getColunaInitChama() const { return colunaInitChama; }
