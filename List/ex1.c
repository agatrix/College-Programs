#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ex1.h"


int main(){

	int escolha;

	do{
		printf("1 - Inserir Contato\n");
		printf("2 - Listar Contatos\n");
		printf("3 - Buscar Contato\n");
		printf("4 - Editar Contato\n");
		printf("5 - Remover Contato\n");
		printf("6 - Remover Contatos Duplicados\n");
		printf("7 - Sair\n");

		scanf("%d",&escolha);
		system("clear");
	}while(escolha!=7);


	return 0;
}
