#include <stdio.h>

typedef struct carro{
    char marca[32];
    int ano;
    float preco;
}Carro;


void bolha_crescente(struct carro a[]) {
  int i, houve_troca = 1;
  struct carro aux;
  while (houve_troca) {
    houve_troca = 0;
    for (i = 0; i < 3 - 1; i++) {
      if (a[i].preco > a[i + 1].preco) {
        aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
        houve_troca = 1;
      }
    }

  }

}

void mostrar_crescente(struct carro car[]){

  for (int i = 0; i < 3; i++) {
        printf("\nMarca: %s\n", car[i].marca);
        printf("Ano: %d\n", car[i].ano);
        printf("Preco: R$ %.2f\n", car[i].preco);
  }
}


int main() {
    int N = 3, i;
    Carro car[N];
    float p;

    for (i = 0; i < N; i++)
    {
        printf("Marca: ");
        scanf("%s", &car[i].marca);
        printf("Ano: ");
        scanf("%d", &car[i].ano);
        printf("Preco: ");
        scanf("%f", &car[i].preco);
    }

    bolha_crescente(car);
    mostrar_crescente(car);

    printf("Filtrar Por Valor Maximo: R$: ");
    scanf("%f", &p);

    for (i = 0; i < N; i++)
    {
        if (p >= car[i].preco)
        {
            printf("\nMarca: %s\n", car[i].marca);
            printf("Ano: %d\n", car[i].ano);
            printf("Preco: R$ %.2f\n", car[i].preco);
        }
        

    }


    



    
        
}

//Porsche 2022 200000 Gol 2021 60000 Honda 2018 40000 Toyota 2021 20000 Gols 2023 70000 Honda 2018 40000