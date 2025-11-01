#include "minunit.h"
#include "zoologico.h"
#include <stdio.h>

// Necessário para o MinUnit
int tests_run = 0;

// Função de teste para a função 'calcularValor'
char * test_calcularValor() {
    // Casos de teste de Partição Equivalente e Análise de Valor Limite

    // Testes para Criança (idade <= 12)
    mu_assert("Criança: 10 anos deveria ser R$ 10.00", calcularValor(10) == 10.0);
    mu_assert("Criança no limite superior: 12 anos deveria ser R$ 10.00", calcularValor(12) == 10.0);

    // Testes para Adulto (13 <= idade <= 59)
    mu_assert("Adulto: 30 anos deveria ser R$ 30.00", calcularValor(30) == 30.0);
    mu_assert("Adulto no limite inferior: 13 anos deveria ser R$ 30.00", calcularValor(13) == 30.0);
    mu_assert("Adulto no limite superior: 59 anos deveria ser R$ 30.00", calcularValor(59) == 30.0);

    // Testes para Idoso (idade >= 60)
    mu_assert("Idoso: 70 anos deveria ser R$ 15.00", calcularValor(70) == 15.0);
    mu_assert("Idoso no limite inferior: 60 anos deveria ser R$ 15.00", calcularValor(60) == 15.0);

    return 0;
}

/*
 * NOTA: As funções de entrada como 'lerQuantidade', 'lerNome' e 'lerIdade'
 * não são testadas unitariamente aqui porque dependem da interação direta
 * do usuário (teclado). Testes para essas funções exigiriam redirecionamento
 * de entrada, o que torna o teste mais complexo.
 */

// Função principal de execução dos testes
char * all_tests() {
    mu_run_test(test_calcularValor);
    return 0;
}

// Função que executa todos os testes
char * rodar_testes() {
    printf("--- EXECUTANDO TESTES UNITÁRIOS ---\n");
    char *result = all_tests();

    if (result != 0) {
        printf("--- FALHA NO TESTE ---\n");
        printf("%s\n", result);
    } else {
        printf("--- TODOS OS TESTES PASSARAM ---\n");
    }
    printf("Testes rodados: %d\n", tests_run);

    return 0;
}
