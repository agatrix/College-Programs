#include<stdio.h>
#include<stdlib.h>

void escrita(char ler[14]){

    FILE *arquivo;

    arquivo = fopen("destiny.txt","w");

    if (arquivo == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
    }else{
        printf("O arquivo foi aberto com sucesso!\n");
    }

    fprintf(arquivo, "%s" ,ler);


    fclose(arquivo);

}

void leitura(){
    FILE *arquivo;
    char ler[50];

    arquivo = fopen("origin.txt","r");

    if (arquivo == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
    }else{
        printf("O arquivo foi aberto com sucesso!\n");
    }

   
    fgets(ler, 15,arquivo);
    
    escrita(ler);
    
    fclose(arquivo);
}


int main(){
    
    leitura();

    return 0;
}