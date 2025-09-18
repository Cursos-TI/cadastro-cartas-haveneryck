#include <stdio.h>

#define TOTAL_CARTAS 32

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
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
    }

    return 0;
}