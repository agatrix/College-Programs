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
    int x; string y;
    cout << "Hello World!" << endl;
    Aluno a;
    Aluno b(123, "Agatha");
    Aluno c;
    cin >> c.nome;
    cin >> c.matricula;
    cout << a.nome << endl;
    cout << b.nome << endl;
    cout << c.nome << endl;
    cout << c.matricula << endl;
    return 0;

}
