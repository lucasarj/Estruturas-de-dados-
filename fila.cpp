#include<iostream>

using namespace std;

class Node{
private:
	int value;
	Node *prox;
public:
	Node(int value){
		this->value = value;
		this->prox = NULL;
	}
	int getValue(){
		return this->value;
	}
	void setValue(int value){
		this->value = value;
	}
	Node* getProx(){
		return this->prox;
	} 
	void setProx(Node *prox){
		this->prox = prox;
	}
};

class Fila{
private:
    Node *first;
    Node *last;
public:
	Node *getFirst(){
		return this->first;
	}
	Node *getLast(){
		return this->last;
	}
	void setLast(Node *last){
		this->last = last;
	}
	void setFirst(Node *first){
		this->first = first;
	}
	Fila(){
		this->last = getFirst();
		this->first = NULL;
	}
	~Fila(){
		delete this->last;
		delete this->first;
	}
    bool Vazia(){
        return this->last->getProx()== NULL
    }
    void Insere(int value){
        Node *novo = new Node(value);
        if (Vazia()){
			this->first = novo;
        }else{
			novo->setProx(this->last);
			this->setLast(novo);
		}
    }
	void Remove(){
		Node *lixo = this->last;
		if (Vazia()){
			cout << "Isso é besteira mah!\n";
		}else{
			while(lixo->getProx() != this->first){
				lixo->setProx(getProx());
			}
			delete this->first;
			this->setFirst(lixo);
		}
	}
	void Print(){
		
	}
};