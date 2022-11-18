#include <stdio.h>

int par(int n, float soma, int i){

    
    int x[5] = {38,2,1,4,4};
    if (n < 5)
    {
        if (x[n]%2 == 0)
        {
            printf("indice[%d] ", x[n]);
            soma = soma + x[n];
            i++;
        }
        
        par(n + 1, soma, i);
    }
    if(n == 4){
        printf("Media: %f", soma/i);
    }

}


int main(){
    par(0, 0, 0);
}