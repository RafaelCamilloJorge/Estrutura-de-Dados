#include <stdio.h>
#define max 2

struct aluno {
  int ra, falta;
  float p, e;
};

void bolha_crescente(struct aluno a[]) {
  int i, houve_troca = 1;
  struct aluno aux;
    printf("\n CODIGO CRESCENTE \n");
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < max - 1; i++) {
      if (a[i].ra > a[i + 1].ra) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }

}

void bolha_decrescente(struct aluno a[]) {
  int i, houve_troca = 1;
  struct aluno aux;
  printf("\n CODIGO DECRESCENTE \n");
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < max - 1; i++) {
      if (a[i].ra < a[i + 1].ra) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  } 
}

int busca(int codigo, int tamanho, struct aluno a[]) {
  int meio, inf, sup;
  float media;
  inf = 0;
  sup = tamanho - 1;
  meio = (inf + sup) / 2;
  while (inf <= sup) {
    if (a[meio].ra == codigo) {
      printf("\n**ALUNO ENCONTRADO!!**\n");
      float media;
      media = (a[meio].p + a[meio].e) / 2;
      printf("\nCodigo do aluno  Faltas  Parcial Exame  Media ");
      printf(" \n   %d             %d      %.2f  %.2f   %.2f\n", a[meio].ra,
             a[meio].falta, a[meio].p, a[meio].e, media);
      return meio;
    } else if (codigo > a[meio].ra)
      inf = meio + 1;
    else
      sup = meio - 1;
    meio = (inf + sup) / 2;
  }

  if (inf > sup)
    meio = -1;
  return meio;
}

void mostrar_crescente(struct aluno alunos[]){
  printf("Codigo do aluno  Faltas  Parcial Exame  Media ");

  for (int i = 0; i < max; i++) {
    float media;
    media = (alunos[i].p + alunos[i].e) / 2;
    printf(" \n   %d                %d      %.2f    %.2f    %.2f\n", alunos[i].ra,
           alunos[i].falta, alunos[i].p, alunos[i].e, media);
  }
}

void mostrar_descrecente(struct aluno alunos[]){
  float media;
    for (int i = 0; i < max; i++) {
    media = (alunos[i].p + alunos[i].e) / 2;
    printf(" \n   %d             %d      %.2f  %.2f   %.2f\n", alunos[i].ra,
           alunos[i].falta, alunos[i].p, alunos[i].e, media);
  }
}

int main() {

  int codigo;
  struct aluno alunos[max];


  for(int i = 0 ; i< max; i++){
  printf("digite o código do aluno \n");
  scanf("%i", &alunos[i].ra);
  printf("digite a falta do aluno: \n");
  scanf("%i", &alunos[i].falta);
  printf("digite o p do aluno: \n");
  scanf("%f", &alunos[i].p);
  printf("digite o e do aluno \n");
  scanf("%f", &alunos[i].e);
}


  
  bolha_crescente(alunos);
  mostrar_crescente(alunos);


  bolha_decrescente(alunos);
  mostrar_descrecente(alunos);


  printf("Digite o codigo do aluno a ser procurado  ");
  scanf("%d", &codigo);
  bolha_crescente(alunos);
  busca(codigo, max, alunos);

}
