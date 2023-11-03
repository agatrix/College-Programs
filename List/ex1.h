#ifndef __LISTA_H__
#define __LISTA_H__

typedef struct{
	int dia;
	int mes;
}Data;

typedef struct{
	char nome[40];
	char telefone[15];
	char celular[15];
	char email[40];
	Data DataAniversario;
}contato;


typedef struct No{
	contato info;
	struct No* prox;
}elemento;


typedef elemento * Lista;



void cria_agenda(Lista *ap_lista);

void insere_contato(Lista *lista);

void lista_contatos(Lista *lista);

Lista busca_contato(Lista lista, char nome);

void remove_contato(Lista *lista);

void atualiza_contato(Lista *lista);

void libera_agenda(Lista *lista);

#endif
