#include <stdio.h>
#include <string.h>

// Definição da estrutura
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Protótipos
void lerCarta(struct Carta *carta, int numero);
void exibirCarta(struct Carta carta, int numero);
void calcularSuperPoder(struct Carta *carta);
void compararCartas(struct Carta c1, struct Carta c2);

int main() {
    struct Carta carta1, carta2;

    printf("==== Cadastro de Cartas Super Trunfo ====\n");

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);

    printf("\n==== Exibindo Cartas Cadastradas ====\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("\n==== Comparação de Cartas ====\n");
    compararCartas(carta1, carta2);

    return 0;
}

void lerCarta(struct Carta *carta, int numero) {
    printf("\n=== Inserção da Carta %d ===\n", numero);

    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o Nome da Cidade: ");
    getchar(); // limpa o buffer
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);

    // Remove o \n no final, se houver
    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("Digite a População: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
}

void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void calcularSuperPoder(struct Carta *carta) {
    carta->superPoder = (
        (float)carta->populacao +
        carta->area +
        carta->pib +
        (float)carta->pontosTuristicos +
        carta->pibPerCapita +
        (1.0f / carta->densidadePopulacional)
    );
}

void compararCartas(struct Carta c1, struct Carta c2) {
    printf("População: ");
    if (c1.populacao > c2.populacao)
        printf("Carta 1 venceu\n");
    else if (c1.populacao < c2.populacao)
        printf("Carta 2 venceu\n");
    else
        printf("Empate \n");

    printf("Área: ");
    if (c1.area > c2.area)
        printf("Carta 1 venceu\n");
    else if (c1.area < c2.area)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");

    printf("PIB: ");
    if (c1.pib > c2.pib)
        printf("Carta 1 venceu\n");
    else if (c1.pib < c2.pib)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");

    printf("Pontos Turísticos: ");
    if (c1.pontosTuristicos > c2.pontosTuristicos)
        printf("Carta 1 venceu\n");
    else if (c1.pontosTuristicos < c2.pontosTuristicos)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");

    printf("Densidade Populacional (menor vence): ");
    if (c1.densidadePopulacional < c2.densidadePopulacional)
        printf("Carta 1 venceu\n");
    else if (c1.densidadePopulacional > c2.densidadePopulacional)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");

    printf("PIB per Capita: ");
    if (c1.pibPerCapita > c2.pibPerCapita)
        printf("Carta 1 venceu\n");
    else if (c1.pibPerCapita < c2.pibPerCapita)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");

    printf("Super Poder: ");
    if (c1.superPoder > c2.superPoder)
        printf("Carta 1 venceu\n");
    else if (c1.superPoder < c2.superPoder)
        printf("Carta 2 venceu \n");
    else
        printf("Empate \n");
}