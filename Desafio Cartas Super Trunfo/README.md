# 🏙️ Super Trunfo Cidades — Comparador de Cartas (Linguagem C)

Este programa simula um jogo de **Super Trunfo** entre cidades brasileiras. Desenvolvido em **linguagem C**, permite comparar duas cartas baseadas em atributos numéricos distintos escolhidos pelo jogador, com base em regras específicas para determinar o vencedor.

---

## 📌 Funcionalidades

- Cadastro interativo de **duas cartas** com dados de cidades.
- Cálculo automático de:
  - **Densidade populacional** (`População / Área`)
  - **PIB per capita** (`PIB / População`)
- **Escolha dinâmica** de dois atributos numéricos diferentes via menus.
- Comparação individual de atributos com regra específica:
  - Regra geral: vence o **maior valor**
  - Exceção: **Densidade populacional** (vence o **menor valor**)
- **Soma dos dois atributos** determina a carta vencedora.
- **Empates** são tratados e exibidos claramente.
- Validação de entrada do usuário com tratamento de erros.

---

## 🧮 Atributos disponíveis para comparação

| Número | Atributo                | Regra para vencer         |
|--------|-------------------------|---------------------------|
|   1    | População               | Maior valor               |
|   2    | Área (km²)              | Maior valor               |
|   3    | PIB (R$)                | Maior valor               |
|   4    | Densidade Populacional  | **Menor valor**           |
|   5    | PIB per capita (R$/hab) | Maior valor               |

---

## ⚙️ Compilação e Execução

### ✅ Requisitos

- Compilador C (ex: `gcc` no Linux/Mac/WSL ou `MinGW` no Windows)

### ▶️ Compilar

```bash
gcc supertrunfo_cidades.c -o supertrunfo
```

### ▶️ Executar

No Linux/macOS/WSL:

```bash
./supertrunfo
```

No Windows:

```bash
supertrunfo.exe
```

---

## 💡 Exemplo de uso

```
Cadastro da Carta 1:
Estado: SP
Código da carta: 001
Nome da cidade: São Paulo
População: 12300000
Área: 1521
PIB: 750000000000
Número de pontos turísticos: 100

Cadastro da Carta 2:
Estado: RJ
Código da carta: 002
Nome da cidade: Rio de Janeiro
População: 6700000
Área: 1200
PIB: 400000000000
Número de pontos turísticos: 70

Escolha um atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Densidade Populacional
5 - PIB per capita
Digite o número do primeiro atributo: 5

Escolha um atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Densidade Populacional
Digite o número do segundo atributo (diferente do primeiro): 3

--- Comparação de Cartas ---
Carta 1: São Paulo (SP)
Carta 2: Rio de Janeiro (RJ)

Atributo 1: PIB per capita
Carta 1: 60975.61
Carta 2: 59701.49

Atributo 2: PIB
Carta 1: 750000000000.00
Carta 2: 400000000000.00

Soma dos valores (ajustada pela regra):
Carta 1: 750000060975.61
Carta 2: 400000059701.49

Resultado: Carta 1 (São Paulo) venceu!
```

---

## 📂 Estrutura do Projeto

```
├── supertrunfo_cidades.c   # Código-fonte principal
└── README.md               # Instruções e documentação
```

---

## ✨ Possíveis melhorias

- Cadastro automático com cartas fixas
- Suporte a múltiplas rodadas
- Interface gráfica com bibliotecas C (ex: SDL)
- Sistema de pontuação por rodadas

---

## 📄 Licença

Este projeto é open-source e pode ser utilizado para fins educacionais e pessoais. Sinta-se livre para copiar, modificar e distribuir.

---
