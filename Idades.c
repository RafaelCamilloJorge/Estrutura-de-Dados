#include <stdio.h>


typedef struct teste
{
    char nome[10];
    int idade;
}Teste;

void ordem(struct teste a[], int N){
    int houve_troca = 1;
    struct teste aux;
    while (houve_troca)
    {
        for (int i = 0; i < N; i++)
        {
            houve_troca = 0;
            if (a[i].idade > a[i + 1].idade)
            {
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                houve_troca = 1;
            }
        }
    
    }
}

void mostrar_crescente(struct teste pessoa[], int N){

    printf("\n\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nome : %s\n", pessoa[i].nome);
        printf("idade : %d\n", pessoa[i].idade);
        printf("****************************\n");
    }
}


int main(){
    int N = 3;
    Teste pessoa[N];

    for (int i = 0; i < N; i++)
    {
        printf("Digite o nome: ");
        scanf("%s", &pessoa[i].nome);
        printf("Digite o idade: ");
        scanf("%d", &pessoa[i].idade);
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nome : %s\n", pessoa[i].nome);
        printf("idade : %d\n", pessoa[i].idade);
        printf("****************************\n");
    }

    ordem(pessoa, N);
    mostrar_crescente(pessoa, N);
    
    
}