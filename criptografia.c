#include <stdio.h>
#include <string.h>


int main() {

    char palavra[16];

    char alfabeto[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'
    };

    int shift;
    int tipo = 3;

    printf("Digite uma palavra: ");
    scanf("%15s", palavra);

    printf("Digite o SHIFT: ");
    scanf("%d", &shift);

    // Criação da sequência de Fibonacci
    int fibonacci[15];

    // Define os dois primeiros valores da sequência de Fibonacci
    // F1 = 1 e F2 = 1
    fibonacci[0] = 1;
    fibonacci[1] = 1;

    // Fn = Fn-1 + Fn-2
    for (int i = 2; i < 15; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Descobre a quantidade de letras
    int tamanho = strlen(palavra);

    // Percorre cada letra da palavra
    for (int i = 0; i < tamanho; i++) {

        int posicao = 0;

        // Procura a posição da letra no alfabeto
        for (int j = 0; j < 26; j++) {
            if (palavra[i] == alfabeto[j]) {
                posicao = j;
                break;
            }
        }

        // Aplica o SHIFT e o valor de Fibonacci
        posicao = posicao + shift + fibonacci[i];

        // Faz o alfabeto voltar ao início quando passa do Z
        posicao = posicao % 26;

        // Substitui a letra pela letra criptografada
        palavra[i] = alfabeto[posicao];
    }

    // Mostra o resultado na tela
    printf("\nPalavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
           palavra, shift, tipo, tamanho);

    // Cria o arquivo com o resultado
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // Grava o resultado no arquivo
    fprintf(arquivo,
            "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
            palavra, shift, tipo, tamanho);

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
