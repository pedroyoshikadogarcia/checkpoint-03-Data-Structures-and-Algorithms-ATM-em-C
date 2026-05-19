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
 
    printf("\n---------- SALDO ----------\n");
    printf("Saldo atual: R$ %.2f\n", saldo);
    printf("-----------------------\n");
}

float realizarDeposito(float saldo) {
 
    float valor;
    char operacao[100];
 
    printf("\nDigite o valor do deposito: R$ ");
    scanf("%f", &valor);
 
    if(valor > 0) {
 
        saldo += valor;
 
        printf("\nDeposito realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", saldo);
 
        sprintf(operacao, "Deposito: +R$ %.2f", valor);
        registrarOperacao(operacao);
 
    } else {
 
        printf("\nValor invalido!\n");
    }
 
    return saldo;
}

float realizarSaque(float saldo) {
 
    float valor;
    char operacao[100];
 
    printf("\nDigite o valor do saque: R$ ");
    scanf("%f", &valor);
 
    if(valor > 1000) {
 
        printf("\nLimite diario excedido!\n");
 
    } else if(valor <= 0) {
 
        printf("\nValor invalido!\n");
 
    } else if(valor > saldo) {
 
        printf("\nSaldo insuficiente!\n");
 
    } else {
 
        saldo -= valor;
 
        printf("\nSaque realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", saldo);
 
        sprintf(operacao, "Saque: -R$ %.2f", valor);
        registrarOperacao(operacao);
    }
 
    return saldo;
}
 
void mostrarExtrato(float saldo) {
 
    int i;
 
    printf("\n--------- EXTRATO ----------\n");
 
    if(totalOperacoes == 0) {
 
        printf("Nenhuma operacao realizada.\n");
 
    } else {
 
        for(i = 0; i < totalOperacoes; i++) {
 
            printf("%d. %s\n", i + 1, historico[i]);
        }
    }
 
    printf("\nSaldo atual: R$ %.2f\n", saldo);
    printf("-----------------------------\n");
}

int main() {
 
    int opcao;
    float saldo = 500.00;
 
    do {
 
        limparTela();
 
        exibirMenu();
 
        scanf("%d", &opcao);
 
        switch(opcao) {
 
            case 1:
                limparTela();
                consultarSaldo(saldo);
                pausar();
                break;
 
            case 2:
                limparTela();
                saldo = realizarSaque(saldo);
                pausar();
                break;
 
            case 3:
                limparTela();
                saldo = realizarDeposito(saldo);
                pausar();
                break;
 
            case 4:
                limparTela();
                mostrarExtrato(saldo);
                pausar();
                break;
 
            case 0:
                limparTela();
                printf("Encerrando sistema...\n");
                printf("Obrigado por utilizar nosso ATM!\n");
                break;
 
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
 
    } while(opcao != 0);
 
    return 0;
}