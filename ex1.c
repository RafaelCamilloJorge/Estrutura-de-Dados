#include <stdio.h>

int expoente(int n, int e){
    if (e > 1)
    {
        return n * expoente(n, e - 1);
    }
    if(e == 1){
        return n;
    }
    
}



int main(){
    printf("%d", expoente(8,3));
}