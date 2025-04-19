#ifndef CONFIG_HPP
#define CONFIG_HPP

// Número máximo de iterações da simulação
inline constexpr int MAX_ITERACOES = 100;

// Direções do vento, use false em todas para desligar o vento
inline constexpr bool VENTO_ESQUERDA = false;
inline constexpr bool VENTO_DIREITA = false;
inline constexpr bool VENTO_BAIXO   = false;
inline constexpr bool VENTO_CIMA    = false;

// False para imprimir a animação do mapa no terminal e true para salvar em um arquivo
inline constexpr bool OUTPUT_TO_FILE = false;

// Tempo de exibição de cada frame em milisegundos
inline constexpr int TIME_ANIMATION = 500;

#define EMPTY_SYMBOL "⬜"
#define TREE_SYMBOL "🌳"
#define BURNING_SYMBOL "🔥"
#define BURNT_SYMBOL "⬛"
#define WATER_SYMBOL "🌊"
#define ANIMAL_SYMBOL "🐇"
#define DEAD_ANIMAL_SYMBOL "💀"
#define VISITED_SYMBOL "❌"

#endif 