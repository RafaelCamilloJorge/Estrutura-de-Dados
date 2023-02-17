#include <stdio.h>
#include <stdlib.h>


int ordena(int arr[], int topo){
    int aux = 0;
    int houve_troca = 1;

    while(houve_troca == 1){
        houve_troca = 0;
        for(int i = 0; i < topo; i++){
        if(arr[i] > arr[i + 1]){
            aux = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = aux;
            houve_troca = 1;
        }
        }
    }

    system("cls");

    for(int i = 0; i < topo; i++){
        
        printf("\n%d ",arr[i]);
    }

}



int busca(int arr[]){
    int nro;
    int x = 0;
    printf("\n================================");
    printf("\nENCONTRAR NUMERO\n");
    scanf("%d",&nro);
    for(int i = 0; i < 5; i++){
        if(arr[i] == nro){
            x++;
            
        }
    }
        if(x == 0){
            printf("\n\nNao Foi Encontrado!\n");
        }
        else{
            printf("esse numero foi encontrado");
            printf(" %d Vezes\n", x);
        }

}


int main(){
    int array[5] = {5, 4, 3, 2, 1};
    int topo = 0;

    for (int i = 0; i < 5; i++)
    {
        topo++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d\n\n", array[i]);
    }

    ordena(array, topo);
    busca(array);    

}