#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;                     // Letra de 'A' a 'H'
    char codigo[4];                  // Ex: A01, B03
    char nomeCidade[100];           // Nome da cidade
    int populacao;                  // Número de habitantes
    float area;                     // Área em km²
    float pib;                      // PIB em bilhões de reais
    int pontosTuristicos;          // Número de pontos turísticos
    float densidadePopulacional;   // Habitantes por km²
    float pibPerCapita;            // PIB per capita em reais
};

// Função para ler os dados de uma carta
void lerCarta(struct Carta *carta, int numero) {
    printf("\n=== Inserção da Carta %d ===\n", numero);
    
    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o Nome da Cidade: ");
    getchar(); // Consumir o \n pendente
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);

    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo da densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;

    // Cálculo do PIB per capita (converte bilhões para reais)
    carta->pibPerCapita = (carta->pib * 1000000000.0) / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    printf("==== Cadastro de Cartas Super Trunfo ====\n");

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    printf("\n==== Exibindo Cartas Cadastradas ====\n");

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
