#include<iostream>

using namespace std;

class Node{
private:
	int value;
	Node *down;
public:
	Node(int value){
		this->value = value;
		this->down = NULL;
	}
	int getValue(){
		return this->value;
	}
	void setValue(int value){
		this->value = value;
	}
	Node* getDown(){
		return this->down;
	} 
	void setDown(Node *down){
		this->down = down;
	}
};

class Pilha{
private:
	Node* topo;
public:
	Pilha(){
		this->topo = NULL;
	}
	~Pilha(){
		delete this->topo;
	}
	Node* getTopo(){
		return this->topo;
	}
	void setTopo(Node *topo){
		this->topo = topo;
	}
	bool Vazia(){
		return this->topo == NULL;
	}
	void push(int value){
		Node *novo = new Node(value);
		if(this->topo == NULL){
			this->topo = novo;
		}
		else {
			novo->setDown(this->topo);
			this->topo = novo;
		}
	}
	void pop(){
		Node *lixo = topo;
		if (Vazia()){
			cout << "A pilha está vazia, seu vagabundo\n";
		}else{
			topo = topo->getDown();
			lixo->setDown(lixo);
			delete lixo;
		}
	}
	void Imprime(){
		Node *aux = topo;
		while(aux != NULL){
			cout << aux->getValue() << endl;
			aux = aux->getDown();
		}
	}
};

int main(){
	Pilha test;
	int i = 0;


	for (; i < 10; ++i){
		test.push(i + 1);
	}
	test.Imprime();
	test.pop();
	test.pop();
	test.Imprime();
	
	return 0;
}
