#include <iostream>

using namespace std;

class Aluno{
public:
    int matricula;
    string nome;

    ~Aluno(){} //Destruto

    Aluno(int mat,const string &nom){ //Construtor com parâmentros
        matricula = mat;
        nome = nom;
    }

    Aluno(){ //Construtor padrão
        matricula = -1;
        nome = "Indefino";
    }
};

class Nodo{
public:
    Nodo * prox;
    Aluno aluno;
    Nodo(){
        prox = NULL;
    }
};

class ListaEncAluno{
public:
    Nodo * primeiroNodo;
    ListaEncAluno(){
        primeiroNodo = NULL;
    }

    void insere(const Aluno &novoAluno){
        Nodo * novoNodo = new Nodo();
        novoNodo->aluno = novoAluno;
        Nodo * ultimoNodo = primeiroNodo;

        if(!primeiroNodo)
            primeiroNodo = novoNodo;
        else{
            while(ultimoNodo->prox)
                ultimoNodo = ultimoNodo->prox;

            ultimoNodo->prox = novoNodo;
       }
       return;
   }

   void imprime(ListaEncAluno &lista){
        Nodo * aux;
        aux = lista.primeiroNodo;
        while(aux){           
            cout << aux->aluno.nome << endl;
            aux = aux->prox;
        }
        
   }

   ~ListaEncAluno(){
        Nodo * Atual = primeiroNodo;
        Nodo * prox;
        while(Atual){
           prox = Atual->prox;
           delete Atual;
           Atual = prox;
        }
    }
};


int main(){
    Aluno a;
    Aluno b(123, "Agatha");
    Aluno c;
    ListaEncAluno lista;
    lista.insere(b);
    
    cin >> c.nome;
    cin >> c.matricula;
    lista.insere(c);
    lista.insere(a);
    lista.imprime(lista);
    return 0;

}
