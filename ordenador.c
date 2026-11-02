#include <stdio.h>
#include <stdlib.h>

// Função para gravar números no arquivo
void gravarNumeros(const char *arquivo) {

    //Abre o arquivo em modo escrita (write)
    FILE *fp = fopen(arquivo, "w");
    // Testa se o arquivo abriu corretamente. E mostra mensagem de erro se não abrir 
    if (fp == NULL) { 
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
}

    int n, numero;
printf("Quantos numeros deseja gravar? ");
    // Lê quantidade de numeros a gravar e os guarda
scanf("%d", &n);
if (n < 1 || n > 100) {
    printf("Quantidade invalida! Digite um valor entre 1 e 100.\n");
    fclose(fp);
    return;
}

    /* Percorre o vetor várias vezes e permite que o usuário digite 
    vários números e que eles sejam armazenados*/
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        // Lê o número digitado pelo usuário e guarda na variável numero
        scanf("%d", &numero);
        // Grava o numero no arquivo
        fprintf(fp, "%d\n", numero); 
    }

    // Fecha o arquivo
    fclose(fp);
    printf("Números gravados com sucesso!\n");
    
}
// Função para ler números do arquivo
int lerNumeros(const char *arquivo, int v[]) {
    //Abre o arquivo em modo leitura 
    FILE *fp = fopen(arquivo, "r");
    // Se o arquivo for nulo, será exibida uma mensagem de erro
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0;
    }
    //Variáveis para guardar temporariamente cada número lido do arquivo
    int numero;
    int n = 0;
    printf("\nNumeros gravados no arquivo:\n");
    //Lê os números que estão salvos no arquivo, mostra cada um na tela e guarda cada número em um vetor
    while (n < 100 && fscanf(fp, "%d", &numero) == 1) {
        v[n] = numero;
    // Lê linha a linha do arquivo
        printf("%d\n", numero);
        n ++;
    }
    // Fecha o arquivo
    fclose(fp);
    return n;
}

    // Ordenador Bubble Sort
    void bubbleSort(int v[], int n) {
        int i, j, aux;
        // Percorre o vetor várias vezes
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                // Se o elemento atual for maior que o próximo, troca
                if (v[j] > v[j + 1]) {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }
    }

// Ordenador Insertion Sort
void insertionSort(int v[], int n) {
    int i, j, chave;
    // Começa a partir do segundo elemento
    for (i = 1; i < n; i++) {
        chave = v[i]; // Armazena o valor atual
        j = i - 1;
        // Move os elementos maiores para a direita 
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        // Insere a chave na posição correta
        v[j + 1] = chave;
    }
}
//Ordenador Selection Sort
void selectionSort(int v[], int n) {
    int i, j, min, aux;
    // Percorre o vetor
    for (i = 0; i < n - 1; i++) {
        // Assume que o menor é o atual
        min = i;
         // Procura o menor valor à frente
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        // Troca se encontrou menor
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}
//Ordenador Merge
void merge(int v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];
    // Compara os valores dos dois lados e coloca o menor no vetor auxiliar
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
}
    // Copia os valores que sobraram do lado esquerdo
    while (i <= meio) aux[k++] = v[i++];
    // Copia os valores que sobraram do lado direito
    while (j <= fim) aux[k++] = v[j++];
    // Copia os valores ordenados de volta para o vetor original
    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];
}
// Divide o vetor em partes menores até sobrar um elemento
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        // Parte esquerda
        mergeSort(v, inicio, meio); 
        // Parte direita
        mergeSort(v, meio + 1, fim);
        // Intercala
        merge(v, inicio, meio, fim);
    }
}
// Ordenador Quick Sort
void quickSort(int v[], int inicio, int fim) {
    // Define os índices e escolhe o pivô (elemento que ficará no meio)
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2], aux;
// Separa os números maiores e menores que o pivô
    while (i <= j) {
        while (v[i] < pivo) i++; // Percorre enquanto o valor for menor que o pivô
        while (v[j] > pivo) j--; // Volta enquanto o valor for maior que o pivô
        if (i <= j) {         // Troca os valores de posição quando necessário
            aux = v[i]; // Guarda temporariamente o valor
            v[i] = v[j]; // Coloca o valor de j na posição de i
            v[j] = aux;  // Coloca o valor guardado na posição de j
            i++;
            j--;
        }
    }

    // Recursão nas partes esquerda e direita
    if (inicio < j) quickSort(v, inicio, j);
    if (i < fim) quickSort(v, i, fim);
}

// Função para guardar os números ordenados em um arquivo
void gravarOrdenados(const char *arquivo, int v[], int n) {
    FILE *fp = fopen(arquivo, "w"); // Abre em modo escrita
    if (!fp) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    // Grava cada número do vetor no arquivo
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", v[i]);
    }
    fclose(fp);
}
// Função para guardar número específico no arquivo
int alterarNumeros(const char *arquivo, int posicao, int novoValor) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0;
    }

    FILE *an = fopen("temp.txt", "w"); // Cria um arquivo temporário para escrita
    if (an == NULL) {
        printf("Erro ao criar o arquivo temporario.\n");
        fclose(fp);
        return 0;
    }

    int numero;
    int atual = 1;
    int quantidade = 0;

    // Conta quantos números existem no arquivo
    while (fscanf(fp, "%d", &numero) == 1) {
        quantidade++;
    }

    if (posicao < 1 || posicao > quantidade) {
        printf("Posicao invalida!\n");
        fclose(fp);
        fclose(an);
        remove("temp.txt");
        return 0;
    }

    rewind(fp);
    // Lê os números do arquivo original e substitui o valor escolhido
    while (fscanf(fp, "%d", &numero) == 1) {
        if (atual == posicao) {
            numero = novoValor;
        }
        fprintf(an, "%d\n", numero);
        atual++;
    }

    fclose(fp);
    fclose(an);

    // Remove o arquivo original antes de substituí-lo
    if (remove(arquivo) != 0) {
        printf("Erro ao substituir o arquivo original!\n");
        remove("temp.txt");
        return 0;
    }

    // Renomeia o arquivo temporário para o nome do arquivo original
    if (rename("temp.txt", arquivo) != 0) {
        printf("Erro ao renomear o arquivo temporario!\n");
        return 0;
    }

    return 1;
}
// Função para ordenar os números
int ordenarNumeros(int v[], int n) {
    int ordenador;
    int resultado;

    printf("Selecione que tipo de ordenador deseja utilizar: \n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");

    // Continua pedindo até receber uma opção válida entre 1 e 5.
    for (;;) {
        printf("Ordenador (1 a 5): ");
        resultado = scanf("%d", &ordenador);
        if (resultado == EOF) {
            printf("\nEntrada encerrada.\n");
            return 0;
        }
        if (resultado != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                ;
            }
            printf("Entrada invalida! Digite um numero de 1 a 5.\n");
            continue;
        }
        if (ordenador < 1 || ordenador > 5) {
            printf("Opcao invalida! Escolha de 1 a 5.\n");
            continue;
        }
        break;
    }

    // Executa o método escolhido.
    switch (ordenador) {
        case 1:
            bubbleSort(v, n);
            printf("Vetor ordenado (Bubble Sort): ");
            break;
        case 2:
            insertionSort(v, n);
            printf("Vetor ordenado (Insertion Sort): ");
            break;
        case 3:
            selectionSort(v, n);
            printf("Vetor ordenado (Selection Sort): ");
            break;
        case 4:
            mergeSort(v, 0, n - 1);
            printf("Vetor ordenado (Merge Sort): ");
            break;
        case 5:
            quickSort(v, 0, n - 1);
            printf("Vetor ordenado (Quick Sort): ");
            break;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 1;
}

int main() {
    const char *arquivo = "dados.txt";
    int v[100]; // Vetor para armazenar até 100 números
    int n; // Armazena a quantidade de números lidos
    int posicao; // Armazena a posição do número que será alterado
    int novoValor; // Armazena o novo valor digitado
    int opcao; // Armazena a opção de alterar ou não um número

    gravarNumeros(arquivo);
    n = lerNumeros(arquivo, v);
    // Verifica se algum número foi lido
    if (n == 0) {
        printf("Nenhum numero foi lido do arquivo.\n");
        return 1; // Encerra o programa se não houver números
    }

    if (!ordenarNumeros(v, n)) {
        return 0;
    }
    gravarOrdenados("ordenado.txt", v, n);
    printf("\n");
 
    printf("Deseja alterar um numero? (1 - Sim / 0 - Nao): ");
    scanf("%d", &opcao);

if (opcao == 1) {
    printf("Qual a posicao do numero que deseja alterar? ");
    scanf("%d", &posicao);

    if (posicao < 1 || posicao > n) {
        printf("Posicao invalida!\n");
    } else {
        printf("Digite o novo valor: ");
        scanf("%d", &novoValor);
        if (alterarNumeros(arquivo, posicao, novoValor)) {
            n = lerNumeros(arquivo, v);  // Lê novamente somente se a alteração foi válida
            if (n > 0 && ordenarNumeros(v, n)) {
                gravarOrdenados("ordenado.txt", v, n); // Salva a nova ordenação
            }
        }
    }
} else {
    printf("Nenhum numero foi alterado\n");
}
return 0;
}
