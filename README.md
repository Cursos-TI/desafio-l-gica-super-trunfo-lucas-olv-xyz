# Super Trunfo - Cidades Brasileiras 🇧🇷

Este é um pequeno jogo inspirado no Super Trunfo, onde duas cartas de cidades (São Paulo e Rio de Janeiro) são comparadas com base em atributos como população, área, PIB, pontos turísticos e densidade populacional.

---

## 🧠 Sobre o jogo

O jogo já vem com duas cartas cadastradas:

- **Carta 1**: São Paulo
- **Carta 2**: Rio de Janeiro

O usuário escolhe um atributo no menu para comparar entre as duas cidades, e o programa informa qual delas venceu com base no valor do atributo escolhido.

---

## 📦 Compilação

Você pode compilar usando o `gcc`:

```bash
gcc -o supertrunfo supertrunfo.c
```

> Substitua `supertrunfo.c` pelo nome do seu arquivo `.c`, se for diferente.

---

## ▶️ Execução

Após compilar, execute o programa com:

```bash
./supertrunfo
```

No Windows, use:

```cmd
supertrunfo.exe
```

---

## 📋 Atributos disponíveis para comparação

1. População
2. Área (em km²)
3. PIB (em bilhões de reais)
4. Número de pontos turísticos
5. Densidade populacional
6. Regras do jogo
7. Sair

---

## 🛠️ Requisitos

- Compilador C (como `gcc`)
- Terminal compatível com UTF-8 (o programa utiliza `setlocale` para acentuação)

---

## ✍️ Autor

Feito como parte de exercícios de lógica e estruturas condicionais em C.

Objetivo: praticar `if/else`, `switch`, uso de variáveis, cálculos e menus interativos.

---
