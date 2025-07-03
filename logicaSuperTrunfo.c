#include <stdio.h>

int main() 

{
   #include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

float calcularPibPerCapita(float pib, int populacao) {
    return pib / populacao;
}

void imprimirCarta(struct Carta carta) {
    printf("\nEstado: %s", carta.estado);
    printf("\nCódigo: %s", carta.codigo);
    printf("\nCidade: %s", carta.cidade);
    printf("\nPopulação: %d", carta.populacao);
    printf("\nÁrea: %.2f km²", carta.area);
    printf("\nPIB: R$ %.2f bilhões", carta.pib);
    printf("\nPontos Turísticos: %d", carta.pontosTuristicos);
    printf("\nDensidade Populacional: %.2f hab/km²", carta.densidadePopulacional);
    printf("\nPIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    strcpy(carta1.estado, "São Paulo");
    strcpy(carta1.codigo, "SP01");
    strcpy(carta1.cidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 700.0;
    carta1.pontosTuristicos = 15;

    strcpy(carta2.estado, "Rio de Janeiro");
    strcpy(carta2.codigo, "RJ02");
    strcpy(carta2.cidade, "Rio de Janeiro");
    carta2.populacao = 6700000;
    carta2.area = 1182.30;
    carta2.pib = 410.0;
    carta2.pontosTuristicos = 20;

    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);

    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib * 1e9, carta1.populacao);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.pib * 1e9, carta2.populacao);

    printf("========== CARTA 1 ==========");
    imprimirCarta(carta1);

    printf("\n========== CARTA 2 ==========");
    imprimirCarta(carta2);

    printf("\n\n--- Comparação de Cartas (Atributo: PIB per capita) ---\n");
    printf("Carta 1 - %s: R$ %.2f\n", carta1.cidade, carta1.pibPerCapita);
    printf("Carta 2 - %s: R$ %.2f\n", carta2.cidade, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}