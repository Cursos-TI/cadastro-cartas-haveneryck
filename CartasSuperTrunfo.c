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

    // Cálculo do super poder de duas cartas escolhidas
    int indice1, indice2;
    printf("\nEscolha duas cartas para comparar (0 a %d):\n", TOTAL_CARTAS - 1);
    printf("Índice da primeira carta: ");
    scanf("%d", &indice1);
    printf("Índice da segunda carta: ");
    scanf("%d", &indice2);

    float superPoder1 = cartas[indice1].populacao +
                        cartas[indice1].area +
                        cartas[indice1].pib +
                        cartas[indice1].pontosTuristicos +
                        cartas[indice1].pibPerCapita;

    float superPoder2 = cartas[indice2].populacao +
                        cartas[indice2].area +
                        cartas[indice2].pib +
                        cartas[indice2].pontosTuristicos +
                        cartas[indice2].pibPerCapita;

    // Comparação entre os atributos das duas cartas
    printf("\nComparação entre %s e %s:\n", cartas[indice1].codigo, cartas[indice2].codigo);

    printf("População: %s\n", cartas[indice1].populacao > cartas[indice2].populacao ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Área: %s\n", cartas[indice1].area > cartas[indice2].area ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("PIB: %s\n", cartas[indice1].pib > cartas[indice2].pib ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Pontos turísticos: %s\n", cartas[indice1].pontosTuristicos > cartas[indice2].pontosTuristicos ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("PIB per Capita: %s\n", cartas[indice1].pibPerCapita > cartas[indice2].pibPerCapita ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Densidade Populacional (vence o menor): %s\n", cartas[indice1].densidadePopulacional < cartas[indice2].densidadePopulacional ? cartas[indice1].codigo : cartas[indice2].codigo);

    // Exibição do super poder total
    printf("\nSuper Poder de %s: %.2f\n", cartas[indice1].codigo, superPoder1);
    printf("Super Poder de %s: %.2f\n", cartas[indice2].codigo, superPoder2);

    // Determinação da carta vencedora geral
    if (superPoder1 > superPoder2) {
        printf("Carta vencedora geral: %s\n", cartas[indice1].codigo);
    } else if (superPoder2 > superPoder1) {
        printf("Carta vencedora geral: %s\n", cartas[indice2].codigo);
    } else {
        printf("Empate geral entre as cartas!\n");
    }

    return 0;
}