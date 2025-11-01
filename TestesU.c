#include "minunit.h"
#include "zoologico.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int tests_run = 0;      // Contador de testes

#define EPSILON 1e-6

// Função auxiliar para comparar floats
static int float_iguais(float a, float b) {
    return fabsf(a - b) < EPSILON;
}

// Teste de calcularValor
static char * test_calcularValor(void) {
    mu_assert("Criança: 10 anos deveria ser R$ 10.00", float_iguais(calcularValor(10), 10.0f));
    mu_assert("Criança: 12 anos deveria ser R$ 10.00", float_iguais(calcularValor(12), 10.0f));
    mu_assert("Adulto: 30 anos deveria ser R$ 30.00", float_iguais(calcularValor(30), 30.0f));
    mu_assert("Adulto: 13 anos deveria ser R$ 30.00", float_iguais(calcularValor(13), 30.0f));
    mu_assert("Adulto: 59 anos deveria ser R$ 30.00", float_iguais(calcularValor(59), 30.0f));
    mu_assert("Idoso: 70 anos deveria ser R$ 15.00", float_iguais(calcularValor(70), 15.0f));
    mu_assert("Idoso: 60 anos deveria ser R$ 15.00", float_iguais(calcularValor(60), 15.0f));
    return NULL;
}

// Executa todos os testes
char * rodar_testes(void) {
    char *resultado = test_calcularValor();

    if (resultado != NULL) {
        printf("\n--- FALHA NO TESTE ---\n%s\n", resultado);
    } else {
        printf("\n--- TODOS OS TESTES PASSARAM ---\n");
    }

    printf("Testes rodados: %d\n", tests_run);
    return resultado;
}
