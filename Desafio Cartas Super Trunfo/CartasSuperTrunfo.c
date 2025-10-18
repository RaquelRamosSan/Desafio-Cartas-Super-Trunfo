#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[50];
    char codigo[20];
    char cidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Enum para os atributos disponíveis
enum Atributos {
    POPULACAO = 1,
    AREA,
    PIB,
    DENSIDADE,
    PIB_PER_CAPITA
};

// Função para cadastrar uma carta (sem mudanças)
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);

    printf("População: ");
    scanf("%d", &carta->populacao);
    getchar();

    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    getchar();

    printf("PIB (em R$): ");
    scanf("%f", &carta->pib);
    getchar();

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    getchar();

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir menu de atributos
void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir != POPULACAO)       printf("1 - População\n");
    if (excluir != AREA)            printf("2 - Área\n");
    if (excluir != PIB)             printf("3 - PIB\n");
    if (excluir != DENSIDADE)       printf("4 - Densidade Populacional\n");
    if (excluir != PIB_PER_CAPITA)  printf("5 - PIB per capita\n");
}

// Função para obter valor do atributo de uma carta
float obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case POPULACAO: return c.populacao;
        case AREA: return c.area;
        case PIB: return c.pib;
        case DENSIDADE: return c.densidadePopulacional;
        case PIB_PER_CAPITA: return c.pibPerCapita;
        default: return 0.0;
    }
}

// Função para imprimir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case POPULACAO: return "População";
        case AREA: return "Área";
        case PIB: return "PIB";
        case DENSIDADE: return "Densidade Populacional";
        case PIB_PER_CAPITA: return "PIB per capita";
        default: return "Desconhecido";
    }
}

// Função para comparar as cartas com base em dois atributos
void compararCartas(struct Carta c1, struct Carta c2, int atributo1, int atributo2) {
    float valor1_c1 = obterValorAtributo(c1, atributo1);
    float valor1_c2 = obterValorAtributo(c2, atributo1);

    float valor2_c1 = obterValorAtributo(c1, atributo2);
    float valor2_c2 = obterValorAtributo(c2, atributo2);

    printf("\n--- Comparação de Cartas ---\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.cidade, c2.estado);

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("Carta 1: %.2f\n", valor1_c1);
    printf("Carta 2: %.2f\n", valor1_c2);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("Carta 1: %.2f\n", valor2_c1);
    printf("Carta 2: %.2f\n", valor2_c2);

    // Aplicar regra de menor para Densidade, maior para os outros
    float comparado1_c1 = (atributo1 == DENSIDADE) ? -valor1_c1 : valor1_c1;
    float comparado1_c2 = (atributo1 == DENSIDADE) ? -valor1_c2 : valor1_c2;

    float comparado2_c1 = (atributo2 == DENSIDADE) ? -valor2_c1 : valor2_c1;
    float comparado2_c2 = (atributo2 == DENSIDADE) ? -valor2_c2 : valor2_c2;

    float soma_c1 = comparado1_c1 + comparado2_c1;
    float soma_c2 = comparado1_c2 + comparado2_c2;

    printf("\nSoma dos valores (ajustada pela regra):\n");
    printf("Carta 1: %.2f\n", soma_c1);
    printf("Carta 2: %.2f\n", soma_c2);

    printf("\nResultado: ");
    if (soma_c1 > soma_c2) {
        printf("Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (soma_c2 > soma_c1) {
        printf("Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    int atributo1 = 0, atributo2 = 0;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Escolha do primeiro atributo
    while (atributo1 < 1 || atributo1 > 5) {
        mostrarMenu(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);

        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida. Tente novamente.\n");
    }

    // Escolha do segundo atributo (diferente do primeiro)
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        mostrarMenu(atributo1);
        printf("Digite o número do segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);

        if (atributo2 == atributo1)
            printf("Você já escolheu esse atributo. Tente outro.\n");
        else if (atributo2 < 1 || atributo2 > 5)
            printf("Opção inválida. Tente novamente.\n");
    }

    // Comparar cartas
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
