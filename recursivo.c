#include <stdio.h>



void crescente(int n){
    if (0 < n)
    {
        crescente(n - 1);
    }

    printf(" %d ", n);
    
}

void decrescente(int n){
    if (10 > n)
    {
        decrescente(n + 1);
    }

    printf(" %d ", n);
    
}

int fatorial(int n){
    if(n > 1){
        return n * fatorial(n - 1);
    }
 }







int main(){

crescente(10);
printf("\n"); 
decrescente(0);
printf("\n");
fatorial(10);







}