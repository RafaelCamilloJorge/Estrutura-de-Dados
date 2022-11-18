#include <stdio.h>



int busca(int n, int nmax, int nmin, int item){
    int v[5] = {1,2,3,4,5};
    if (n <= nmax)
    {
        int meio = (nmax + nmin) / 2;
        if (v[meio] == item)
        {
           return meio; 
        }
        if(item > v[meio]){
            nmin = meio + 1;
        }if(item < v[meio]){
            nmax = meio - 1;
            meio = (nmax + nmin) / 2;
        }
        if(nmin > nmax){
            return -1;
        }
        
        busca(n + 1, nmax, nmin, item);
    }
}



int main(){
    int item;
    scanf("%d", &item);
    printf("Seu numero foi encontrado no indice v[%d]", busca(0, 5, 0, item));
}