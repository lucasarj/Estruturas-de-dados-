#include <iostream>

using namespace std;

//classe para manipulação dos nós da lista
class Node{
private:
	int value;
	Node *next;
	Node * prev;
public:
	Node(int value){
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
	~Node(){}
	void setValue(int value){
		this->value = value;
	}
	void setNext(Node *next){
		this->next = next;
	}
	void setPrev(Node* prev){
		this->prev = prev;
	}
	int getValue(){
		return this->value;
	}
	Node *setNext(){
		return this->next;
	}
	Node *getPrev(){
		return this->prev;
	}

};

//classe para manipulação da lista
class List{
private:
	Node* head;
	Node* tail;
public:
	List(){
		this->head = NULL;
		this->tail = NULL;
	}
	~List(){}
	void setHead(Node* head){
		this->head = head;
	}
	Node* getHead(){
		return this->head;
	}
	void setTail(Node* tail){
		this->tail = tail;
	}
	Node* getTail(){
		return this->tail;
	}

//imprime a lista
	void imprime(){
		Node *cont = this->getHead();
		if (this->head == getTail()){
			cout << "A lista esta vazia!\n";
		}
		else{
			do{
				cout << cont->getValue() <<" ";
				cont = cont->setNext();
			}
			while (cont != this->tail);
		}
		cout << endl;
	}

	//buscar um elemento na lista
	void Busca(int value){
		int cont = 0;
		Node *aux = this->getHead();
		while(aux != NULL){
			if(aux->getValue() == value){
				cout << "O elemento foi encontrado na posição " << cont << endl;
				return;
			}
			aux = aux->setNext();
			cont++;
		}
		cout << "O elemento não foi encontrado!\n";
	}

	//Insere um elemento no fim da lista
	void insereEnd(int value){
		if (this->head == NULL){
			Node *cont = new Node(value);
			this->setTail(cont);
			this->setHead(cont);
			cont->setNext(NULL);
		}
		else {
			Node *cont = new Node(value);
			this->tail->setNext(cont);
			this->setTail(cont);
		}
	}

//insere um elemento no meio da lista
	void insereMid(int pos, int value){
		int cont = 0;
		Node *prev = NULL;
		Node *aux = head;
		Node *novo = new Node(0);
		novo->setValue(value);

		while(cont < pos){
			prev = aux;
			aux = aux->setNext();
			cont++;
		}
		novo->setNext(prev->setNext());
		prev->setNext(novo);
	}

};

int main(){
	List test;
	int v, cont = 0;
	for (cont; cont < 10; cont++){
		test.insereEnd(cont + 1);
	}
	test.insereMid(4, 2345);
	test.imprime();
	test.Busca(3);
	test.Busca(2346);
	return 0;
}
