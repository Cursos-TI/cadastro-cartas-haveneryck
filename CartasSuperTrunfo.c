#include <stdio.h>
#include <string.h>

#define TOTAL_CARTAS 4

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char codigo[4];               // Código da carta (ex: A01)
    char nome[30];                // Nome do país
    int populacao;               // População total
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita;          // PIB / População
} Carta;

// Função auxiliar para obter o valor do atributo
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        default: return 0;
    }
}

// Função auxiliar para obter o nome do atributo
char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade populacional";
        default: return "Desconhecido";
    }
}

int main() {
    Carta cartas[TOTAL_CARTAS];

    printf("Cadastro das cartas do Super Trunfo - Países\n");

    // Cadastro das cartas
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCarta %d\n", i + 1);
        printf("Código (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome do país: ");
        scanf(" %[^\n]", cartas[i].nome); // Lê nome com espaços

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculo da densidade populacional
        cartas[i].densidadePopulacional = (cartas[i].area > 0) ? cartas[i].populacao / cartas[i].area : 0;

        // Cálculo do PIB per capita
        cartas[i].pibPerCapita = (cartas[i].populacao > 0) ? cartas[i].pib / cartas[i].populacao : 0;
    }

    // Exibição das cartas cadastradas
    printf("\nCartas cadastradas:\n");

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("Nome: %s\n", cartas[i].nome);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidadePopulacional);
        printf("PIB per Capita: %.6f bilhões/hab\n", cartas[i].pibPerCapita);
    }

    // Escolha de duas cartas para comparação
    int indice1, indice2;
    printf("\nEscolha duas cartas para comparar (0 a %d):\n", TOTAL_CARTAS - 1);
    printf("Índice da primeira carta: ");
    scanf("%d", &indice1);
    printf("Índice da segunda carta: ");
    scanf("%d", &indice2);

    if (indice1 < 0 || indice1 >= TOTAL_CARTAS || indice2 < 0 || indice2 >= TOTAL_CARTAS) {
        printf("\nErro: Índices inválidos. Encerrando comparação.\n");
        return 1;
    }

    // Menu para escolha do primeiro atributo
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nErro: Atributo inválido. Encerrando comparação.\n");
        return 1;
    }

    // Menu dinâmico para escolha do segundo atributo
    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nErro: Atributo inválido ou repetido. Encerrando comparação.\n");
        return 1;
    }

    // Obter valores dos atributos para cada carta
    float valor1_carta1 = obterValor(cartas[indice1], atributo1);
    float valor1_carta2 = obterValor(cartas[indice2], atributo1);
    float valor2_carta1 = obterValor(cartas[indice1], atributo2);
    float valor2_carta2 = obterValor(cartas[indice2], atributo2);

    // Exibir os valores comparados
    printf("\nComparação dos atributos:\n");

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", cartas[indice1].nome, valor1_carta1);
    printf("%s: %.2f\n", cartas[indice2].nome, valor1_carta2);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", cartas[indice1].nome, valor2_carta1);
    printf("%s: %.2f\n", cartas[indice2].nome, valor2_carta2);

    // Determinar vencedor de cada atributo
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5) {
        // Densidade populacional: menor vence
        (valor1_carta1 < valor1_carta2) ? pontosCarta1++ :
        (valor1_carta2 < valor1_carta1) ? pontosCarta2++ : 0;
    } else {
        // Maior valor vence
        (valor1_carta1 > valor1_carta2) ? pontosCarta1++ :
        (valor1_carta2 > valor1_carta1) ? pontosCarta2++ : 0;
    }

    // Comparação do segundo atributo
    if (atributo2 == 5) {
        (valor2_carta1 < valor2_carta2) ? pontosCarta1++ :
        (valor2_carta2 < valor2_carta1) ? pontosCarta2++ : 0;
    } else {
        (valor2_carta1 > valor2_carta2) ? pontosCarta1++ :
        (valor2_carta2 > valor2_carta1) ? pontosCarta2++ : 0;
    }

    // A lógica de soma e decisão final será implementada no próximo commit

    return 0;
}