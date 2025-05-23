# Burn Simulation 🔥

<div align="center"> 
    <img src="./img/animacao.gif" width="200" height="200"> 
</div> 


### ☕ Introdução

Este projeto foi desenvolvido para a disciplina de Algoritmos e Estruturas de Dados I, ministrada pelo professor Michel Pires Silva, no Centro Federal de Educação Tecnológica de Minas Gerais (CEFET-MG) — Campus V - Divinópolis.

O objetivo do trabalho é simular a propagação de um incêndio em uma floresta modelada como uma matriz N x M (mínimo de 100x100), além de implementar uma lógica de movimentação aleatória para um animal que tenta escapar do fogo.

### 🎯 Objetivos

- Simular, de forma visual ou em arquivo, a propagação de incêndios numa floresta representada por uma matriz.

- Implementar regras realistas de propagação, considerando influência de vento.

- Modelar o comportamento de um animal que tenta fugir do fogo.

- Registrar estatísticas relevantes: caminho percorrido, passos dados e situação final do animal.

- Utilizar conceitos de estruturas de dados e algoritmos eficientes estudados em POO como Busca em Largura (BFS) e filas.

### 🔥 Regras do Incêndio:

- Uma árvore saudável 🌳 (1) pega fogo se possuir vizinho em chamas 🔥 (2).

- Uma árvore em chamas 🔥 (2) se torna queimada ⬛ (3) no ciclo seguinte.

- O fogo se propaga ortogonalmente 

- A simulação termina quando o fogo apaga ou o número máximo de iterações é atingido.

- As direções do vento e o número máximo de iterações são definidos no arquivo [Config.hpp](src/Config.hpp).


### 🐇 Regras do Animal:

- Se movimenta ortogonalmente e de forma aleatória respeitando os campos prioritários: 

    - Prioriza movimentação para Água 🌊 (4).
    - Caso intermediário espaço vazio ⬜ (0) ou área com vegetação 🌳 (1) 
    - Evita áreas queimadas ⬛ (3).

- O animal não pode se movimentar para uma posição que ja visitou anteriormente

- Quando encontra água 🌊 (4), restaura o ambiente das posições ortogonais, as transformando em 🌳 (1) e alterando a água 🌊 (4) para ⬜ (0).

- Movimenta-se antes da propagação do fogo, e se caso o fogo o alcance logo após sua movimentação, tem a chance de fazer um outro movimento.


### 🖥️ Ambiente de Implementação

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![g++](https://img.shields.io/badge/g++-13.3.0-blue.svg)
![Ubuntu](https://img.shields.io/badge/Ubuntu-24.04-orange?logo=ubuntu)
![WSL](https://img.shields.io/badge/WSL-2-brightgreen?logo=windows)
![VSCode](https://img.shields.io/badge/VSCode-1.99.3-blue?logo=visualstudiocode)


### 📂 Organização dos Arquivos
```
.
├── Makefile
├── README.md
├── build
│   ├── app
│   └── objects
├── casos_teste
├── img
├── input
│   └── input.dat
├── output
│   └── output.dat
└── src
    ├── Animal.cpp
    ├── Animal.hpp
    ├── Config.hpp
    ├── Incendio.cpp
    ├── Incendio.hpp
    ├── Matriz.cpp
    ├── Matriz.hpp
    ├── Simulacao.cpp
    ├── Simulacao.hpp
    └── main.cpp
```
### 💡 Metodologia

<b>Funções Principais:</b>

```cpp
int Incendio::Propagar();
```
- [Propagar()](src/Incendio.cpp): linha 61 a 101
- Simula a propagação do fogo utilizando o conceito de BFS, explorando em largura.
- Essa função trabalha em conjunto com:
    - ```void Queimar();```
        - Faz com que os antigos focos de incendio 🔥 (2) sejam alterados para queimados ⬛ (3) após um ciclo do programa
    - ```int Incendio::verificaPropagacao(int x, int y)```
        - Retornos:
            - (0) = Não houve propagação.
            - (1) = Houve propagação.
            - (2) = Houve propagação e atingiu o animal.
    - ```void Incendio::configuraVento(vector<Posicao> &direcoes)```
        - Recebe um vetor de direções e o edita conforme as direções do vento configuradas no arquivo [Config.hpp](src/Config.hpp) 

```cpp
void Animal::movimentaAnimal(ostream &arquivo)
```
- [movimentaAnimal()](src/Animal.cpp): linha 54 a 118
- Função responsável pela movimentação do animal
- Aleatoriza a escolha do animal entre permanecer parado no ⬜ (0) em até no máximo 2 vezes
- Recebe uma saida como parâmetro
- Essa função trabalha em conjunto com:
    - ```void Animal::dispersaUmidade()``` 
        - Responsável pela dispersão da umidade caso o animal se movimente para uma posição 🌊 (4)
    - ```Animal::Posicao Animal::escolherMelhorPosicao(const vector<Posicao> &posicoes)```
        - Escolhe a melhor posição para o animal de movimentar respeitando a ordem de prioridade
        - Recebe um vetor de posições que representa a 'visão' do animal naquele momento
        - Retorna a posição para qual o animal deve se mover
    - ```bool Animal::estaCercadoPorFogo()```
        - Retorna <b>true</b> caso esteja cercado totalmente por fogo
    - ```bool Animal::dentroDosLimites(int x, int y)```
        - Recebe dois inteiros que representam uma cordenada e retorna se essa cordenada está dentro dos limites da matriz

```cpp
void Simulacao::Simular()
```
- [Simular()](src/Simulacao.cpp): linha 15 a 101
- Função que gerencia as iterações entre movimentação do animal e propagação do fogo
- Responsável pelas regras de implementação, como:
    - Sistama de turno: animal se movimenta depois o fogo propaga
    - Segunda vida do animal
    - Identifica quando o animal morre
    - Limita a quantidade de iterações
    - Devolve o relatório final que é gravado no arquivo [output.dat](output/output.dat), sendo exibido cada iteração separadamente com descrições do que aconteceu naquele ciclo e ao final informações sobre o animal, contendo: 
        - Quantidade de passos do animal
        - Caminho feito pelo animal
        - Estado do animal


```cpp
void Simulacao::SimularTerminal()
```
- [Simular()](src/Simulacao.cpp): linha 103 a 171
- Função semelhante a ```Simular()``` porém tem como saída o próprio terminal, gerando uma animação da simulação

- A escolha entre simular no terminal ou gravar em arquivo é controlada pela variável OUTPUT_TO_FILE, localizada no arquivo [Config.hpp](src/Config.hpp).

- Caso a simulação seja exibida no terminal (OUTPUT_TO_FILE = false), o tempo entre cada frame é definido pela variável TIME_ANIMATION, no mesmo arquivo.

A simulação é realizada a partir das funções descritas anteriormente, organizadas dentro dos métodos ```Simular()``` e ```SimularTerminal()```.
O funcionamento geral do processo pode ser visualizado no fluxograma apresentado a seguir.

<b>Fluxograma:</b>

```mermaid
flowchart TD
    A[Início da Simulação] --> B[Abrir arquivo output.dat]
    B --> C[Imprimir mapa inicial]

    C --> D[Início do loop de iterações]
    D --> E{Animal está vivo?}

    E -- Não --> F[Animal não se move]
    E -- Sim --> G{Animal está cercado por fogo?}

    G -- Sim --> H[Animal morre 💀]
    H --> I[Marca posição do animal como 9]

    G -- Não --> J[Animal se move]
    J --> K[Imprimir mapa atualizado]

    F --> L[Propagação do fogo 🔥]
    I --> L
    K --> L

    L --> M[Imprimir focos atualizados]
    M --> N{Fogo atingiria o animal?}

    N -- Sim --> O[Ativa vida extra ⚡]
    O --> P[Animal tenta fugir novamente]
    P --> Q[Atualiza mapas e ignora resto da iteração]
    Q --> D

    N -- Não --> R{Ainda há fogo?}
    R -- Não --> S[Encerrar simulação 🔚]
    S --> T[Imprimir relatório final]
    T --> U[Fim]

    R -- Sim --> D
```




### 📜 Arquivos Adicionais

[Makefile.hpp](Makefile)

- Tem os seguintes comandos
    - ```make clean``` : remove todos os arquivos de build e saídas geradas pela simulação, deixando o diretório limpo.
    - ```make```: compila o código-fonte e gera o executável da simulação.
    - ```make run```: compila (se necessário) e executa a simulação diretamente.
    - ```make full```: limpa, recompila do zero e executa a simulação, garantindo que a execução utilize a versão mais recente do código.

### 👨🏻‍💻 Compilação e Execução

- Insira os valores de entrada no arquivo [input.dat](input/input.dat) no formato:
```
a b c d e f
x x x x x
x x x x x
x x x x x
x x x x x
x x x x x
```
- Legenda:
    - `a`: Quantidade de linhas da matriz.
    - `b`: Quantidade de colunas da matriz.
    - `c`: Linha da posição inicial do fogo.
    - `d`: Coluna da posição inicial do fogo.
    - `e`: Linha da posição inicial do animal.
    - `f`: Linha da posição inicial do animal.
    - `x`: Valores possíveis de cada célula (0, 1 ou 4).

- Configure o arquivo [Config.hpp](src/Config.hpp), as instruções estão comentadas no próprio arquivo

- Agora no terminal:

```sh
make full
```

### 🧪 Casos de Teste

- [Caso 1 — Animal cercado por fogo e dispersão da umidade](casos_teste/caso1)
- [Caso 2 — Direções do vento](casos_teste/caso2)
- [Caso 3 — Mecanismo de segunda vida](casos_teste/caso3)
- [Caso 4 — Restrição de posições já visitadas pelo animal](casos_teste/caso4)

### 🔚 Conclusão

A simulação desenvolvida demonstrou ser aceitável na modelagem da propagação de incêndios exponencias em uma matriz.

- No Caso 1, foi possível observar que priorizar a movimentação em direção ao campo de água 🌊 (4) nem sempre garante a sobrevivência do animal, pois, nesta situação, essa estratégia acabou colocando-o em perigo.

- No Caso 2, a configuração das direções do vento alterou significativamente o comportamento do fogo, aumentando a chance de sobrevivência do animal. Ao limitar o vento a apenas duas direções e o foco inicial estando no meio da matriz, aproximadamente 25% do mapa foi queimado, preservando cerca de 75% de áreas seguras.

- No Caso 4, a restrição de movimentos para posições já visitadas influenciou diretamente na morte do animal, reduzindo seu tempo de vida. A implementação dessa funcionalidade, onde o animal não pode passar por onde já passou, é uma medida extrema e não reflete a realidade. Essa abordagem, embora válida para simulações simplificadas, limita a complexidade do comportamento animal no contexto da simulação.

De forma geral, o uso de busca em largura (BFS) garantiu uma propagação do fogo consistente e previsível, enquanto a lógica para a movimentação do animal, embora aceitável para uma simulação, ainda precisa ser mais elaborada para refletir comportamentos mais realistas e dinâmicos.

Os resultados indicam que ajustes nos parâmetros, como o número máximo de interações ou a configuração do vento, podem influenciar profundamente os desfechos da simulação, abrindo espaço para futuros aprimoramentos e análises mais detalhadas.

### 🚀 Melhorias Futuras

- Implementar alternância da direção do vento durante a simulação.

- Desenvolver um algoritmo de movimentação inteligente para o animal, priorizando sua sobrevivência ao invés de movimentos aleatórios.

- Adicionar novos fatores externos que influenciem o comportamento da simulação, como:
    - Variação climática.
    - Intensidade e direção dinâmica do vento.
    - Barreiras naturais.

- Otimizar o fluxo da simulação, removendo redundâncias e validações desnecessárias.