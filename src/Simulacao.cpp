#include "Simulacao.hpp"
#include "Config.hpp"
#include <iostream>

void Simulacao::Simular()
{
    cout << "Mapa Inicial:" << endl;
    floresta.imprimirMapa();
    cout << endl;

    for (int i = 0; i < MAX_ITERACOES; i++)
    {
        if (animal.getEstadoAnimal() != "Morto")
        {
            if (animal.estaCercadoPorFogo())
            {
                cout << "💀 Animal cercado por fogo! Morreu.\n";
                animal.setEstadoAnimal("Morto");
            }
            else
            {
                animal.movimentaAnimal();
                cout << "Movimentação do Animal:" << endl;
                floresta.imprimirMapa();
            }
        }

        cout << "Propagação dos Fogos:" << endl;
        int propagou = incendio.Propagar();

        if (animal.getEstadoAnimal() != "Morto" && propagou == 2) // Fogo iria atingir o animal
        {
            floresta.imprimirMapa();
            cout << "\n⚡ Animal em perigo, tentando fugir!\n";

            auto &mapa = floresta.getMapa();
            auto pos = animal.getPosicaoDoAnimal();
            animal.setTipoCampoAnterior(2);

            incendio.getFogos().push(Incendio::Posicao{pos.x, pos.y});
            mapa[pos.x][pos.y] = 2;

            animal.setEsperaRestante(0);
            animal.movimentaAnimal();    // Tenta fugir
            animal.setEsperaRestante(2); // Restaura tempo de espera

            floresta.imprimirMapa();
            incendio.getFogosAtt().push(Incendio::Posicao{pos.x, pos.y});
            continue;
        }
        else if (!propagou)
        {
            cout << "\n🔥 Fogo extinto. Encerrando simulação.\n";
            cout << "🦌 Passos do animal: " << animal.getPassos() << endl;
            cout << "Estado do animal: " << animal.getEstadoAnimal() << endl;
            break;
        }

        floresta.imprimirMapa();
        cout << endl;
    }
}
