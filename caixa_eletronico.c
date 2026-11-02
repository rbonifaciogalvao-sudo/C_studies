#include <stdio.h>

int main() {
    int saldo, saque, restante, n100, n50, n20, n10, n5; // Variáveis inteiras
    saldo = 1000;
    printf("Digite o valor que deseja sacar: "); // Mostra na tela essa frase, para que um valor seja digitado
    scanf("%d", &saque); // Armazena o valor digitado acima na variável saque
    while(saque % 5 != 0) { // Enquanto o resto da divisão do saque por 5 for diferente de 0
        printf("Digite um número múltiplo de 5: "); // Será solicitado um novo valor até que ele seja múltiplo de 5
        scanf("%d", &saque); 
    }
    if (saque > saldo) { // Se o saque for maior que o saldo 
        printf("Saldo insuficiente.\n"); // Será mostrada essa mensagem
    } else { // Se o saque não for maior que o saldo
    restante = saque; //  O valor do saque é armazenado na variável restante para calcular as notas
    n100 = restante / 100; /* Divide o valor restante por 100 para descobrir quantas notas de 100 cabem no saque */
    restante %= 100; /* Guarda o resto da divisão por 100 para calcular as próximas notas*/

    n50 = restante / 50;
    restante %= 50;

    n20 = restante / 20;
    restante %= 20;
    
    n10 = restante / 10;
    restante %= 10;
    
    n5 = restante / 5;
    restante %= 5;

    saldo = saldo - saque; /*Subtrai o valor do saque do saldo para obter o saldo atual */
    printf("Seu saldo é: %d \n", saldo); /*Mostra na tela o valor do saldo atual */
    printf("Notas entregues: \n"); 
    if(n100 > 0) printf("Nota(s) de 100: %d \n", n100); /*Mostra a quantidade de notas de 100 se houver alguma*/
    if(n50 > 0) printf("Nota(s) de 50: %d \n", n50); /*Mostra a quantidade de notas de 50 se houver alguma*/
    if(n20 > 0) printf("Nota(s) de 20: %d \n", n20); /*Mostra a quantidade de notas de 20 se houver alguma*/
    if(n10 > 0) printf("Nota(s) de 10: %d \n", n10); /*Mostra a quantidade de notas de 10 se houver alguma*/
    if(n5 > 0) printf("Nota(s) de 5: %d \n", n5); /*Mostra a quantidade de notas de 5 se houver alguma*/
    }
}
