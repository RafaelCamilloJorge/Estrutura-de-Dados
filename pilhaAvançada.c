#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int inverte(int pilha[], int topo, int pilha2[]) {
    int topo2 = -1;

    for(int i = 0; i <= topo; i++) {
        topo2++;
        pilha2[topo2] = pilha[topo-i];
        printf("[%d] : [%d]\n", topo2, pilha2[topo2]); //printando a pilha 1, a pilha 2 invertida está no int main
    }

    return topo2;
}

int push(int pilha[], int elemento, int topo) {
    if(topo < MAX - 1) {
        topo++;
        pilha[topo] = elemento;
        printf("Elemento [%d]: %d inserido com sucesso!\n", topo, elemento);
        system("pause");
    }
    else {
        system("cls");
        printf("STACK ERROR\n");
        system("pause");
    }
    return topo;
}

int pop(int pilha[], int topo) {
    if(topo > -1) {
        printf("\n%d foi o Elemento Removido\n\n", pilha[topo]);
        topo--;
        system("pause");
    }
    else {
        printf("\nPilha vazia. Insira algum elemento antes...\n");
        system("pause");
    }
    return topo;
}

void show(int pilhaPrincipal[], int topo) {
    if(topo > -1) {
    for(int i = 0; i <= topo; i++) {
        printf("\n[%d]: %d\n", i, pilhaPrincipal[i]);
    }
    }
    
    else {
        printf("\nPilha vazia. Insira algum elemento antes...\n\n");
    }
}

int main() {
    int pilha[MAX];
    int topo = -1;
    int elemento;
    int escolha = 0;
    int pilha2[MAX];
    int principal = 1;

    while(escolha != 5) {
        system("cls");
        if(principal == 1){
            printf("P I L H A [1]\n\n");
        }
        else if(principal == 2){
            printf("P I L H A [2]\n\n");
        }
        printf("1 - PUSH\n");
        printf("2 - POP\n");
        printf("3 - SHOW\n");
        printf("4 - REVERSE\n");
        printf("5 - EXIT\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                system("cls");
                printf("PUSH\n");
                printf("\nDigite seu número: ");
                scanf("%d", &elemento);
                if(principal == 1){
                    printf("PILHA 1\n");
                    topo = push(pilha, elemento, topo);
                }
                else if(principal == 2){
                    printf("PILHA 2\n");
                    topo = push(pilha2, elemento, topo);
                }
                break;

            case 2:
                system("cls");
                printf("POP\n");
                if(principal == 1){
                    printf("PILHA 1\n");
                    topo = pop(pilha, topo);
                }
                else if(principal == 2){
                    printf("PILHA 2\n");
                    topo = pop(pilha2, topo);
                }
                break;

            case 3:
                if(principal == 1){
                    printf("PILHA 1\n");
                    show(pilha, topo);
                    system("pause");
                }
                else if(principal == 2){
                    printf("PILHA 2\n");
                    show(pilha2, topo);
                    system("pause");
                }
                break;

            case 4:
                system("cls");
                printf("REVERSE\n");
                if(principal == 2){
                    printf("PILHA 1\n");
                    int tamanho_pilha = inverte(pilha2, topo, pilha);
                    printf("Pilha invertida: ");
                    for(int i = 0; i <= tamanho_pilha; i++) {
                        printf("%d ", pilha[i]);
                    }
                    printf("\n");
                    principal = 1;
                    system("pause");
                }

                else if(principal == 1){
                    printf("PILHA 1\n");
                    int topo2 = inverte(pilha, topo, pilha2);
                    printf("Pilha invertida: ");
                    for(int i = 0; i <= topo2; i++) {
                        printf("%d ", pilha2[i]);
                    }
                    printf("\n");
                    principal = 2;
                    system("pause");

                    }

                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
}
