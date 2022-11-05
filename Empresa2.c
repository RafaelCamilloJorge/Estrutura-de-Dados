#include <stdio.h>

typedef struct empresa{
    char nome[32];
    int mercadoria;
    float pagar;
    float totalpagar;
    float pago;
}Empresa;

int busca(int mercadoria, int tamanho, struct empresa a[]) {
  int meio, inf, sup;
  float media;
  inf = 0;
  sup = tamanho - 1;
  meio = (inf + sup) / 2;
  while (inf <= sup) {
    if (a[meio].mercadoria == mercadoria) {
      printf(" \n   %d             %.2f      %.2f  %.2f\n", a[meio].mercadoria,
             a[meio].pagar, a[meio].totalpagar, a[meio].pago);
      return meio;
    } else if (mercadoria > a[meio].mercadoria)
      inf = meio + 1;
    else
      sup = meio - 1;
    meio = (inf + sup) / 2;
  }

  if (inf > sup)
    meio = -1;
  return meio;
}

int main(){
    int N = 2;
    Empresa emp[N];
    int codigo;

    for(int i=0; i<N; i++){
        printf("\nDigite a empresa: ");
        scanf("%s", &emp[i].nome);
        printf("\nDigite a mercadoria: ");
        scanf("%d", &emp[i].mercadoria);
        printf("\nDigite o totalpagar: ");
        scanf("%f", &emp[i].totalpagar);
        printf("\nDigite o pago: ");
        scanf("%f", &emp[i].pago);
    }

    for (int i = 0; i < N; i++)
    {
        
        printf("%s\n", emp[i].nome);
        printf("%d\n", emp[i].mercadoria);
        printf("%.2f\n", emp[i].totalpagar);
        printf("%.2f\n", emp[i].pago);
        emp[i].pagar = emp[i].totalpagar - emp[i].pago;
        printf("%.2f\n", emp[i].pagar);
    }
    scanf("%d", &codigo);

    busca(codigo, N, emp);
    
}