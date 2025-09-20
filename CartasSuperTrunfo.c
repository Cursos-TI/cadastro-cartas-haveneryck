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
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadePopulacional;// População / Área
    float pibPerCapita;         // PIB / População
} Carta;

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
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos turísticos\n"); break;
                case 5: printf("5 - Densidade populacional\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nErro: Atributo inválido ou repetido. Encerrando comparação.\n");
        return 1;
    }

    // A lógica de comparação e soma será implementada no próximo commit

    return 0;
}