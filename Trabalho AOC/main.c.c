#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 50
#define MAX_TAMANHO_LINHA 100
#define TAMANHO_STRING 10
#define QNTD_MAX_FUNCOES 30

typedef struct {
    char estrutura[TAMANHO_STRING];
    char arg1[TAMANHO_STRING];
    char arg2[TAMANHO_STRING];
    char arg3[TAMANHO_STRING];
    int passaPelaMemoria; // bin
    int passaPeloWB; // bin
} Funcao;

void LeFuncaoSW(char* linha, Funcao* funcao){
    char* token = strtok(linha, ", ");
    int contador = 0;

    while (token != NULL) {
        if (contador == 0) {
            strncpy(funcao->arg1, token, TAMANHO_STRING);
        } else if (contador == 1) {
            strncpy(funcao->arg2, token, TAMANHO_STRING);
        } else if (contador == 2) {
            strcpy(funcao->arg3, "nada");
        }
        contador++;
        token = strtok(NULL, ", ");
    }

    funcao->passaPelaMemoria = 1;
    funcao->passaPeloWB = 0;
}

void LeFuncaoLW(char* linha, Funcao* funcao){
    char* token = strtok(linha, ", ");
    int contador = 0;

    while (token != NULL) {
        if (contador == 0) {
            strncpy(funcao->arg1, token, TAMANHO_STRING);
        } else if (contador == 1) {
            strncpy(funcao->arg2, token, TAMANHO_STRING);
        } else if (contador == 2) {
            strcpy(funcao->arg3, "nada");
        }
        contador++;
        token = strtok(NULL, ", ");
    }

    funcao->passaPelaMemoria = 1;
    funcao->passaPeloWB = 1;
}

void LeFuncao1Arg(char* linha, Funcao* funcao){
    char* token =  strtok(linha," ");
    int contador = 0;

    while (token != NULL) {
        if (contador == 0) {
            strncpy(funcao->arg1, token, TAMANHO_STRING);
        } else if (contador == 1) {
            strcpy(funcao->arg2, "nada");
        } else if (contador == 2) {
            strcpy(funcao->arg3, "nada");
        }
        contador++;
        token = strtok(NULL, " ");
    }

    funcao->passaPelaMemoria = 0;
    funcao->passaPeloWB = 1;
}

void LeFuncao3Args(char* linha, Funcao* funcao) {
    char* token = strtok(linha, ", ");
    int contador = 0;

    while (token != NULL) {
        if (contador == 0) {
            strncpy(funcao->arg1, token, TAMANHO_STRING);
        } else if (contador == 1) {
            strncpy(funcao->arg2, token, TAMANHO_STRING);
        } else if (contador == 2) {
            strncpy(funcao->arg3, token, TAMANHO_STRING);
        }
        contador++;
        token = strtok(NULL, ", ");
    }

    funcao->passaPelaMemoria = 0;
    funcao->passaPeloWB = 1;
}

void LeArquivo(char linhas[MAX_LINHAS][MAX_TAMANHO_LINHA], Funcao* funcoes[QNTD_MAX_FUNCOES], int* totalDeFuncoes) {
    int indiceFuncao = 0;

    for (int j = 0; j < MAX_LINHAS; j++) {
        if (strncmp(linhas[j], "main:", 5) == 0) {
            for (int k = j + 1; k < MAX_LINHAS; k++) {
                if (strncmp(linhas[k], "addi", 4) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "addi");
                    LeFuncao3Args(linhas[k] + 5, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "add", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "add");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "sub", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "sub");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "sll", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "sll");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "beq", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "beq");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "bne", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "bne");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "blt", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "blt");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "bgt", 3) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "bgt");
                    LeFuncao3Args(linhas[k] + 4, funcoes[indiceFuncao]);
                    indiceFuncao++;
///////////////////////////////////////////////////////////////////////
                }else if (strncmp(linhas[k], "lw", 2) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "lw");
                    LeFuncaoLW(linhas[k] + 3, funcoes[indiceFuncao]);
                    indiceFuncao++;
//////////////////////////////////////////////////////////////////////
                }else if (strncmp(linhas[k], "sw", 2) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "sw");
                    LeFuncaoSW(linhas[k] + 3, funcoes[indiceFuncao]);
                    indiceFuncao++;
//////////////////////////////////////////////////////////////////////
                }else if (strncmp(linhas[k], "j", 1) == 0) {
                    strcpy(funcoes[indiceFuncao]->estrutura, "j");
                    LeFuncao1Arg(linhas[k] + 2, funcoes[indiceFuncao]);
                    indiceFuncao++;
                }else if (strncmp(linhas[k], "li $v0, 10", 10) == 0) {
                    // Para de ler e salvar funcoes ao encontrar "li $v0, 10"
                    (*totalDeFuncoes) = indiceFuncao;
                    printf("\n%i\n", indiceFuncao);
                    return;
                }
            }
            break;
        }
    }
}


// Os dois voids abaixos são usados na simulação da tabela
// Se a função tiver 2 argumentos vai ser exibida assim
void imprimeFuncao1Arg(Funcao*** funcoes, int i){
        printf("Função: ");
        printf("%s, %s\n", (*funcoes)[i]->estrutura, (*funcoes)[i]->arg1);
    }
    void imprimeFuncao2Arg(Funcao*** funcoes, int i){
        printf("Função: ");
        printf("%s, %s, %s\n", (*funcoes)[i]->estrutura, (*funcoes)[i]->arg1, (*funcoes)[i]->arg2);
    }
    // Se a função tiver 3 argumentos vai ser exibida assim
    void imprimeFuncao3Arg(Funcao*** funcoes, int i){
        printf("Função: ");
        printf("%s, %s, %s, %s\n", (*funcoes)[i]->estrutura, (*funcoes)[i]->arg1,(*funcoes)[i]->arg2, (*funcoes)[i]->arg3);
    }
    // Se for preciso uma bolha, vai ser assim


    void adicionaBolha(Funcao*** funcoes, int i, int* totalCiclos, int motivo){

    printf("Foi identificada uma necessidade do uso da bolha\n");
    if(motivo == 1){
        printf("Como a função anterior (%s) passa pela memória e essa não, elas vão colidir\n", (*funcoes)[i-1]->estrutura);
    }else if(motivo == 2){
        printf("Como a função anterior (%s) passa pela memória e essa não, elas vão colidir\n", (*funcoes)[i-1]->estrutura);
        printf("Como essa função necessita da resposta contida no arg1 da função passada (%s), é necessário o uso de uma bolha\n", (*funcoes)[i-1]->estrutura);
        printf("Logo, será preciso o uso de duas bolhas\n");
        printf("\nBolha:\n");
        printf("If\n");
        printf("If > Id\n");
        printf("Id > exe\n");
        printf("Exe > Wb\n");
        printf("-------------------\n");
        (*totalCiclos)++;
    }else{
        printf("Como essa função necessita da resposta contida no arg1 da função passada (%s), é necessário o uso de uma bolha\n", (*funcoes)[i-1]->estrutura);
        (*totalCiclos)++;
    }

        printf("Bolha:\n");
        printf("If\n");
        printf("If > Id\n");
        printf("Id > exe\n");
        printf("Exe > Wb\n");
        printf("Total de ciclos até agora: %i\n", (*totalCiclos)); 
        printf("-------------------\n");

    return;
    }

    void completaLinha(int quantidade){

    int total = 21 - quantidade;

    for(int i = 0; i < total; i++){
    printf(" ");
    }

    return;
}

void imprimeOResto(int totalDeCiclos, int cicloAtual, int quantidade){
    
    int maximo = totalDeCiclos - (cicloAtual + quantidade);

    for(int k = 0; k < maximo+1; k++){
        printf("     |");
    }

    printf("\n");

    return;
}

void imprimeLinha(Funcao* funcoes, int cicloAtual, int totalDeCiclos){

    int i = cicloAtual - 1;

    if(funcoes->passaPelaMemoria == 1 && funcoes->passaPeloWB == 0){
        for(int j = 0; j < i; j++){
        printf("|     ");
        }
        printf("| IF  | ID  | EXE | MEM |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
    }else if(funcoes->passaPelaMemoria == 0){
        for(int j = 0; j < i; j++){
            printf("|     ");
        }
        printf("| IF  | ID  | EXE | WB  |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
    }else{
        for(int j = 0; j < i; j++){
        printf("|     ");
        }
        printf("| IF  | ID  | EXE | MEM | WB  |");
        imprimeOResto(totalDeCiclos, cicloAtual, 5);
    }

    return;
}

void imprimeTabelaComFowarding(int totalDeCiclos, Funcao* funcoes[], int totalDeFuncoes, int totalDeBolhas[]){

    for(int i = 0; i < totalDeFuncoes; i++){
        if(totalDeBolhas[i] == 1 && totalDeBolhas[i+1] != 0){
            totalDeCiclos--;
        }else if(totalDeBolhas[i] == 2){
            totalDeCiclos--;
        }
    }

    printf("\n-------------------- |");
    for(int i = 0; i < totalDeCiclos; i++){
    printf("  %i  |", i+1);
    }
    printf("\n");

    //int posicaoDaBolha[30];
    int cicloAtual = 1;

    for(int i = 0; i < totalDeFuncoes; i++){
    int quantidade = 0;

    if(totalDeBolhas[i] == 1 && totalDeBolhas[i+1] != 0){
        printf("NOP                  ");
    for(int k = 0; k < cicloAtual-1; k++){
        printf("|     ");
    }
        printf("| NOP | NOP | NOP | NOP |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
        cicloAtual++;
    }
        if(strcasecmp(funcoes[i]->arg2, "nada") == 0) {
        printf("%s, %s", funcoes[i]->estrutura, funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + 2;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }else if(strcasecmp(funcoes[i]->arg3, "nada") == 0){
        printf("%s, %s, %s", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->arg2);
        quantidade = quantidade + 4;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }else{
        printf("%s, %s, %s, %s", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2, funcoes[i]->arg3);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->arg2);
        quantidade = quantidade + strlen(funcoes[i]->arg3);
        quantidade = quantidade + 6;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }
        cicloAtual++;
    }

    return;
}

void imprimeTabela(int totalDeCiclos, Funcao* funcoes[], int totalDeFuncoes, int totalDeBolhas[]){

    printf("\n-------------------- |");
    for(int i = 0; i < totalDeCiclos; i++){
    printf("  %i  |", i+1);
    }
    printf("\n");


    int cicloAtual = 1;

    for(int i = 0; i < totalDeFuncoes; i++){
        if(totalDeBolhas[i] == 1 && totalDeBolhas[i+1] != 0){
            totalDeFuncoes = totalDeFuncoes - 2;
        }else if(totalDeBolhas[i] == 2){
            totalDeFuncoes--;
        }
    }


    for(int i = 0; i < totalDeFuncoes; i++){
    int quantidade = 0;

    if(totalDeBolhas[i] == 1 && totalDeBolhas[i+1] != 0){
        printf("NOP                  ");
        for(int k = 0; k < cicloAtual-1; k++){
            printf("|     ");
        }
        printf("| NOP | NOP | NOP | NOP |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
        cicloAtual++;
        printf("NOP                  ");
        for(int k = 0; k < cicloAtual-1; k++){
            printf("|     ");
        }
        printf("| NOP | NOP | NOP | NOP |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
        cicloAtual++;
    }else if(totalDeBolhas[i] == 2){
        printf("NOP                  ");
        for(int k = 0; k < cicloAtual-1; k++){
        printf("|     ");
    }
        printf("| NOP | NOP | NOP | NOP |");
        imprimeOResto(totalDeCiclos, cicloAtual, 4);
        cicloAtual++;
    }
    if(strcasecmp(funcoes[i]->arg2, "nada") == 0) {
        printf("%s, %s", funcoes[i]->estrutura, funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + 2;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }else if(strcasecmp(funcoes[i]->arg3, "nada") == 0){
        printf("%s, %s, %s", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->arg2);
        quantidade = quantidade + 4;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }else{
        printf("%s, %s, %s, %s", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2, funcoes[i]->arg3);
        quantidade = quantidade + strlen(funcoes[i]->estrutura);
        quantidade = quantidade + strlen(funcoes[i]->arg1);
        quantidade = quantidade + strlen(funcoes[i]->arg2);
        quantidade = quantidade + strlen(funcoes[i]->arg3);
        quantidade = quantidade + 6;
        completaLinha(quantidade);
        imprimeLinha(funcoes[i], cicloAtual, totalDeCiclos);
    }
    cicloAtual++;
    }


    printf("\nDeseja ver como fica o pipeline com fowarding?\n[1] - Sim\n[2] - Não\n\nSua escolha: ");
    int escolha;
    scanf("%i", &escolha);
    if(escolha == 1){
        imprimeTabelaComFowarding(totalDeCiclos, funcoes, totalDeFuncoes, totalDeBolhas);
    }else{
        return;
    }

    return;
}

// A parte mais complicada em si onde vamos ter que tratar todas as necessidades
void simulaTabela(Funcao* funcoes[], int totalDeFuncoes) {

    int totalDeCiclos = 0;
    printf("\n-------------------\n");
    int totalDeBolhas[30];

    for(int i = 0; i < 30; i++){
        totalDeBolhas[i] = 0;
    }

    int quantidadeDeBolhas = 0;

    for (int i = 0; i < totalDeFuncoes; i++) {
    if (i > 0) {
    
    if (strcasecmp(funcoes[i-1]->estrutura, "lw") == 0) {
        if (strcasecmp(funcoes[i]->estrutura, "lw") != 0) {
            if (strcasecmp(funcoes[i]->arg1, funcoes[i-1]->arg1) == 0 || strcasecmp(funcoes[i]->arg2, funcoes[i-1]->arg1) == 0 || strcasecmp(funcoes[i]->arg3, funcoes[i-1]->arg1) == 0) {
                adicionaBolha(&funcoes, i, &totalDeCiclos, 2);
                totalDeBolhas[i] = 1;
                totalDeBolhas[i+1] = 1; 
                quantidadeDeBolhas = quantidadeDeBolhas + 2;
            }else{
                adicionaBolha(&funcoes, i, &totalDeCiclos, 1);
                totalDeBolhas[i] = 2;
                quantidadeDeBolhas++;
                // Se a função atual não passa pela memória, mas a anterior passa, vai adicionar bolha
                }
        }
    } else if (strcasecmp(funcoes[i]->arg1, funcoes[i-1]->arg1) == 0 || strcasecmp(funcoes[i]->arg2, funcoes[i-1]->arg1) == 0 || strcasecmp(funcoes[i]->arg3, funcoes[i-1]->arg1) == 0) {
        adicionaBolha(&funcoes, i, &totalDeCiclos, 3);
        totalDeBolhas[i] = 2;
        quantidadeDeBolhas++;
        // Se a função atual tiver em algum dos argumentos uma variavel que ainda vai receber um valor em uma função anterior, adiciona bolha
    }
    }

    // Se salvar como 'nada' quer dizer que n tem argumento então imprime assim
    if (strcasecmp(funcoes[i]->arg2, "nada")){
        imprimeFuncao1Arg(&funcoes, i);
    }else if (strcasecmp(funcoes[i]->arg3, "nada") == 0) {
        imprimeFuncao2Arg(&funcoes, i);
    } else {
        imprimeFuncao3Arg(&funcoes, i); 
    }

    // imprime TODAS as operações
    // Calcula o total de ciclos
    if (i == 0) { // Primeiro caso
        printf("If\n");
        printf("If > Id\n");
        printf("Id > Exe\n");
    if (strcasecmp(funcoes[i]->estrutura, "lw") == 0) {
        printf("Exe > Mem\n");
        printf("Mem > Wb\n");
        totalDeCiclos = 5;
    } else {
        printf("Exe > Wb\n");
        totalDeCiclos = 4; 
    }
        printf("Total de ciclos até agora: %i\n", totalDeCiclos);
        printf("-------------------\n"); 
    } else { // Demais casos 
        printf("If\n");
        printf("If > Id\n");
        printf("Id > Exe\n");
    if (strcasecmp(funcoes[i]->estrutura, "lw") == 0) {
        printf("Exe > Mem\n");
        printf("Mem > Wb\n");
        if(strcasecmp(funcoes[i-1]->estrutura, "lw") == 0){
        totalDeCiclos++;
    }else{
        totalDeCiclos = totalDeCiclos + 2;
    }
        printf("Total de ciclos até agora: %i\n", totalDeCiclos);
        printf("-------------------\n"); 
    } else {
        printf("Exe > Wb\n");
        totalDeCiclos++;
        printf("Total de ciclos até agora: %i\n", totalDeCiclos);
        printf("-------------------\n"); 
    }
    
    }
    }

    printf("Total de ciclos: %i\n", totalDeCiclos);


    totalDeFuncoes = totalDeFuncoes + quantidadeDeBolhas;
    imprimeTabela(totalDeCiclos, funcoes, totalDeFuncoes, totalDeBolhas);

}


int main(){

    int totalDeFuncoes = 0;

    Funcao* funcoes[QNTD_MAX_FUNCOES];

    FILE *arquivo;
    char linhas[MAX_LINHAS][MAX_TAMANHO_LINHA];
    int i;

    // Aloca memória para cada função
    for (i = 0; i < QNTD_MAX_FUNCOES; i++) {
        funcoes[i] = (Funcao *)malloc(sizeof(Funcao));
        funcoes[i]->estrutura[0] = '\0';  // Inicializa a estrutura com uma string vazia
    }

    // Abre o arquivo para leitura
    arquivo = fopen("../codigo.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Lê até 10 linhas do arquivo
    for (i = 0; i < MAX_LINHAS; i++) {
        if (fgets(linhas[i], MAX_TAMANHO_LINHA, arquivo) == NULL) {
            break; // Sai do loop se não houver mais linhas para ler
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    LeArquivo(linhas, funcoes, &totalDeFuncoes);

    for (i = 0; i < QNTD_MAX_FUNCOES; i++) {
        if (funcoes[i]->estrutura[0] != '\0') { // Verifica se a estrutura foi preenchida
            if(funcoes[i]->passaPelaMemoria == 1){
                printf("\n\n%s %s, %s\n\n", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2);
            }else if(strlen(funcoes[i]->estrutura) == 1){
                printf("\n\n%s %s\n\n", funcoes[i]->estrutura, funcoes[i]->arg1);
            }else{
                printf("\n\n%s %s, %s, %s\n\n", funcoes[i]->estrutura, funcoes[i]->arg1, funcoes[i]->arg2, funcoes[i]->arg3);
            }
        }
    }

    simulaTabela(funcoes, totalDeFuncoes);

    // Libera a memória alocada
    for (i = 0; i < QNTD_MAX_FUNCOES; i++) {
        free(funcoes[i]);
    }

    return 0;
}