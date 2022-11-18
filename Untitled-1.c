#include <stdio.h>
#define max 2
typedef struct alunos
{
    char nome[10];
    int nota1;
}Alunos;

void bolha_crescente(struct alunos a[]){
  int i, houve_troca = 1;
  struct alunos aux;
    printf("\n CODIGO CRESCENTE \n");
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < max - 1; i++) {
      if (a[i].nota1 > a[i + 1].nota1) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }
  }  
}

void mostrar_crescente(struct alunos a[]){
     for (int i = 0; i < max; i++)
  {
    printf("%s ", a[i].nome);
    printf("%d", a[i].nota1);
    printf("\n");
  }
}


int busca(int n, int nmax, int nmin){
    int item;

    int v[5] = {1,2,3,4,5};

    scanf("%d", &item);

    if (n <= nmax)
    {
        int meio = (nmax + nmin) / 2;
        if(item == v[meio]){
            return meio;
        }
        if(item > v[meio]){
            nmin = meio + 1;
            meio = (nmax + nmin) / 2;
        }
        if (item < v[meio])
        {
            nmax = meio - 1;
            meio = (nmax + nmin) / 2;
        }
        if(nmax < nmin) {
            return -1;
        }
        
        busca(n + 1, nmax, nmin);
    }
    
}

int main(){
    int N = 2;
    Alunos al[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", &al[i].nome);
        scanf("%d", &al[i].nota1);
    }
    bolha_crescente(al);
    printf("\n");
    mostrar_crescente(al);

    printf("%d", busca(0, 5, 0));
    

}

//NAO COLOCAR /n no final dos scanf pq buga o codigo