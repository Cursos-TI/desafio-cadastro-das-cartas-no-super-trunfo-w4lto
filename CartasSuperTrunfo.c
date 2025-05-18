#include <stdio.h>
#include <string.h>


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    struct Carta carta1, carta2;

    printf("==== Cadastro de Cartas Super Trunfo ====\n");

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    printf("\n==== Exibindo Cartas Cadastradas ====\n");

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}


// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;                     // Letra de 'A' a 'H'
    char codigo[4];                  // Ex: A01, B03
    char nomeCidade[100];           // Nome da cidade
    int populacao;                  // Número de habitantes
    float area;                     // Área em km²
    float pib;                      // PIB em bilhões de reais
    int pontosTuristicos;          // Número de pontos turísticos
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

    // Remover a quebra de linha no final (caso exista)
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
}