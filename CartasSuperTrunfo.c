#include <stdio.h>

#define TOTAL_CARTAS 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    Carta cartas[TOTAL_CARTAS];

    printf("Cadastro das cartas do Super Trunfo - Países\n");

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

        if (cartas[i].area > 0) {
            cartas[i].densidadePopulacional = cartas[i].populacao / cartas[i].area;
        } else {
            cartas[i].densidadePopulacional = 0;
        }

        if (cartas[i].populacao > 0) {
            cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
        } else {
            cartas[i].pibPerCapita = 0;
        }
    }

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

    printf("\nComparação entre %s e %s:\n", cartas[indice1].codigo, cartas[indice2].codigo);

    printf("População: %s\n", cartas[indice1].populacao > cartas[indice2].populacao ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Área: %s\n", cartas[indice1].area > cartas[indice2].area ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("PIB: %s\n", cartas[indice1].pib > cartas[indice2].pib ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Pontos turísticos: %s\n", cartas[indice1].pontosTuristicos > cartas[indice2].pontosTuristicos ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("PIB per Capita: %s\n", cartas[indice1].pibPerCapita > cartas[indice2].pibPerCapita ? cartas[indice1].codigo : cartas[indice2].codigo);
    printf("Densidade Populacional (vence o menor): %s\n", cartas[indice1].densidadePopulacional < cartas[indice2].densidadePopulacional ? cartas[indice1].codigo : cartas[indice2].codigo);

    return 0;
}