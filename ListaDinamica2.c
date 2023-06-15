#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int elemento;
    struct No *prox;
}no;


void insere_inicio(no **lista, int valor){
    no *novo = malloc(sizeof(no));
    novo->elemento = valor;
    novo->prox = *lista;
    *lista = novo;
}

void imprimi(no *lista){
    no *aux = lista;
    while(aux != NULL){
        printf(" %d ", aux->elemento);
        aux = aux->prox;
    }
}

void remover_fim(no **lista){
    no *aux = *lista;
    no *anterior = NULL;

    while(aux->prox != NULL){
        anterior = aux;
        aux = aux->prox;
    }

    anterior->prox = NULL;
    
}

void inverte(no **lista){
    no *atual = *lista;
    no *proximo, *anterior = NULL;

    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior;
}

float media(no **lista){
    no *aux = *lista;
    int contador = 0;
    while(aux != NULL){
        aux = aux->prox;
        contador++;
    }
    aux = *lista;
    float soma;
    while(aux != NULL){
        soma += aux->elemento;
        aux = aux->prox;
    }
    soma = soma/contador;
    return soma;

}


void insere_fim(no **lista, int valor){
    no *aux = *lista;
    no *novo = malloc(sizeof(no));
    novo->elemento = valor;
    novo->prox = NULL;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;
}

void insere_meio(no **lista, int valor){
    no *novo = malloc(sizeof(no));
    no *aux = *lista;
    int contador = 0;
    novo->elemento = valor;
    while(aux != NULL){
        contador++;
        aux = aux->prox;      
    }
    aux = *lista;

    for(int i = 1; i < contador/2; i++){
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;



    
}


int main(){
    no *lista = NULL;
    insere_inicio(&lista, 10);
    insere_inicio(&lista, 8);
    insere_fim(&lista, 3.2);
    insere_meio(&lista, 2);
    imprimi(lista);

}