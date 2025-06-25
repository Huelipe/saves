#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct para definir os processos (letra como identificador, tempo de chegada
typedef struct processo {
    char letra;
    int tempo;
    int chegada;
} processo;

// Função para ler o arquivo e salvar as informações do arquivo em um vetor struct
void LeArquivo(const char *nome_arquivo, processo **Processos, int *qtd_processos){
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char palavra[50];
    *qtd_processos = 0;
    *Processos = NULL;

        fscanf(arquivo, "%s", palavra);  // esse fscanf vai salvar a primeira palavra do código, e vamos ignorar
        char letra_temp;
        while(fscanf(arquivo, " %c", &letra_temp) == 1){ // Enquanto tiver letras nessa linha, repito o loop
            *Processos = realloc(*Processos, (*qtd_processos + 1) * sizeof(processo));
            // Aqui, uso o realloc para redimensionar o vetor pra não ocupar mais memória do que o necessário
            (*Processos)[*qtd_processos].letra = letra_temp;
            (*qtd_processos)++;
            if(fgetc(arquivo) == '\n'){
                break; // se encontrar o fim da linha, sai do while
            }
        }

        // Segunda linha
        fscanf(arquivo, "%s", palavra); // Ignora a palavra tempo
        for (int i = 0; i < *qtd_processos; i++){ // Salva o tempo de duração de cada processo
            fscanf(arquivo, "%d", &(*Processos)[i].tempo);
        }

        // Terceira linha
        fscanf(arquivo, "%s", palavra);
        for (int i = 0; i < *qtd_processos; i++){ // Salva o tempo de chegada de cada processo 
            fscanf(arquivo, "%d", &(*Processos)[i].chegada);
        }

    fclose(arquivo);
    return;
}

// Função pra exibir o relatório com linha do tempo
void ExibeLinhaDoTempo(char VetorDeLetras[], int totalDeSegundos){
    char letraTemporaria;
    printf("\nLinha do tempo:\n[0]");

    for(int i = 0; i < totalDeSegundos; i++){
        if(i == 0){ // primeiro loop
            letraTemporaria = VetorDeLetras[0];
        }else if(letraTemporaria != VetorDeLetras[i]){
            // já passou do primeiro loop, vou ver até qu ando o processo vai ser executado
            if(letraTemporaria == '-'){ // se tem -, quer dizer que era um processo que terminou de ser executado
                printf("---[NULL]---[%i]", i);
            }else{ // se não tem, quer dizer que era um intervalo onde não tinha nenhum processo pra executar
                printf("---%c---[%i]", letraTemporaria, i);
            }
            letraTemporaria = VetorDeLetras[i];
        }
    }

    // Imprime o último segmento
    if(letraTemporaria == '-'){
        printf("---[NULL]---[%i]", totalDeSegundos);
    }else{
        printf("---%c---[%i]", letraTemporaria, totalDeSegundos);
    }

    printf("\n\n");
    return;
}

void sjfPreemptivo(processo **Processos, int *qtd_processos){
    int processosRestantes = *qtd_processos;
    int segundoAtual = 0;
    char **QualLetraNoSegundo = NULL;
    // esse char é um ponteiro que vamos usar para um vetor chamado QualletraNoSegundo
    // esse vetor vai salvar qual processo está sendo executado em cada segundo
    // assim, no final, fica muito mais facil exibir

    while(processosRestantes > 0){
        int IDprocessoAtual = -1;

        // verifica todos os processos a cada segundo
        for(int i = 0; i < *qtd_processos; i++){
            if((*Processos)[i].chegada <= segundoAtual && (*Processos)[i].tempo > 0){
                // Vejo se o processo já chegou, dps, se ele já não foi completado
                // Vou reduzindo do tempo até chegar em 0, para saber se já foi processado completamente ou não
                if(IDprocessoAtual == -1 || (*Processos)[i].tempo < (*Processos)[IDprocessoAtual].tempo){
                    IDprocessoAtual = i;
                    // Se IDprocessoAtual = -1, é a primeira vez no loop do for i, ai recebe um novo valor
                    // Outro caso é para o loop seguinte, para verificar se o anterior tem tempo menor
                } else if((*Processos)[i].tempo == (*Processos)[IDprocessoAtual].tempo &&
                        (*Processos)[i].chegada < (*Processos)[IDprocessoAtual].chegada){
                    IDprocessoAtual = i;
                }
            }
        }

        // Aumenta o vetor dinamicamente
        QualLetraNoSegundo = realloc(QualLetraNoSegundo, (segundoAtual + 1) * sizeof(char*));
        QualLetraNoSegundo[segundoAtual] = malloc(2 * sizeof(char)); // 1 caractere + \0

        if(IDprocessoAtual != -1){ // Vejo se é o primeiro loop
            QualLetraNoSegundo[segundoAtual][0] = (*Processos)[IDprocessoAtual].letra;
            QualLetraNoSegundo[segundoAtual][1] = '\0';
            (*Processos)[IDprocessoAtual].tempo--;

            // Se terminou o processo
            if((*Processos)[IDprocessoAtual].tempo == 0){
                processosRestantes--;
            }
        }else{
            // Quando não houver nenhum processo sendo executado
            QualLetraNoSegundo[segundoAtual][0] = '-';
            QualLetraNoSegundo[segundoAtual][1] = '\0';
        }

        segundoAtual++;
    }

    // Gera vetor final de letras
    char vetorDeLetras[segundoAtual];
    for (int i = 0; i < segundoAtual; i++){
        vetorDeLetras[i] = QualLetraNoSegundo[i][0];
        free(QualLetraNoSegundo[i]); // libera memória individual
    }
    free(QualLetraNoSegundo); // libera o vetor principal

    ExibeLinhaDoTempo(vetorDeLetras, segundoAtual);
}

/* -------- Round-Robin simples (quantum = 5 s) -------- */
void roundRobin(processo *proc, int qtd, int quantum) {
    int restantes = qtd; // quantos processos ainda não terminaram
    int tempo = 0; 

    int fila[qtd]; // crio uma fila de tamanho fixo, e o tamanho é quantidade de processos, porquê não tem como ser maior
    int validos = 0; // esse aqui vai salvar a quantidade de processos ainda válidos

    // linha do tempo
    char *linhaDotempo = NULL; // armazena letra executada a cada segundo 
    int tlen = 0; // tamanho da linha do tempo


    while(restantes > 0){
        // coloca na fila processos que chegam no instante i
        for (int i = 0; i < qtd; i++)
            if (proc[i].chegada == tempo && proc[i].tempo > 0)
                fila[validos++] = i;

        if (validos == 0){ // se não tiver processos válidos, quer dizer que não tem processo a ser executado naquele momento
            linhaDotempo = realloc(linhaDotempo, tlen + 1);
            linhaDotempo[tlen++] = '-'; 
            tempo++;
            continue;
        }

        // antes de executar, retiro quem vai ser executado no início
        int pid = fila[0];
        for (int i = 1; i < validos; i++) // desloco os outros pra esquerda
            fila[i - 1] = fila[i];
        validos--;

        // executo até quantum segundos ou até não ter mais segundos restantes
        int slice = (proc[pid].tempo < quantum) ? proc[pid].tempo : quantum;

        for(int s = 0; s < slice; s++){
            linhaDotempo = realloc(linhaDotempo, tlen + 1);
            linhaDotempo[tlen++] = proc[pid].letra;

            proc[pid].tempo--;
            tempo++;

            // se durante algum quantum um processo chegar, ele já entra na fila
            for (int i = 0; i < qtd; i++)
                if (proc[i].chegada == tempo && proc[i].tempo > 0)
                    fila[validos++] = i;

            if (proc[pid].tempo == 0) { restantes--; break; }
        }

        // se tiver tempo restante ainda, volta pro início da fila
        if (proc[pid].tempo > 0)
            fila[validos++] = pid;
        }

    // por fim, exibo a linha do tempo
    ExibeLinhaDoTempo(linhaDotempo, tlen); 
    free(linhaDotempo);
}


int main(){
    processo *Processos = NULL; // Não atribuimos nd para allocar apenas o que for necessário dps
    int qtd_processos = 0;

    LeArquivo("../entrada.txt", &Processos, &qtd_processos);

    int escolha = 0;

    printf("\n\n----------> Menu <----------\n");
    printf("Escolha uma opção:\n\n");
    printf("1 - Visualizar os processos lidos\n2 - Escalonador SJF Preemptivo\n3 - Escalonador Round-Robin");
    printf("\n\nEscolha: ");
    scanf("%i", &escolha);

    if(escolha == 1){
        printf("Processos lidos:\n");
        for (int i = 0; i < qtd_processos; i++) {
            printf("Letra: %c, Tempo: %d, Chegada: %d\n",
            Processos[i].letra, Processos[i].tempo, Processos[i].chegada);
        }
        printf("\n\nObservação: Se não saiu como esperado, siga o modelo de txt abaixo:\n");
        printf("Processo A B C D E\nTempo 1 2 3 4 5\nChegada 0 2 4 6 8\n");
    }else if(escolha == 2){
        sjfPreemptivo(&Processos, &qtd_processos);
    }else if(escolha == 3){
        roundRobin(Processos, qtd_processos, 5);
    }else{
        printf("\nEscolha inválida!\n");
    }

    free(Processos);

    return 0;
}
