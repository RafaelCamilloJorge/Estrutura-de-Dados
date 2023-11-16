#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct no
{
    struct no *proximo;
    int chave;
} No;

typedef struct lista
{
    No *Inicio;
} Lista;

void inicializaLista(Lista *l)
{
    l->Inicio = NULL;
}

void inserirLista(Lista *l, int valor)
{
    No *novo = malloc(sizeof(No));

    novo->chave = valor;
    novo->proximo = l->Inicio;
    l->Inicio = novo;
}

No *busca(Lista *l, int valor)
{
    No *aux = l->Inicio;

    while (aux)
    {
        if (aux->chave == valor)
            return aux;
        else
            aux = aux->proximo;
        
    }

    return 0;
}

void imprimir(Lista *l){
    No *aux = l->Inicio;

    while(aux){
        printf("%d,", aux->chave);
        aux = aux->proximo;
    }
}



/*------------ T A B E L A ------------*/

int funcaoHash(int valor){
    return valor % TAM;
}


void incializaTabela(Lista *t[]){
    for (int i = 0; i < TAM; i++)
    {
        inicializaLista(&t[i]);
    }
    
}

void inserirTabela(Lista *t[], int valor){
    int id = funcaoHash(valor);

    inserirLista(&t[id], valor);
}

int buscaTabela(Lista *t[], int valor){
    int id = funcaoHash(valor);
    printf("\nIndice Gerado: %d\n", id);
    if(busca(&t[id], valor)){
        printf("%d valor encontrado\n", valor);
        return 1;
    }
    else{
        printf("\nValor Não Encontrado");
    }
}

void imprimirTabela(Lista t[]){
    for(int i = 0; i < TAM; i++){
        printf("%d: ", i);
        imprimir(&t[i]);
        printf("\n");
    }
}





int main()
{
    int opcao, valor;
    Lista *tabela[TAM];
    incializaTabela(tabela);

    do{
        printf("Escolha uma opcao\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: 
            
            printf("Inserir\n");
            printf("Qual valor deseja inserir ");
            scanf("%d", &valor);
            inserirTabela(&tabela, valor);
            break;

        case 2:
            
            printf("Buscar\n");
            printf("Qual valor deseja Buscar ");
            scanf("%d", &valor);
            buscaTabela(&tabela, valor);
            break;

        case 3:
            
            printf("Imprimir\n");
            imprimirTabela(&tabela);
            break;
        }


    }while(opcao != 4);
}