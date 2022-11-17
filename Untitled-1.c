#include <stdio.h>
#define N 2

typedef struct salas{
    int id;
    int idade;
    char nome[10];
    int nota1, nota2;
}Salas; 


int main(){
    Salas aluno[N];

    for (int i = 0; i < N; i++)
    {
        printf("Digite o ID do aluno: ");
        scanf("%d", &aluno[i].id);
        printf("Digite o NOME do aluno: ");
        scanf("%s", &aluno[i].nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &aluno[i].idade);
        printf("Digite a NOTA 1 do aluno: ");
        scanf("%d", &aluno[i].nota1);
        printf("Digite o Nota2 do aluno: ");
        scanf("%d", &aluno[i].nota2);
    }

    printf("ID   NOME   IDADE   NOTA 1   NOTA 2\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d   ", aluno[i].id);
        printf("%s   ", aluno[i].nome);
        printf("%d   ", aluno[i].idade);
        printf("%d   ", aluno[i].nota1);
        printf("%d   \n", aluno[i].nota2);
    }
    
    

}

//NAO COLOCAR /n no final dos scanf pq buga o codigo