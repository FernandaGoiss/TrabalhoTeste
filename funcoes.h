#ifndef ZOOLOGICO_H
#define ZOOLOGICO_H

// Estrutura para os dados dos ingressos
struct ficha {
    char nome[100];
    int idade;
    float valor;
};

// Declarações das suas funções
int lerQuantidade();
void lerNome(char *nome);
int lerIdade(char *nome);
float calcularValor(int idade);
void exibirResumo(struct ficha ingresso[], int quantidade, float total);

#endif // ZOOLOGICO_H
