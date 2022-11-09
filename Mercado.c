#include <stdio.h>
#include <stdlib.h>
#define N 5


typedef struct mercado{
    int codigo;
    char nome[15];
    float preco;
    int quantidade;
}Mercado;

void bolha_crescenteID(struct mercado a[]) {
  int i, houve_troca = 1;
  struct mercado aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < N - 1; i++) {
      if (a[i].codigo > a[i + 1].codigo) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }

}

void MostraCrescente(struct mercado produto[]){
    for (int i = 0; i < N; i++)
    {
        printf("\n\nCodigo => %d\n", produto[i].codigo);
        printf("Nome => %s\n", produto[i].nome);
        printf("Preco => %.2f\n",produto[i].preco);
        printf("Quantidade => %d\n\n\n",produto[i].quantidade); 
    }
    
}

void bolha_crescentePRECO(struct mercado a[]){
int i, houve_troca = 1;
  struct mercado aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < N - 1; i++) {
      if (a[i].preco > a[i + 1].preco) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }
}




int main(){
    Mercado produto[N];
    int escolha;
    

    for(int i=0; i < N; i++){
        printf("Digite o codigo do produto: ");
        scanf("%d", &produto[i].codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", &produto[i].nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &produto[i].preco);
        printf("Digite o quantidade: ");
        scanf("%d\n\n", &produto[i].quantidade);
    }
    system("cls");
    for(int i=0; i < N; i++){
        printf("\n\nCodigo => %d\n", produto[i].codigo);
        printf("Nome => %s\n", produto[i].nome);
        printf("Preco => %.2f\n",produto[i].preco);
        printf("Quantidade => %d\n\n\n",produto[i].quantidade);
    }

    printf("\n******************************************\n");
    printf(" 1 => Ordenar por ID, 2 => Ordenar por valor");
    scanf("%d",&escolha);

    if (escolha == 1)
    {
        bolha_crescenteID(produto);
        MostraCrescente(produto);
    }
    else if (escolha == 2)
    {
        bolha_crescentePRECO(produto);
        MostraCrescente(produto);
    }

}

//TESTE
//101 bone 100 10 102 Caixa 100 2 302 Blusa 200 9 104 Livro 78 10 109 Caneta 7 100 
//TESTE