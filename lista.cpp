#include <iostream>

using namespace std;

class Node{
private:
	int value;
	Node *prox;
	Node * prev;
public:
	Node(int value){
		this->value = value;
		this->prox = NULL;
		this->prev = NULL;
	}
	~Node(){}
	void setValue(int value){
		this->value = value;
	}
	void setProx(Node *prox){
		this->prox = prox;
	}
	void setPrev(Node* prev){
		this->prev = prev;
	}
	int getValue(){
		return this->value;
	}
	Node *getprox(){
		return this->prox;
	}
	Node *getPrev(){
		return this->prev;
	}

};

class List{
private:
	Node* first;
	Node* last;
public:
	List(){
		this->first = NULL;
		this->last = NULL;
	}
	~List(){}
	void setFirst(Node* first){
		this->first = first;
	}
	Node* getFirst(){
		return this->first;
	}
	void setLast(Node* last){
		this->last = last;
	}
	Node* getLast(){
		return this->last;
	}
	void insere(int value){
		if(this->getFirst() == NULL){
			this->insereFirstNode(value);
		}
		else{
			this->insereNode(value);
		}
	}
	void insereFirstNode(int value){
		first = new Node(value);
		this->setLast(first);
	}
	void insereNode(int value){
		Node* aux = new Node(value);
		aux->setProx(last);
		this->getLast()->setPrev(aux);
		this->setLast(aux);
	}
	void print(){
		Node* aux = this->getFirst();
		while(aux != NULL){
			cout << aux->getValue() << " ";
			aux = aux->getPrev();
		}
		cout << endl;
	}
};

int main(){
	List test;
	int v, cont = 0;
	for (cont; cont < 10; cont++){
		test.insere(cont + 1);
	}
	test.print();
	return 0;
}
