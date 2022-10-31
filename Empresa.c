#include <stdio.h>


typedef struct local{
    char cidade[32];
    char estado[32];
}Local;

typedef struct empresa{
    char nome[32];
    char cnpj[16];
    Local end;
}Empresa;


int main(){
    Empresa emp;

    printf("Nome: ");
    scanf("%s", &emp.nome);
    printf("CNPJ: ");
    scanf("%s", &emp.cnpj);

    printf("Cidade: ");
    scanf("%s", &emp.end.cidade);
    printf("Estado: ");
    scanf("%s", &emp.end.estado);

    printf("Nome: %s\n", emp.nome);
    printf("CNPJ: %s\n", emp.cnpj);
    printf("Cidade: %s\n", emp.end.cidade);
    printf("Estado: %s\n", emp.end.estado);
}