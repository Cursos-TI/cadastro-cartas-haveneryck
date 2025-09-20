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

    // Loop para cadastrar os dados de cada carta
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

    // Exibição dos dados das cartas cadastradas
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

    // Comparação por atributo fixo: População
    printf("\nComparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s: %d habitantes\n", cartas[indice1].codigo, cartas[indice1].populacao);
    printf("Carta 2 - %s: %d habitantes\n", cartas[indice2].codigo, cartas[indice2].populacao);

    // Lógica de decisão usando if e if-else
    if (cartas[indice1].populacao > cartas[indice2].populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", cartas[indice1].codigo);
    } else if (cartas[indice2].populacao > cartas[indice1].populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", cartas[indice2].codigo);
    } else {
        printf("\nResultado: Empate entre as cartas!\n");
    }

    return 0;
}