#include<iostream>

using namespace std;

class Node{
private:
	int value;
	Node *prox;
public:
	Node(){
		this->value = 0;
		this->prox = NULL;
  }
  ~Node(){}
  void setProx(Node *prox){
		this->prox = prox;
	}
  int getValue(){
		return this->value;
	}
  void setValue(int value){
		this->value = value;
	}
  Node *getProx(){
		return this->prox;
	}
};

class Pilha{
private:
  Node* topo;
public:
  Pilha(int value){
    topo = NULL;
  }
  ~Pilha(){}
  void Push(int value){
    Node* novo = new Node;
    if (topo == NULL){
      novo->setValue(value);
      novo->setProx(NULL);
      topo = novo;
    }
    else{
      novo->setValue(value);
      novo->setProx(topo);
      topo = novo;
    }
  }
  void Pop(){
    Node* aux;
    if(topo == NULL){
      cout << "Lista vazia\n";
    }
    else{
      aux = topo;
      topo = topo->getProx();
      delete(aux);
    }
  }
  void print(){
    Node * aux = topo;
    while(aux != NULL){
      cout << aux->getValue() << endl;
      aux->setProx()
    }
  }
};


int main(){
  Pilha test;
  int i = 0;

  for (; i < 10; i++){
    test.Push(i);
  }
  for (; i < 10; i++){
    cout << test->getValue() << endl;
  }
  test.Pop();
  te

  return 0;
}
