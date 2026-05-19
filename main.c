#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char historico[3][100];
int totalOperacoes = 0;

void limparTela() {
    system("cls");
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void exibirMenu() {
    printf("----CAIXA ELETRONICO-----\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("4 - Ver Extrato\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

 
void registrarOperacao(char operacao[]) {
 
    if(totalOperacoes == 3) {
        strcpy(historico[0], historico[1]);
        strcpy(historico[1], historico[2]);
        strcpy(historico[2], operacao);
    } else {
        strcpy(historico[totalOperacoes], operacao);
        totalOperacoes++;
    }
}
 
void consultarSaldo(float saldo) {
 
    printf("\n========== SALDO ==========\n");
    printf("Saldo atual: R$ %.2f\n", saldo);
    printf("===========================\n");
}