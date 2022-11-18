#include <stdio.h>



void palavra(int n){
    char x;
    if (n > 0)
    {
        scanf("%c", &x);
        palavra(n - 1);
    }

    printf("%c", x);
    
}



int main(){
    palavra(6);
}
