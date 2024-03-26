#include<iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

#define MAX 300
using namespace std;

class ListaFisica {
public:
    int vet[MAX];
    int quantidade = 0;

    ListaFisica(){} //Construtor Vazio
    ~ListaFisica(){} //Destrutor 

    void insere(int vet[]){
        while(scanf("%d",&vet[quantidade])>0){
            quantidade++;
        }
    }

    void insereRandom(int vet[]){
        for(int i=1; i<=100;i++){
            for(int j=0; j<i; j++)
                vet[j] = 1+(rand()%1000);

            //manda o vetor pra função

        }
    }
};

void escritaArquivo(int numAcesso, int selecao){
    ofstream myStream;
    if(selecao==1)
        myStream.open("InsertSortAcess.txt");
    else
        myStream.open("SelectionSortAcess.txt");
    
    myStream << numAcesso;
    myStream << " ";
    myStream.close();
}

void insertSort(int vet[], int quantidade){
    int valor, j, numAcesso=0;
    for(int i=1; i<quantidade;i++){
        valor = vet[i];
        numAcesso++;
        j = i-1;
        while(valor < vet[j] && j>=0){
            vet[j+1] = vet[j];
            numAcesso++;
            j--;   
        }
        vet[j+1] = valor;
        numAcesso++;
        for(int k=0; k<quantidade;k++){
            cout << vet[k] << " ";
        }
        cout << endl;
    }
    cout << numAcesso << endl;
    escritaArquivo(numAcesso,1);
}

void swap(int vet[], int x, int y, int *numAcesso){
    int aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
    *numAcesso+=3;

}


void selectionSort(int vet[], int quantidade){
    int numAcesso = 0, atualIndex;

    for(int i=0; i<quantidade-1;i++){
        atualIndex = i;
        for(int j=i+1;j<quantidade;j++){
            if(vet[j]<vet[atualIndex])
                atualIndex = j;
        }
        if(i!=atualIndex)
            swap(vet,i,atualIndex,&numAcesso);

        for(int k=0; k<quantidade;k++){
            cout << vet[k] << " ";
        }
        cout << endl;
    }
    cout << numAcesso << endl;
    escritaArquivo(numAcesso,2);
}


int main(){

    ListaFisica listaEst;
    
    listaEst.insere(listaEst.vet);

    insertSort(listaEst.vet,listaEst.quantidade);
    selectionSort(listaEst.vet,listaEst.quantidade);
    return 0;
}