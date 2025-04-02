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

public:
    Matriz();
    void carregarArquivo(const string &caminhoArquivo);
    int getLinhas() const;
    int getColunas() const;
    int getLinhaInitChama() const;
    int getColunaInitChama() const;
    
};
#endif