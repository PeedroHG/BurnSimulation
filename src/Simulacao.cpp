#include "Simulacao.hpp"
#include "Config.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

Simulacao::Simulacao(Matriz &matriz, Incendio &incendio, Animal &animal) : floresta(matriz), incendio(incendio), animal(animal) {}

void Simulacao::limpaTerminal()
{
    system("clear");
}

void Simulacao::Simular()
{
    auto &mapa = floresta.getMapa();

    ofstream arquivo("./output/output.dat");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo output.dat\n";
        return;
    }

    arquivo << "=== Mapa inicial: ===\n";
    floresta.imprimirMapaArquivo(arquivo);
    arquivo << "\n";

    for (int i = 0; i < MAX_ITERACOES; i++)
    {
        arquivo << "\n=== Iteração " << i + 1 << " ===\n";

        if (animal.getEstadoAnimal() != "Morto")
        {
            if (animal.estaCercadoPorFogo())
            {
                arquivo << "💀 Animal cercado por fogo! Morreu.\n";
                animal.setEstadoAnimal("Morto");
                mapa[animal.getPosicaoDoAnimal().x][animal.getPosicaoDoAnimal().y] = 9;
            }
            else
            {
                animal.movimentaAnimal(arquivo);
                arquivo << "\nMovimentação do Animal:\n";
                arquivo << "Posição do Animal: (" << animal.getPosicaoDoAnimal().x << ", " << animal.getPosicaoDoAnimal().y << ")\n";
                floresta.imprimirMapaArquivo(arquivo);
            }
        }

        arquivo << "\nPropagação dos Fogos:\n";
        int propagou = incendio.Propagar();

        queue<Incendio::Posicao> fogosAtt = incendio.getCopiaFogosAtt();
        while (!fogosAtt.empty())
        {
            Incendio::Posicao fogo = fogosAtt.front();
            fogosAtt.pop();
            arquivo << "(" << fogo.x << ", " << fogo.y << ") vira 2\n";
        }

        if (animal.getEstadoAnimal() != "Morto" && propagou == 2) // Fogo iria atingir o animal
        {
            floresta.imprimirMapaArquivo(arquivo);
            arquivo << "\n⚡ Animal em perigo, ativando vida extra!\n";

            auto pos = animal.getPosicaoDoAnimal();
            animal.setTipoCampoAnterior(2);

            incendio.getFogos().push(Incendio::Posicao{pos.x, pos.y});
            mapa[pos.x][pos.y] = 2;

            animal.setEsperaRestante(0);
            animal.movimentaAnimal(arquivo); // Tenta fugir
            animal.setEsperaRestante(2);     // Restaura tempo de espera

            floresta.imprimirMapaArquivo(arquivo);
            incendio.getFogosAtt().push(Incendio::Posicao{pos.x, pos.y});
            continue;
        }
        else if (!propagou)
        {
            floresta.imprimirMapaArquivo(arquivo);
            arquivo << "\n🔥 Fogo extinto. Encerrando simulação.\n";
            arquivo << "🦌 Passos do animal: " << animal.getPassos() << "\n";
            arquivo << "Caminho do animal: \n";
            for (auto &pos : animal.getCaminhoAnimal())
            {
                arquivo << "(" << pos.x << ", " << pos.y << ") ";
            }
            arquivo << "\n";
            arquivo << "Estado do animal: " << animal.getEstadoAnimal() << "\n";
            break;
        }

        floresta.imprimirMapaArquivo(arquivo);
        arquivo << "\n";
    }

    arquivo.close();
}

void Simulacao::SimularTerminal()
{
    auto &mapa = floresta.getMapa();

    limpaTerminal();
    floresta.imprimirMapaTerminal();
    cout << "\n";
    this_thread::sleep_for(chrono::milliseconds(TIME_ANIMATION)); // Tempo para visualizar o estado inicial

    for (int i = 0; i < MAX_ITERACOES; i++)
    {
        limpaTerminal();

        if (animal.getEstadoAnimal() != "Morto")
        {
            if (animal.estaCercadoPorFogo())
            {
                cout << "💀 Animal cercado por fogo! Morreu.\n";
                animal.setEstadoAnimal("Morto");
                mapa[animal.getPosicaoDoAnimal().x][animal.getPosicaoDoAnimal().y] = 9;
            }
            else
            {
                animal.movimentaAnimal(cout);
            }
        }

        int propagou = incendio.Propagar();

        if (animal.getEstadoAnimal() != "Morto" && propagou == 2)
        {
            floresta.imprimirMapaTerminal();
            cout << "\nAnimal foi queimado, ativando vida extra!\n";

            auto pos = animal.getPosicaoDoAnimal();
            animal.setTipoCampoAnterior(2);
            incendio.getFogos().push(Incendio::Posicao{pos.x, pos.y});
            mapa[pos.x][pos.y] = 2;

            animal.setEsperaRestante(0);
            animal.movimentaAnimal(cout);
            animal.setEsperaRestante(2);

            floresta.imprimirMapaTerminal();
            cout << "\n";
            incendio.getFogosAtt().push(Incendio::Posicao{pos.x, pos.y});
            this_thread::sleep_for(chrono::milliseconds(TIME_ANIMATION));
            continue;
        }
        else if (!propagou)
        {
            floresta.imprimirMapaTerminal();
            cout << "\n🔥 Fogo extinto. Encerrando simulação.\n";
            cout << "🦌 Passos do animal: " << animal.getPassos() << "\n";
            cout << "❤️‍🩹 Estado do animal: " << animal.getEstadoAnimal() << "\n";
            cout << "🚶🏼 Caminho do animal: \n";
            for (auto &pos : animal.getCaminhoAnimal())
            {
                cout << "(" << pos.x << ", " << pos.y << ") ";
            }
            break;
        }

        floresta.imprimirMapaTerminal();
        cout << "\n";

        this_thread::sleep_for(chrono::milliseconds(TIME_ANIMATION)); // Delay entre os frames
    }
}