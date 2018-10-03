#include<iostream>

using namespace std;

class Node{
private:
	int value;
	Node *next;
public:
		Node(int value){
			this->value = value;
			this->next = NULL;
		}
		~Node(){}
		void setValue(int value){
		this->value = value;
		}
		void setNext(Node *next){
			this->next = next;
		}
		int getValue(){
			return this->value;
		}
		Node *getNext(){
			return this->next;
		}
};

class List{
private:
	Node *head;
	Node *tail;
public:
	List(){
		this->head = NULL;
		this->tail = NULL;
	}
	~List(){}
	Node *getHead(){
		return this->head;
	}
	Node *getTail(){
		return this->tail;
	}
	void setHead(Node *head){
		this->head = head;
	}
	void setTail(Node *tail){
		this->tail = tail;
	}
	void imprime();
	void insereEnd(int value);
	void Busca(int value);
};

//imprime a lista
void List::imprime(){
	Node *cont = this->getHead();
	if (this->head == getTail()){
		cout << "A lista esta vazia!\n";
	}
	else{
		do{
			cout << cont->getValue() <<" ";
			cont = cont->getNext();
		}
		while (cont != this->tail);
	}
	cout << endl;
}

//Insere um elemento no fim da lista
void List::insereEnd(int value){
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

void List::Busca(int value){
	int cont = 0;
	Node *aux = this->getHead();
	while(aux != NULL){
		if(aux->getValue() == value){
			cout << "O elemento foi encontrado na posição " << cont << endl;
			return;
		}
		aux = aux->getNext();
		cont++;
	}
	cout << "O elemento não foi encontrado!\n";
}



int main(){
	int i;
	List *test = new List();
	for (i = 0; i <= 10; i++){
		test->insereEnd(i);
	}
	test->imprime();
	test->Busca(11);
	return 0;
}
