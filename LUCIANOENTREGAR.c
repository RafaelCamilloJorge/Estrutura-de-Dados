#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
int codigo; // campo 1
float custo, venda, impostos, margem; // campos 2, 3, 4 e 5 respectivamente

} produto;

void limpa_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=0;
        p[i].custo=p[i].venda=p[i].margem=0;
        p[i].impostos=i%2==0?.18:.15;
    }
}

float gera_custo (){ // gera custos de até 3000.00
    int d1=rand()%3001;
    int d2 = rand()%701;
    return (float) d1/d2;
}
float gera_margem (){// gera margem de até 25%
     int val = rand()%26;
    return (float)val/100.0;
}

void gera_dados(produto *p){
    for (int i =0 ; i < MAX; i++){
        p[i].codigo=i + 1000;
        p[i].margem=gera_margem();
        p[i].impostos=i%2==0?.18:.15;
        p[i].custo=gera_custo();
        p[i].venda= p[i].custo +  p[i].impostos*p[i].custo + p[i].margem*p[i].custo;
    }
}

void imprime (produto *p){
printf ("CODIGO \t\tCUSTO \t\tVENDA \t\tIMPOSTOS \tMARGEM\n");
printf ("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for (int i =0 ; i < MAX; i++)
        printf ("%d \t\t%4.2f \t\t%4.2f \t\t%.2f \t\t%.2f\n",
               p[i].codigo, p[i].custo, p[i].venda, p[i].impostos, p[i].margem );


}

void ordena(struct node a[], int n) {
    if(n == 3){
  int i, houve_troca = 1;
  struct node aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < MAX - 1; i++) {
      if (a[i].venda > a[i + 1].venda) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }
    }

  if(n == 2){
      int i, houve_troca = 1;
        struct node aux;
      while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < MAX - 1; i++) {
      if (a[i].custo < a[i + 1].custo) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }
  }

}

void ordena1(struct node a[]) {
  int i, houve_troca = 1;
  struct node aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < MAX - 1; i++) {
      if (a[i].codigo > a[i + 1].codigo) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }
    }

int busca(int codigo, struct node a[], int inf, int sup) {
    
  int meio;
  meio = (inf + sup) / 2;
  while (inf <= sup) {
    if (a[meio].codigo == codigo) {
      return meio;
    } else if (codigo > a[meio].codigo)
      inf = meio + 1;
    else
      sup = meio - 1;
    meio = (inf + sup) / 2;
  }

  if (inf > sup)
    meio = -1;
  return meio;
}

int main (){
srand(time(NULL));
produto produtos[MAX];
limpa_dados(produtos);
gera_dados(produtos);
imprime(produtos);
ordena(produtos, 3); // aplique bubble sort neste campo 3 ascedente
imprime(produtos);
ordena(produtos, 2); // aplique bubble sort neste campo 3 ascedente
imprime(produtos);
ordena1(produtos);
int b = busca(1015,produtos,0,MAX); // implementar
if (b!=-1)
    printf ("\nProduto %d encontrado:\nCusto: %.2f\nVenda: %.2f\nTaxas + Imp: %.2f%%\n",
        produtos[b].codigo, produtos[b].custo, produtos[b].venda, (produtos[b].impostos + produtos[b].margem)*100 );
    else
        printf ("\nProduto nao encontrado\n");

}