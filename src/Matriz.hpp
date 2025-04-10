#include <vector>
#include <string>
#ifndef MATRIZ_HPP
#define MATRIZ_HPP

using namespace std;
class Matriz
{
private:
    vector<vector<int>> mapa;
    int linhas, colunas;
    int linhaInitChama, colunaInitChama;
    int linhaInitAnimal, colunaInitAnimal;

public:
    Matriz();
    void carregarArquivo(const string &caminhoArquivo);
    void imprimirMapa() const;
    vector<vector<int>> &getMapa() { return mapa; }
    int getLinhas() const;
    int getColunas() const;
    int getLinhaInitChama() const;
    int getColunaInitChama() const;
    int getLinhaInitAnimal() const;
    int getColunaInitAnimal() const;
};
#endif