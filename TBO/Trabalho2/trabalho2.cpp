#include<iostream>
#include<cstdlib>
#include<fstream>

#define MAX 300
using namespace std;

//Função comentada para discutir com o professor
/*void escritaArquivo(int numAcesso, int selecao){
    ofstream myStream;
    if(selecao==1)
        myStream.open("InsertSortAcess.txt", ios::ate);
    else{
        myStream.open("SelectionSortAcess.txt", ios::ate);
    }
    myStream << numAcesso;
    myStream << " ";
}*/

int insertSort(int vet[], int quantidade){
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
    // escritaArquivo(numAcesso,1);
    return numAcesso;
}

void swap(int vet[], int x, int y, int *numAcesso){
    int aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
    *numAcesso+=3;
}


int selectionSort(int vet[], int quantidade){
    int numAcesso = 0, atualIndex;

    for(int i=0; i<quantidade-1;i++){
        atualIndex = i;
        for(int j=i+1;j<quantidade;j++){
            if(vet[j]<vet[atualIndex])
                atualIndex = j;
        }
        //Condição para não ter que fazer acesso desnecessário
        if(i!=atualIndex) 
            swap(vet,i,atualIndex,&numAcesso);

        for(int k=0; k<quantidade;k++){
            cout << vet[k] << " ";
        }
        cout << endl;
    }
    cout << numAcesso << endl;
    // escritaArquivo(numAcesso,2);
    return numAcesso;
}

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

    void insereRandom(int vet[],int escolha){
        ofstream myStream;
        if(escolha==1)
            myStream.open("InsertSortAcess.txt", ios::ate);
        else{
            myStream.open("SelectionSortAcess.txt", ios::ate);
        }

        for(int i=1; i<=100;i++){
            srand(i+12312);   //Dessa forma alimenta a seed com um valor diferente em cada
            for(int j=0; j<i; j++){
                vet[j] = 1+(rand()%1000);
            }
            if(escolha==1){
                myStream << insertSort(vet,i);
                myStream << endl;
            }else{
                myStream << selectionSort(vet,i);
                myStream << endl;
            }
        }
    }
};



int main(){

    ListaFisica listaEst;
    int escolhaTipoLista, escolhaOrdenacao;
    cin >> escolhaTipoLista;
    cin >> escolhaOrdenacao;
    
    

    switch (escolhaTipoLista)
    {
    case 1:
        listaEst.insere(listaEst.vet);
        
        if(escolhaOrdenacao==1)
            insertSort(listaEst.vet,listaEst.quantidade);
        else
            selectionSort(listaEst.vet,listaEst.quantidade);

        break;
    case 2:
        listaEst.insereRandom(listaEst.vet,escolhaOrdenacao);
        //selectionSort(listaEst.vet,listaEst.quantidade);
        break;
    }
   
    
    return 0;
}