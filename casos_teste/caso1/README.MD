### Caso 1 — Animal cercado por fogo e dispersão da umidade

<b>Configurações usadas</b>

```cpp
inline constexpr int MAX_ITERACOES = 100;
inline constexpr bool OUTPUT_TO_FILE = true;
inline constexpr bool VENTO_ESQUERDA = false;
inline constexpr bool VENTO_DIREITA = false;
inline constexpr bool VENTO_BAIXO   = false;
inline constexpr bool VENTO_CIMA    = false;
```

- Na iteração 13 o animal se movimenta para um campo com água 🌊 (4) dispersando a umidade ortogonalmente

- Ainda na iteração 13 depois da movimentação do animal é realizado uma propagação que cerca o animal com chamas 🔥 (2);

- Na iteração 14 é informado a morte do animal e a propagação continua.

```
=== Iteração 13 ===

Movimentação do Animal:
Posição do Animal: (8, 17)
🌳🔥⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳
🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛🔥🌳🌳🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊🌳🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳
⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛🌳🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌳🐇🌳🌳
🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳
🌳🔥⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳
🌳🌳🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌊🌳🌳🌳
🌳🌳🌳🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌊⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🔥⬛⬛⬛🔥⬛🌊🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🔥⬛🔥🌳🔥🌳🌳🌳🌊🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🔥🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳⬜🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳

Propagação dos Fogos:
🔥⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛🔥🌳🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥
⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛🔥⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🐇🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳
🔥⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳
🌳🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌊🌳🌳🌳
🌳🌳🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳🌳
🌳🌳🌳🔥🌊⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🔥⬛⬛⬛⬛⬛⬛🌊🔥🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🔥⬛⬛⬛🔥⬛🔥🌳🌳🌊🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🔥⬛🔥🌳🔥🌳🌳🌳🌳🌳🌳🌳⬜🌳
🌳🌳🌳🌳🌳🌳🌳🔥🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳


=== Iteração 14 ===
💀 Animal cercado por fogo! Morreu.

Propagação dos Fogos:
⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛💀⬛🔥
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳
⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳
🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🌊🌳🌳🌳
🌳🔥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳
🌳🌳🔥⬛🌊⬛⬛⬛⬛⬛⬛⬛⬛⬛🔥🌳🌳🌳🌳🌳
🌳🌳🌳🔥⬛⬛⬛⬛⬛⬛⬛🌊⬛🔥🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🔥⬛⬛⬛⬛⬛⬛⬛🔥🌳🌊🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🔥⬛⬛⬛🔥⬛🔥🌳🌳🌳🌳🌳🌳⬜🌳
🌳🌳🌳🌳🌳🌳🔥⬛🔥🌳🔥🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🔥🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳

```
