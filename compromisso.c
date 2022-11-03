#include <stdio.h>
#include <stdlib.h>


typedef struct compromisso{
    char compromisso[5];
    int dia, mes, ano;
    int hora, minutos;
}Compromisso;

void important(struct compromisso comp[], int N) {
    int x = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (comp[i].mes > comp[i + 1].mes) 
        {
            {
                x = i;
            }
        }
    }
    
    printf("O compromisso mais importate eh o: ");
    printf("Compromisso %s => no dia %d/%d/%d as %dh%dm\n", comp[x].compromisso, comp[x].dia, comp[x].mes, comp[x].ano, comp[x].hora, comp[x].minutos);
       

}




int main(){
    int N = 2;
    Compromisso comp[N];

    for (int i = 0; i < N; i++)
    {
        printf("Digite o compromisso: ");
        scanf("%s\n", &comp[i].compromisso);
        fflush(stdin);
        printf("Digite o dia: ");
        scanf("%d", &comp[i].dia);
        printf("Digite o mes: ");
        scanf("%d", &comp[i].mes);
        printf("Digite o ano: ");
        scanf("%d", &comp[i].ano);
        printf("Digite o hora: ");
        scanf("%d\n", &comp[i].hora);
        printf("Digite o minuto: ");
        scanf("%d\n", &comp[i].minutos);
    }

    printf("\nVoce tem compromissos: \n");

    for (int i = 0; i < N; i++)
    {
        printf("Compromisso %s => no dia %d/%d/%d as %dh%dm\n", comp[i].compromisso, comp[i].dia, comp[i].mes, comp[i].ano, comp[i].hora, comp[i].minutos);
    }
    



}


