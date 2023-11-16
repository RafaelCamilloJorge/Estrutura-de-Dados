#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_DICIONARIO 26

typedef struct trie{
    struct trie* filhos[TAM_DICIONARIO];
    int fimDePalavra;
}Trie;


Trie *criaTrie(){
    Trie *No = malloc(sizeof(Trie));

    for(int i = 0; i < TAM_DICIONARIO; i++){
        No->filhos[i] = NULL;
    }
    No->fimDePalavra = 0;
    return No;
}

void insere(Trie *raiz, char *chave){
    int tamanho = strlen(chave);
    int index;
    Trie *aux = raiz;

    for(int i = 0; i < tamanho; i++){
        index = (int)chave[i] - (int)'a';
        if(!aux->filhos[index]){
            aux->filhos[index] = criaTrie();
        }
        aux = aux->filhos[index];
    }

    aux->fimDePalavra = 1;

}

int busca(Trie *raiz, char *chave){
    int tamanho = strlen(chave);
    int index;
    Trie *aux = raiz;

    for(int i = 0; i < tamanho; i++){
        index = (int)chave[i] - (int)'a';
        if(!aux->filhos[index]){
            return 0;
        }else{
            aux = aux->filhos[index];
        }
    }

    if(aux->fimDePalavra = 1){
        return 1;
    }
}


int main(){
    Trie *raiz = criaTrie();

    insere(raiz, "teste");
    printf("verificando se existe...\n");
    printf("verificando se existe...\n");
    printf("verificando se existe...\n");
    printf("1 - sim, 0 - não\n%d", busca(raiz, "teste"));

    
}
