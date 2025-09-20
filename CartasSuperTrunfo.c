#include <stdio.h>

#define TOTAL_CARTAS 4

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char codigo[4];               // Código da carta (ex: A01)
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

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculo da densidade populacional
        if (cartas[i].area > 0) {
            cartas[i].densidadePopulacional = cartas[i].populacao / cartas[i].area;
        } else {
            cartas[i].densidadePopulacional = 0;
        }

        // Cálculo do PIB per capita
        if (cartas[i].populacao > 0) {
            cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
        } else {
            cartas[i].pibPerCapita = 0;
        }
    }

    // Exibição das cartas cadastradas
    printf("\nCartas cadastradas:\n");

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
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

    // Menu interativo para escolha do atributo
    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Lógica de comparação com switch e if-else aninhado
    printf("\nComparação entre %s e %s:\n", cartas[indice1].codigo, cartas[indice2].codigo);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", cartas[indice1].codigo, cartas[indice1].populacao);
            printf("%s: %d habitantes\n", cartas[indice2].codigo, cartas[indice2].populacao);
            if (cartas[indice1].populacao > cartas[indice2].populacao) {
                printf("Vencedora: %s\n", cartas[indice1].codigo);
            } else if (cartas[indice2].populacao > cartas[indice1].populacao) {
                printf("Vencedora: %s\n", cartas[indice2].codigo);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", cartas[indice1].codigo, cartas[indice1].area);
            printf("%s: %.2f km²\n", cartas[indice2].codigo, cartas[indice2].area);
            if (cartas[indice1].area > cartas[indice2].area) {
                printf("Vencedora: %s\n", cartas[indice1].codigo);
            } else if (cartas[indice2].area > cartas[indice1].area) {
                printf("Vencedora: %s\n", cartas[indice2].codigo);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", cartas[indice1].codigo, cartas[indice1].pib);
            printf("%s: %.2f bilhões\n", cartas[indice2].codigo, cartas[indice2].pib);
            if (cartas[indice1].pib > cartas[indice2].pib) {
                printf("Vencedora: %s\n", cartas[indice1].codigo);
            } else if (cartas[indice2].pib > cartas[indice1].pib) {
                printf("Vencedora: %s\n", cartas[indice2].codigo);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d pontos\n", cartas[indice1].codigo, cartas[indice1].pontosTuristicos);
            printf("%s: %d pontos\n", cartas[indice2].codigo, cartas[indice2].pontosTuristicos);
            if (cartas[indice1].pontosTuristicos > cartas[indice2].pontosTuristicos) {
                printf("Vencedora: %s\n", cartas[indice1].codigo);
            } else if (cartas[indice2].pontosTuristicos > cartas[indice1].pontosTuristicos) {
                printf("Vencedora: %s\n", cartas[indice2].codigo);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade populacional\n");
            printf("%s: %.2f hab/km²\n", cartas[indice1].codigo, cartas[indice1].densidadePopulacional);
            printf("%s: %.2f hab/km²\n", cartas[indice2].codigo, cartas[indice2].densidadePopulacional);
            if (cartas[indice1].densidadePopulacional < cartas[indice2].densidadePopulacional) {
                printf("Vencedora: %s\n", cartas[indice1].codigo);
            } else if (cartas[indice2].densidadePopulacional < cartas[indice1].densidadePopulacional) {
                printf("Vencedora: %s\n", cartas[indice2].codigo);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Nenhuma comparação realizada.\n");
            break;
    }

    return 0;