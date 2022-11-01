#include <stdio.h>

typedef struct alunos
{
    int matricula;
    char nome[10];
    float prova1, prova2, prova3;
}Alunos;

void bolha_crescente(struct alunos a[]) {
  int i, houve_troca = 1;
  struct alunos aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < 3 - 1; i++) {
      if (a[i].matricula > a[i + 1].matricula) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }

}

int busca(int codigo, int tamanho, Alunos a[]) {
  int meio, inf, sup;
  inf = 0;
  sup = tamanho - 1;
  meio = (inf + sup) / 2;
  float media;
  while (inf <= sup) {
    if (a[meio].matricula == codigo) {
      printf("\n**ALUNO ENCONTRADO!!**\n");
      media = (a[meio].prova1 + a[meio].prova2 + a[meio].prova3) / 3;
      printf("Matricula   Nome    Prova 1    Prova 2    Prova 3   Media");
      printf(" \n   %d       %s      %.2f      %.2f   %.2f     %.2f\n", a[meio].matricula,
             a[meio].nome, a[meio].prova1, a[meio].prova2, a[meio].prova3, media);
      return meio;
    } else if (codigo > a[meio].matricula)
      inf = meio + 1;
    else
      sup = meio - 1;
    meio = (inf + sup) / 2;
  }

  if (inf > sup)
    meio = -1;
  return meio;
}






int main() {
    int i=0;
    int N = 3;
    float media;
    int codigo;
    Alunos al[N];

    for(i=0;i<N;i++)
    {
        printf("Informe a Matricula: ");
        scanf("%d",&al[i].matricula);
        printf("Informe a Nome: ");
        scanf("%s",&al[i].nome);
        printf("Informe a Prova 1: ");
        scanf("%f",&al[i].prova1);
        printf("Informe a Prova 2: ");
        scanf("%f",&al[i].prova2);
        printf("Informe a Prova 3: ");
        scanf("%f",&al[i].prova3);
    }

    bolha_crescente(al);

    printf("Matricula   Nome    Prova 1    Prova 2    Prova 3   Media");

    for (i = 0; i < N; i++)
    {
        printf("\n%d  ", al[i].matricula);
        printf("\t   %s  ", al[i].nome);
        printf(" %.2f  ", al[i].prova1);
        printf("     %.2f  ", al[i].prova2);
        printf("\t   %.2f  ", al[i].prova3);
        printf("  %.2f\n\n", (al[i].prova1 + al[i].prova2 + al[i].prova3) / 3);
        
    }
    scanf("%d", &codigo);

    printf("Codigo Da Matricula: ");
    busca(codigo, N, al);
    
}

//101 Rafael 10 9.8 7.3 102 Joao 10 9 7.5 103 Renan 9 10 10 