#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int nro = 0;
    int pilha[MAX];
    int topo = -1;
    int opc = 0;

    while (opc != 4)
    {

        system("cls");
        printf("* * * * * * M E N U * * * * * *\n\n");
        printf("\n1 - INSERIR");
        printf("\n2 - REMOVER");
        printf("\n3 - MOSTRAR");
        printf("\n4 - SAIR\n");
        printf("\n\nDigite sua OPCAO\n\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            system("cls");
            printf("* * * * * I N S E R I R * * * * *\n\n");
            if (topo < (MAX - 1))
            {
                topo++;
                scanf("%d", &pilha[topo]);
                printf("\n\n\nNumero Inserido Com Sucesso...\n\n\n");
            }
            else
                printf("\nERROR - PILHA CHEIA...\n\n");

            system("pause");
            break;

        case 2:
            system("cls");
            printf("* * * * * R E M O V E R * * * * *\n\n");
            if (topo > -1)
            {
                    printf("Quantos Nro deseja Remover? \n");
                    scanf("%d", &nro);
                    if (nro <= topo + 1)
                    {
                        while (nro > 0)
                        {
                            printf("\n%d REMOVIDO COM SUCESSO...\n\n\n", pilha[topo]);
                            nro--;
                            topo--;
                            
                        }
                    }
                    else{
                        printf("\nQUANTIDADE DE NRO MAIOR QUE A PILHA\n\n");
                        
                    }
                }
            else
                printf("\nERROR - PILHA VAZIA...\n\n\n");

            system("pause");
            break;

        case 3:
            system("cls");
            if (topo != -1)
            {
                printf("* * * * * M O S T R A R * * * * *\n\n");
                for (int i = topo; i >= 0; i--)
                {
                    printf("%d\n", pilha[i]);
                }
            }
            else
                printf("\nERROR - PILHA VAZIA...\n\n\n");
            system("pause");
            break;
        }
    }
}

