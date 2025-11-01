#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "zoologico.h"

struct ficha {
    char nome[100];
    int idade;
    float valor;
};

// Função para ler e validar a quantidade de ingressos
int lerQuantidade() {
    int quantidade, resultado;
    do {
        printf("Qual a quantidade de ingressos que você deseja comprar? ");
        resultado = scanf("%d", &quantidade);

        if (resultado != 1) {
            printf("Informação inválida. Digite um número de 1 a 5.\n");
            while (getchar() != '\n'); // limpa buffer
            quantidade = 0;
            continue;
        }

        if (quantidade < 1 || quantidade > 5) {
            printf("Quantidade inválida! Digite novamente (mínimo 1, máximo 5).\n");
        }

    } while (quantidade < 1 || quantidade > 5);

    return quantidade;
}

// Função para ler e validar o nome do visitante
void lerNome(char *nome) {
    int valido;
    do {
        valido = 1;
        printf("Digite o nome do visitante: ");
        scanf(" %[^\n]", nome);

        int temLetra = 0;
        for (int j = 0; nome[j] != '\0'; j++) {
            if (isdigit((unsigned char)nome[j])) {
                valido = 0;
                break;
            }
            if (nome[j] != ' ') {
                temLetra = 1;
            }
        }

        if (!temLetra) {
            valido = 0;
        }

        if (!valido) {
            printf("Nome inválido! Digite apenas letras e ao menos uma válida.\n");
        }

    } while (!valido);
}

// Função para ler e validar idade
int lerIdade(char *nome) {
    char idadeStr[10];
    int idade, valido;
    do {
        valido = 1;
        printf("Digite a idade de %s: ", nome);
        scanf(" %[^\n]", idadeStr);

        for (int k = 0; idadeStr[k] != '\0'; k++) {
            if (!isdigit((unsigned char)idadeStr[k])) {
                valido = 0;
                break;
            }
        }

        if (!valido || idadeStr[0] == '\0') {
            printf("Idade inválida. Tente novamente.\n");
            valido = 0;
            continue;
        }

        idade = atoi(idadeStr);

        if (idade <= 0 || idade > 110) {
            printf("Idade inválida! Digite entre 1 e 110 anos.\n");
            valido = 0;
        }

    } while (!valido);

    return idade;
}

// Função para calcular o valor do ingresso pela idade
float calcularValor(int idade) {
    if (idade <= 12) return 10.0;
    else if (idade <= 59) return 30.0;
    else return 15.0;
}

// Função para exibir o resumo dos ingressos
void exibirResumo(struct ficha ingresso[], int quantidade, float total) {
    printf("\n------------------------------------------------------------\n");
    printf("                     RESUMO DOS INGRESSOS                   \n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < quantidade; i++) {
        printf("Ingresso %d:\n", i + 1);
        printf("Nome:  %s\n", ingresso[i].nome);
        printf("Idade: %d\n", ingresso[i].idade);
        printf("Valor: R$ %.2f\n", ingresso[i].valor);
        printf("------------------------------------------------------------\n");
    }

    printf("\nValor total: R$ %.2f\n", total);
}

int main() {
    setlocale(LC_ALL, "");

    printf("------------------------------------------------------------\n");
    printf("                         ZOOLÓGICO                          \n");
    printf("------------------------------------------------------------\n");

    int quantidade = lerQuantidade();
    struct ficha ingresso[5];
    float total = 0;

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Ingresso %d ---\n", i + 1);

        lerNome(ingresso[i].nome);
        ingresso[i].idade = lerIdade(ingresso[i].nome);
        ingresso[i].valor = calcularValor(ingresso[i].idade);

        total += ingresso[i].valor;
    }

    exibirResumo(ingresso, quantidade, total);

    return 0;
}
