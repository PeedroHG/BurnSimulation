#ifndef CONFIG_HPP
#define CONFIG_HPP

// Número máximo de iterações da simulação
inline constexpr int MAX_ITERACOES = 1000;

// Direções do vento, use false em todas para desligar o vento
inline constexpr bool VENTO_ESQUERDA = true;
inline constexpr bool VENTO_DIREITA = true;
inline constexpr bool VENTO_BAIXO   = true;
inline constexpr bool VENTO_CIMA    = false;

#endif 