#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int elemento;
    struct No *prox;
} no;

void insere_inicio(no **lista, int valor){
    no *novo = malloc(sizeof(no));
    novo->elemento = valor;
    novo->prox = *lista;
    *lista = novo;
}

void insere_fim(no **lista, int valor){
    no *novo = malloc(sizeof(no));
    novo->elemento = valor;
    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo;
        return;
    }

    no *aux = *lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
}

void imprimir(no *lista){
    no *aux = lista;
    while(aux != NULL){
        printf("%d ", aux->elemento);
        aux = aux->prox;
    }
}

void deleta_inicio(no **lista){
    if(*lista == NULL){
        printf("Lista vazia.\n");
        return;
    }

    no *aux = *lista;
    *lista = aux->prox;
    free(aux);
}

void busca_elemento(no **lista, int valor){
    int indice = 1;
    no *aux = *lista;
    
    while(aux != NULL){
        if(aux->elemento == valor){
            printf("\n\nACHEI");
            printf(" - No indice: %d", indice);
            return;
        }
        aux = aux->prox;
        indice++;
    }

    printf("\nACHEI N CARINHA");
}

void deleta_fim(no **lista){
    if(*lista == NULL){
        printf("Lista vazia.\n");
        return;
    }

    no *atual = *lista;
    no *anterior = NULL;

    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        *lista = NULL;
    } else {
        anterior->prox = NULL;
    }
    free(atual);
}

void deleta_elemento(no **lista, int valor){
    if(*lista == NULL){
        printf("Lista vazia.\n");
        return;
    }

    no *atual = *lista;
    no *anterior = NULL;

    if(atual->elemento == valor){
        *lista = atual->prox;
        free(atual);
        return;
    }

    while(atual != NULL && atual->elemento != valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Elemento %d nao encontrado na lista.\n", valor);
    } else {
        anterior->prox = atual->prox;
        free(atual);
    }
}

void crescente(no **lista, int valor){
    no *novo = malloc(sizeof(no));
    novo->elemento = valor;
    novo->prox = NULL;

    if(*lista == NULL){
        *lista = novo;
        return;
    }

    no *atual = *lista;
    no *anterior = NULL;

    while(atual != NULL && atual->elemento < valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        novo->prox = *lista;
        *lista = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }
}

void removeDuplicates(no **lista) {
    if (*lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    no *atual = *lista;
    while (atual != NULL && atual->prox != NULL) {
        no *aux = atual;
        while (aux->prox != NULL) {
            if (aux->prox->elemento == atual->elemento) {
                no *temp = aux->prox;
                aux->prox = aux->prox->prox;
                free(temp);
            } else {
                aux = aux->prox;
            }
        }
        atual = atual->prox;
    }
}


void inverter_lista(no **lista) {
    no *anterior = NULL;
    no *atual = *lista;
    no *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior;
}

no* fundir_listas_ordenadas(no* lista1, no* lista2) {
    if (lista1 == NULL) {
        return lista2;
    }
    if (lista2 == NULL) {
        return lista1;
    }

    no* cabeca = NULL;
    no* atual = NULL;

    if (lista1->elemento <= lista2->elemento) {
        cabeca = lista1;
        atual = lista1;
        lista1 = lista1->prox;
    } else {
        cabeca = lista2;
        atual = lista2;
        lista2 = lista2->prox;
    }

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->elemento <= lista2->elemento) {
            atual->prox = lista1;
            atual = lista1;
            lista1 = lista1->prox;
        } else {
            atual->prox = lista2;
            atual = lista2;
            lista2 = lista2->prox;
        }
    }

    if (lista1 == NULL) {
        atual->prox = lista2;
    } else {
        atual->prox = lista1;
    }

    return cabeca;
}

int main(){
    no *lista = NULL;
    no *lista2 = NULL;

    insere_inicio(&lista, 1);
    insere_inicio(&lista, 2);
    insere_inicio(&lista, 3);
    insere_inicio(&lista, 8);
    insere_inicio(&lista, 0);
    insere_inicio(&lista, 1900);
    deleta_inicio(&lista);
    imprimir(lista);

    busca_elemento(&lista, 2);
    deleta_elemento(&lista, 2);
    deleta_elemento(&lista, 1);
    deleta_elemento(&lista, 3);
    deleta_elemento(&lista, 2);
    deleta_fim(&lista);

    insere_fim(&lista2, 1);
    insere_fim(&lista2, 2);
    insere_fim(&lista2, 8);
    crescente(&lista2, 3);
    insere_fim(&lista2, 8);
    insere_fim(&lista2, 8);

    removeDuplicates(&lista2);


    printf("\n");
    imprimir(lista2);


    printf("\nINVERTIDA : ");
    inverter_lista(&lista2);

    imprimir(lista2);


    no *listaFundida = fundir_listas_ordenadas(lista, lista2);


    printf("\n LISTA FUNDIDA: ");
    printf("%d", listaFundida);



    


    return 0;
}
