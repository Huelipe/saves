#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo uma nó de lista simplesmente encadeada
typedef struct no_simples no_simples;
struct no_simples{
    int idade;
    char nome[30];
    no_simples *prox;
};

// lista
typedef struct lista lista;
struct lista{
    int tamanho;
    no_simples *primeiro;
    no_simples *ultimo;
};

void adiciona_elemento(int idade, char nome[], lista *p){
    no_simples *novo = (no_simples *) malloc(sizeof(no_simples));

    if (novo == NULL){
        return;
    }
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (p->tamanho == 0){
        p->primeiro = novo;
        p->ultimo = novo;
    }
    else{
        p->ultimo->prox = novo;
        p->ultimo = novo;
    }
    p->tamanho++;
}

// nesta função serão impressas apenas as idades por simplicidade.
void imprime_lista(lista *p){
    printf("\n lista: ");
    for(no_simples *x=p->primeiro; x != NULL; x = x->prox){
        //printf("nome: %s, idade: %d\n", x->nome, x->idade);
        printf("%d ", x->idade);
    }
}

void bubble_sort(lista *p){

    // anterior aponta para x, que aponta para y
    no_simples *x, *y, *ant;

    // repete n-1 vezes
    for (int i=0; i<p->tamanho-1; i++)
    {
        // x itera sobre os elementos da lista
        x=p->primeiro;
        while(x->prox != NULL){

            // se a diade do nó x for maior do que a do próximo, troca
            if(x->idade > x->prox->idade){
                y = x->prox;                // y é o próximo elemento
                x->prox = y->prox;          // atualiza o próximo do x
                y->prox = x;                // atualiza o próximo do y
                if (x == p->primeiro){      // se x era primeiro, atualiza o primeiro
                    p->primeiro = y;
                }
                else{                       // senão atualiza o próximo do nó anterior ao x
                    ant->prox = y;
                }
                if (p->ultimo == y){        // se y era último, atualiza o último
                    p->ultimo = x;
                }
                ant = y;                    // se trocou, x continua x, mas y é o anterior agora
            }
            // se não trocou, atualiza anterior e atualiza x
            else{
                ant = x;
                x = x->prox;
            }
        }
        // imprime a lista a cada iteração para mostrar o desenrolar do algoritmo
        imprime_lista(p);
    }
}

void insertion_sort(lista *p, lista *q){

    // x itera sobre todos os elementos da lista p
    for(no_simples *x=p->primeiro; x != NULL; x = x->prox){

    // para cada nó, cria um novo nó com as mesmas informações.
        no_simples *novo = (no_simples *) malloc(sizeof(no_simples));

        if (novo == NULL){
            return;
        }
        novo->idade = x->idade;
        strcpy(novo->nome, x->nome);
        novo->prox = NULL;
        // se a lista 'q' estiver vazia, insere o novo elemento.
        if (q->tamanho == 0){
            q->primeiro = novo;
            q->ultimo = novo;
        }

        //caso não esteja vazia, testa se deve inserir na primeira posição
        else if(x->idade < q->primeiro->idade){
            novo->prox = q->primeiro;
            q->primeiro = novo;
        }
        // se não está vazia e não vai inserir na primeira posição, 
        // encontra a posição para inserir:
        else{
            // y vai iterar sobre os elementos da lista 'q'
            no_simples *y=q->primeiro;

            // enquanto y tiver um próximo elemento, e o próximo for menor que a idade do novo nó,
            // continua iterando.
            while(y->prox!=NULL && y->prox->idade < novo->idade){
                y = y->prox;
            }
            // depois que terminar de iterar, insere no novo nó atualizando os ponteiros
            novo->prox = y->prox;   
            y->prox = novo;         
        }
        // se novo nó é o último, atualiza o ponteiro:
        if (novo->prox == NULL){
            q->ultimo = novo;
        }
        q->tamanho++;
    }

}

int main(){
    FILE *arq;

    // tenta abrir e avisa caso não conseguir
    arq = fopen("../perc_cat.csv", "r");
    if(arq == NULL){
        printf("Não foi possível abrir\n");
        return 0;
    }

    // le primeira linha
    char lixo[100];
    fscanf(arq, "%[^\n]\n", lixo);
    printf("descartando: %s\n", lixo);
  
    // le próximas linhas
    char estado[50], capital[50];
    double perc;
    while (fscanf(arq, "%[^ ;] ;%[^;];%lf\n", estado, capital, &perc) > 0){
        printf("est: %s, cap: %s, cat: %.1f\n", estado, capital, perc);
    }

    // fecha o arquivo
    fclose(arq);

    int opcao;

    while(1 == 1){
        printf("\n\n==================== Menu ====================\n");
        printf("Escolha uma opção:\n");
        printf("1 - Mudar ordem de nós da lista\n");
        printf("2 - Exibir lista\n");
        printf("3 - Pesquisar ou mudar percentual de um estado\n");
        printf("4 - Fechar programa\n");
        printf("==============================================\n\n");

        scanf("%i", &opcao);

        switch (opcao){
        case 1:
            //funcao 1
            break;
        case 2:
            //funcao 2
            break;
        case 3:
            //funcao 3
            break;
        case 4:
            printf("Finalizando o programa...\n");
            return 0;
        default:
            printf("Opção não encontrada!\n");
            break;
        }

    }

    printf("\nfim\n");
    return 0;
}
