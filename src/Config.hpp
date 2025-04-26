#ifndef CONFIG_HPP
#define CONFIG_HPP

// Número máximo de iterações da simulação
inline constexpr int MAX_ITERACOES = 100;

// Direções do vento, use false em todas para desligar o vento
inline constexpr bool VENTO_ESQUERDA = false;
inline constexpr bool VENTO_DIREITA = false;
inline constexpr bool VENTO_BAIXO   = false;
inline constexpr bool VENTO_CIMA    = false;

// False -> Terminal
// True  -> Arquivo
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

// Use se o seu terminal não renderizar emojis
/* 
    #define EMPTY_SYMBOL "0"
    #define TREE_SYMBOL "1"
    #define BURNING_SYMBOL "2"
    #define BURNT_SYMBOL "3"
    #define WATER_SYMBOL "4"
    #define ANIMAL_SYMBOL "A"
    #define DEAD_ANIMAL_SYMBOL "D"
*/

#endif 