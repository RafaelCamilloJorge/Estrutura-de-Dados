#include <stdio.h>

int busca(int n, int item){
  int x[5] = {12,13,24,35,98};
  int nmax = 5;
  if (n < nmax)
  {
    if (x[n] == item)
    {
      printf("NUMERO ENCONTRADO = no indice n[%d]\n", n);
      return item;
    } 
    if (x[n] < item)
    {
      n = n + 1;
    }
    busca(n + 1, item);
  }
    else{
      return -1;
    }
}





int main(){
  int item;
  printf("DIGITE UM NUMERO A SER ENCONTRADO\n");
  scanf("%d", &item);

  busca(0, item);
  if (busca(0, item) > 0)
  {
    printf("%d", item);
  }
  
  else{
    printf("NUMERO NAO ENCONTRADO");
  }


}