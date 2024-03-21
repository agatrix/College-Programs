#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 300
using namespace std;

class ListaFisica{
public:
    int q_elemento;
    int intervaloInicio, intervaloFim;
    int vetor[MAX];
    
    void insere(int opcao){
        cout << "Quantidade de Elementos: ";
        if(opcao == 1){
            cin >> q_elemento;
            cout << "Numeros da Lista" << endl;
            for(int i=0; i<q_elemento; i++)
                cin >> vetor[i];
        }else{
            cin >> q_elemento;
            cout << "Intervalo: ";
            cin >> intervaloInicio; cin >> intervaloFim;
            for(int i=0; i<q_elemento; i++)
                vetor[i] = intervaloInicio+(rand()%(intervaloFim-intervaloInicio));
                //Temos um intervalo de [x,y], com z elementos
        }
    }

    ListaFisica(){}     //Construtor Vazio
    ~ListaFisica(){}    //Destrutor Vazio

    int insereEspecifico(int indice, int valorInserir){
        for(int i = q_elemento; i>=indice; i--){
                vetor[i+1] = vetor[i];
                if(i == indice){
                    vetor[i] = valorInserir;
                    q_elemento++;
                    return q_elemento;
                }
        }
        return q_elemento;
    }

    void swap(int x, int y){
        int aux = vetor[x];
        vetor[x] = vetor[y];
        vetor[y] = aux;
    }

    void imprimeLista(){
        for(int i=0; i<q_elemento;i++)
            cout << vetor[i] << " ";
    }

    void imprimeListaInversa(){
        for(int i=q_elemento-1; i>=0;i--)
            cout<<vetor[i] << " ";
    }

    int procura(int valor){
        for(int i=0; i<q_elemento;i++){
            if(vetor[i]==valor){
                return i;
            }
        }
        return -1;
    }

    void menorValor(){
        int menor, posicao;
        if(q_elemento!=0)     //Caso não tenha elementos só ignora tudo
            menor = vetor[0];
            posicao = 0;      //porem, se tem pelo menor um elemento, ele ja add um valor
        for(int i=0;i<q_elemento;i++){
            if(menor>vetor[i]){
                menor = vetor[i];
                posicao = i;
            }
        }
        cout << "Menor elemento: " << menor << endl << "posicao: " << posicao << endl;
    }
};

class Nodo{
public:
    Nodo * prox;
    Nodo * antec;
    int valor;

};

class ListaEncadeadaSimple{
public:
    Nodo * primeiroNodo;
    int q_elementos;
    int numAcesso;

    ListaEncadeadaSimple(){
        primeiroNodo = NULL;
    }
    
    void insere(int valor){
        Nodo * novoNodo = new Nodo();
        novoNodo->valor = valor;
        Nodo * ultimoNodo = primeiroNodo;

        if(!primeiroNodo)
            primeiroNodo = novoNodo;
        else{
            while(ultimoNodo->prox)
                ultimoNodo = ultimoNodo->prox;

            ultimoNodo->prox = novoNodo;
       }
    }

    void imprimeListaSimples(){
        Nodo * aux = primeiroNodo;
        while(aux != NULL){
            cout << aux->valor << " ";
            aux = aux->prox;
        }
        cout << endl;
    }

    //Impressão inversa de forma recursiva
    void imprimeListaSimplesInversa(Nodo * primeiro){ 
        Nodo * aux = primeiro;
        if(aux == NULL){
            return;
        }
        imprimeListaSimplesInversa(aux->prox);
        cout << aux->valor << " ";
    }

    void inserirEspecifico(int indice, int valor){
        int contagem = 0;
        Nodo * novoNodo = new Nodo();
        novoNodo->valor = valor;
        if(indice == 0){
            novoNodo->prox = primeiroNodo;
            primeiroNodo = novoNodo;
            return;
        }
        contagem++;
        Nodo * antec = primeiroNodo;
        Nodo * aux = primeiroNodo->prox;
        while(contagem != indice && aux!=NULL){
            contagem++;
            antec = aux;
            aux = aux->prox;
        }
        
        novoNodo->prox = aux;
        antec->prox = novoNodo;
        return;
    }

    int procuraValor(int valor){
        numAcesso = 0;
        Nodo * atual = primeiroNodo;
        while(atual!=NULL){
            numAcesso++;
            if(valor == atual->valor){  
                cout << "valor encontrado na posicao: ";
                return numAcesso;
            }
            atual = atual->prox;
        }
        cout << "numero de acesso: " << numAcesso << endl;
        return -1;
    }

    int menorValor(){
        numAcesso = 0;
        int menor;
        Nodo * atual = primeiroNodo;
        if(atual==NULL)
            return -1;
        menor = atual->valor;
        while(atual!=NULL){
            numAcesso++;
            if(atual->valor<menor){
                menor = atual->valor;
            }
            atual = atual->prox;
        }
        cout << "Numero de Acessos: " << numAcesso << endl;
        cout << "Menor valor: ";
        return menor;
    }

    void swapListaSim(int indice1, int indice2){
        Nodo * troca1; Nodo * troca2;
        Nodo * atual = primeiroNodo;
        int aux;
        numAcesso = 0;
        while(atual!=NULL){
            if(indice1 == numAcesso)
                troca1 = atual;
            if(indice2 == numAcesso)
                troca2 = atual;
            atual = atual->prox;
            numAcesso++;
        }
        aux = troca1->valor;
        troca1->valor = troca2->valor;
        troca2->valor = aux;
    }

    ~ListaEncadeadaSimple(){
        Nodo * aux = primeiroNodo;
        Nodo * prox;
        while(aux!=NULL){
            prox = aux->prox;
            delete aux;
            aux = prox;
        }
    }

};

class ListaEncadeadaDupla{
public:
    Nodo * primeiroNodo;
    int q_elementos;
    int numAcesso;
    
    ListaEncadeadaDupla(){
        primeiroNodo = NULL;
    }

    void insere(int valor){
        Nodo * novoNodo = new Nodo();
        novoNodo->valor = valor;
        Nodo * ultimoNodo = primeiroNodo;

        if(!primeiroNodo){
            primeiroNodo = novoNodo;
            primeiroNodo->prox = NULL;
            primeiroNodo->antec = NULL;
        }else{
            while(ultimoNodo->prox!=NULL){
                ultimoNodo = ultimoNodo->prox;
            }
            ultimoNodo->prox = novoNodo;
            ultimoNodo->prox->antec = ultimoNodo;
        }
    }

    void imprime(){
        Nodo * aux = primeiroNodo;
        int numAcesso;
        while(aux != NULL){
            cout << aux->valor << " ";
            aux = aux->prox;
        }
        cout << endl;
    }

    void imprimeInversa(Nodo * primeiro){ 
        Nodo * aux = primeiro;
        if(aux == NULL){
            return;
        }
        imprimeInversa(aux->prox);
        cout << aux->valor << " ";
    }

    void insereEsp(int indice, int valor){
        Nodo * novoNodo = new Nodo();
        novoNodo->valor = valor;
        
        numAcesso = 0;
        if(indice == 0){
            primeiroNodo->antec = novoNodo;
            novoNodo->prox = primeiroNodo;
            novoNodo->antec = NULL;
            primeiroNodo = novoNodo;
            return;
        }
        numAcesso++;
        Nodo * aux = primeiroNodo->prox;
        while(numAcesso!=indice && aux!=NULL){
            numAcesso++;
            aux = aux->prox;
        }
            
        novoNodo->prox = aux;
        novoNodo->antec = aux->antec;
        aux->antec->prox = novoNodo;
        aux->antec = novoNodo;
        return;  
    }

    int procura(int valor){
        numAcesso = 0;
        Nodo * atual = primeiroNodo;
        while(atual!=NULL){
            numAcesso++;
            if(valor == atual->valor){  
                cout << "valor encontrado na posicao: ";
                return numAcesso;
            }
            atual = atual->prox;
        }
        cout << "numero de acesso: " << numAcesso << endl;
        return -1;
    }

    int menorValor(){
        numAcesso = 0;
        int menor;
        Nodo * atual = primeiroNodo;
        if(atual==NULL)
            return -1;
        menor = atual->valor;
        while(atual!=NULL){
            numAcesso++;
            if(atual->valor<menor){
                menor = atual->valor;
            }
            atual = atual->prox;
        }
        cout << "Numero de Acessos: " << numAcesso << endl;
        cout << "Menor valor: ";
        return menor;
    }

    void swap(int indice1, int indice2){
        Nodo * troca1; Nodo * troca2;
        Nodo * atual = primeiroNodo;
        int aux;
        numAcesso = 0;
        while(atual!=NULL){
            if(indice1 == numAcesso)
                troca1 = atual;
            if(indice2 == numAcesso)
                troca2 = atual;
            atual = atual->prox;
            numAcesso++;
        }
        aux = troca1->valor;
        troca1->valor = troca2->valor;
        troca2->valor = aux;
    }
};

int main(){

    int escolhaLista, escolhaMenu, escolhaEntrada;
    int repeticaoWhile=1;
    int indice;
    int valorInserir;
    int opcaoInserir;
    int troca1, troca2;
    int valorProcura;
    int valores;
    int intervaloI; int intervaloF;
    srand(time(NULL));
    

    do{
        //Cria a lista com entrada ou valores aleatórios
        cout << "Lista com entrada(1) ou aleatória(2)?" << endl;
        cin >> escolhaEntrada;
        ListaFisica listaEstatica;
        ListaEncadeadaSimple listaSim;
        ListaEncadeadaDupla listaDup;

        //Escolha do tipo de lista
        cout <<"Tipo de Lista: lista fisica(1) encadeada(2) duplamente(3)" << endl;
        cin >> escolhaLista;
        switch(escolhaLista){
            case 1: //Lista física
                do{
                    //cout << "\nInserir Lista(1)\nInserir Especifico(2)\nSwap(3)\nProcura Valor(4)\nMenor Valor(5)\nImprime(6)\nImprimeInverso(7)\nSair(0)\n";
                    cin >> escolhaMenu;
                    ////system("clear")
                    switch(escolhaMenu){ 
                        
                        case 1:
                            //insere na lista
                            listaEstatica.insere(escolhaEntrada); 
                            break;

                        case 2:
                            //insere o valor especifico em algum local da lista
                            do{
                                cout << "Indice: ";
                                cin >> indice;
                                cout << "Valor: ";
                                cin >> valorInserir; 
                                listaEstatica.q_elemento = listaEstatica.insereEspecifico(indice, valorInserir);
                                cout << "Inserir novamente? Sim(1) Não(2)" << endl;
                                cin >> opcaoInserir;
                            }while(opcaoInserir == 1);
                            break;

                        //troca valores dentro da lista
                        case 3:
                            cout << "Indices de troca: ";
                            cin >> troca1; cin >> troca2;
                            listaEstatica.swap(troca1, troca2);
                            break;
                        
                        //Procura um valor especifico no vetor
                        case 4:
                            cout << "procure um valor: "; cin >> valorProcura;
                            cout << "Achado no indice: " << listaEstatica.procura(valorProcura) << endl;
                            break;
                        
                        case 5:
                            //Procura o menor elemento da posição
                            listaEstatica.menorValor();
                            break;

                        case 6:
                            //imprime lista
                            listaEstatica.imprimeLista();
                            cout << endl;
                            break;

                        case 7:
                            //imprime lista inversa
                            listaEstatica.imprimeListaInversa();
                            cout << endl;
                            break;

                        default: repeticaoWhile=2;
                    }
                }while(repeticaoWhile==1);
                break;
            
        case 2:
            /*Operações com
                    Lista Encadeada Simples*/
            do{
                cout << "\nInserir Lista(1)\nInserir Especifico(2)\nSwap(3)\nProcura Valor(4)\nMenor Valor(5)\nImprime(6)\nImprimeInverso(7)\nSair(0)\n";
                cin >> escolhaMenu;
                //system("clear")
                switch(escolhaMenu){ 
                    case 1:
                        //Inserções
                        cout << "Quantidade de Elementos: ";
                        cin >> listaSim.q_elementos;
                        if(escolhaEntrada==2){
                            cout << "intervalo: ";
                            cin >> intervaloI; cin >> intervaloF;
                        }
                            
                        for(int i=0; i<listaSim.q_elementos;i++){
                            if(escolhaEntrada == 1){
                                cin >> valores;
                                listaSim.insere(valores);
                            }else{
                                listaSim.insere(intervaloI+(rand()%(intervaloF-intervaloI)));
                            }
                        }
                        break;

                    case 2:
                    //Inserção de um valor em um indice especifico

                        do{
                            cout << "Indice: ";
                            cin >> indice;
                            cout << "Valor: ";
                            cin >> valorInserir; 
                            listaSim.inserirEspecifico(indice, valorInserir);
                            cout << "Inserir novamente? Sim(1) Não(2)" << endl;
                            cin >> opcaoInserir;
                        }while(opcaoInserir == 1);
                        break;

                    case 3:
                        //Faz a troca de dois valores
                        cout << "Indices para trocar: ";
                        cin >> troca1; cin >> troca2;
                        listaSim.swapListaSim(troca1,troca2);
                        break;

                    case 4:
                        //Procura valor especifico 
                        cout << "procure um valor: "; cin >> valorProcura;
                        cout << listaSim.procuraValor(valorProcura) << endl;
                        break;

                    case 5:
                        //Busca o menor valor da Lista encadeada Simples
                        cout << listaSim.menorValor() << endl;
                        break;

                    case 6:
                        //Impressão
                        listaSim.imprimeListaSimples();
                        break;
                    
                    case 7:
                        //Impressão Inversa da lista encadeada
                        listaSim.imprimeListaSimplesInversa(listaSim.primeiroNodo);
                        break;

                    default: repeticaoWhile=2;
                }
            }while(repeticaoWhile==1);
            break;
        
        case 3:
            /*Operações com
                    lista duplamente ligada*/
            do{
                cout << "\nInserir Lista(1)\nInserir Especifico(2)\nSwap(3)\nProcura Valor(4)\nMenor Valor(5)\nImprime(6)\nImprimeInverso(7)\nSair(0)\n";
                cin >> escolhaMenu;
                //system("clear")
                switch(escolhaMenu){ 
                    case 1:
                        //Inserção
                        cout << "Quantidade de Elementos: ";
                        cin >> listaDup.q_elementos;
                        if(escolhaEntrada==2){
                            cout << "intervalo: ";
                            cin >> intervaloI; cin >> intervaloF;
                        }
                            
                        for(int i=0; i<listaDup.q_elementos;i++){
                            if(escolhaEntrada == 1){
                                cin >> valores;
                                listaDup.insere(valores);
                            }else{
                                listaDup.insere(intervaloI+(rand()%(intervaloF-intervaloI)));
                            }
                        }
                        break;

                    case 2:
                        //Insereção em posição Especifica
                        do{
                            cout << "Indice: ";
                            cin >> indice;
                            cout << "Valor: ";
                            cin >> valorInserir; 
                            listaDup.insereEsp(indice, valorInserir);
                            cout << "Inserir novamente? Sim(1) Não(2)" << endl;
                            cin >> opcaoInserir;
                        }while(opcaoInserir == 1);
                        break;

                    case 3:
                        //faz a troca de dois itens especificos
                        cout << "Indices para trocar: ";
                        cin >> troca1; cin >> troca2;
                        listaDup.swap(troca1,troca2);
                        break;

                    case 4:
                        //Procura um valor especficio
                        cout << "procure um valor: "; cin >> valorProcura;
                        cout << listaDup.procura(valorProcura) << endl;
                        break;

                    case 5:
                        //Busca o menor valor da Lista encadeada Simples
                        cout << listaDup.menorValor() << endl;
            
                    case 6:
                        //Impressão
                        listaDup.imprime();
                        break;

                    case 7:
                        listaDup.imprimeInversa(listaDup.primeiroNodo);
                        break;

                    default: repeticaoWhile=2;
                }
            }while(repeticaoWhile==1);
    }
        cout << "Gostaria de repetir o procedimento? Sim (1) Não(2)" << endl;
        cin >> repeticaoWhile;
    }while(repeticaoWhile==1);

    return 0;
}