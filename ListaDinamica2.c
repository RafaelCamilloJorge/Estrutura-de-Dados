#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
    struct no* anterior;
} No;

void inserir_em_ordem_decrescente(No** cabeca, No** fim, int novo_valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = novo_valor;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (*cabeca == NULL) { // Se a lista estiver vazia
        *cabeca = novo;
        *fim = novo;
        return;
    }

    if (novo_valor >= (*cabeca)->valor) { // Inserir no início da lista
        novo->proximo = *cabeca;
        (*cabeca)->anterior = novo;
        *cabeca = novo;
        return;
    }

    if (novo_valor <= (*fim)->valor) { // Inserir no final da lista
        (*fim)->proximo = novo;
        novo->anterior = *fim;
        *fim = novo;
        return;
    }

    No* atual = (*cabeca)->proximo;
    while (atual != NULL && novo_valor < atual->valor) {
        atual = atual->proximo;
    }

    // Inserir no meio da lista
    novo->proximo = atual;
    novo->anterior = atual->anterior;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
}

void imprimir_lista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    No* cabeca = NULL;
    No* fim = NULL;

    // Inserção de alguns elementos na lista
    inserir_em_ordem_decrescente(&cabeca, &fim, 5);
    inserir_em_ordem_decrescente(&cabeca, &fim, 10);
    inserir_em_ordem_decrescente(&cabeca, &fim, 3);
    inserir_em_ordem_decrescente(&cabeca, &fim, 8);

    // Imprimir a lista
    printf("Lista: ");
    imprimir_lista(cabeca);

    return 0;
}
