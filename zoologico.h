#ifndef ZOOLOGICO_H
#define ZOOLOGICO_H

// Declaração da variável global de testes
extern int tests_run;

// Protótipos das funções do zoológico
double calcularValor(int idade);

// Funções de entrada (não testadas unitariamente)
int lerQuantidade(const char *mensagem);
void lerNome(char *nome, int tamanho);
int lerIdade();

#endif // ZOOLOGICO_H
