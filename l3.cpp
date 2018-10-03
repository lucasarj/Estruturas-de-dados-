#include<iostream>
#include<string.h>

using namespace std;

class Node{
private:
	int value;
	Node *prox;
public:
	Node();
	~Node();
	int getValue();
	void setValue(int value);
	Node* getProx();
	void setProx(Node *prox);
};

class Line{
private:
	Node *head;
    Node *tail;
public:
	Line();
	~Line();
	void add(char data);
	void remove();
	int size();
	bool isEmpty();
	char get(int pos);
	void destroy();
	void show();
};

class Pile{
    private:
    Node *head;
    public:
    Pile(){
        head = NULL;
    }
    ~Pile(){
    }
    Node* getHead(){
        return head;
    }
    void add(int data){
        Node *newNode = new Node;
        newNode->setValue(data);
        newNode->setProx(head);
        head = newNode;
    }
    void remove(){
        Node *temp = head;
        temp = temp->getProx();
        delete head;
        head = temp;
    }
    int size(){
        Node *temp = head;
        int cont = 0;
        while(temp != NULL){
            temp = temp->getProx();
            cont++;
        }
        return cont;
    }
    void show(){
        Node *temp;
        for(temp = head; temp != NULL; temp = temp->getProx()){
            cout << temp->getValue() << "-> ";
        }
        cout << endl;
    }
    char get(int pos){
        int cont = 0;
        Node *temp = head;
        
        while(temp != NULL){
            if(cont == pos){
                return temp->getValue();
            }
                cont++;
                temp = temp->getProx();
            }
            cout << "nao existe" << endl;
    }

};

//---------------------------------------------------------------------------------//
Node::Node(){
	prox = NULL;
}

Node::~Node(){
}

int Node::getValue(){
	return value;
}

void Node::setValue(int value){
	this->value = value;
}

Node* Node::getProx(){
	return prox;
}

void Node::setProx(Node *prox){
	this->prox = prox;
}

//---------------------------------------------------------------------------------//
Line::Line(){
	head = NULL;
    tail = NULL;
}

Line::~Line(){
}

void Line::add(char data){
	Node *newNode = new Node;
	newNode->setValue(data);
	newNode->setProx(NULL);

	if(head == NULL){
		head = newNode;
        tail = newNode;
	}
	else{
		tail->setProx(newNode);
        tail = newNode;
	}
}

void Line::remove(){
	Node *temp = head;
    temp = temp->getProx();
    delete head;
    head = temp;
}

int Line::size(){
	int cont = 0;
	Node *temp = head;
	while(temp != NULL){
		temp = temp->getProx();
		cont++;
	}
	return cont;
}
bool Line::isEmpty(){
	return (head == NULL);
}

char Line::get(int pos){
	int cont = 0;
	Node *temp = head;
	
	while(temp != NULL){
		if(cont == pos){
			return temp->getValue();
		}
		cont++;
		temp = temp->getProx();
	}
	cout << "nao existe" << endl;
}

void Line::destroy(){
	while(head != NULL){
		Node *temp = head->getProx();
		delete head;
		head = temp;
	}
	cout << "limpo" << endl;
}

void Line::show(){
	Node *temp;
	for(temp = head; temp != NULL; temp = temp->getProx()){
		cout << temp->getValue() << "-> ";
	}
	cout << endl;
}

bool verifyPoli(string str){
    Line li;
    Pile pi;
    int i;


    for(i = 0; i < str.length(); i++){
        li.add(str.at(i));
    }
    for(i = 0; i < str.length(); i++){
        pi.add(str.at(i));
    }

    for(i = 0; i < str.length(); i++){
        if(li.get(i) != pi.get(i))
            return false;
    }

}

Pile organize(Pile pi1, Pile pi2){
    Node *p1 = pi1.getHead();
    Node *p2 = pi2.getHead();
    Pile temp;

    while(true){
        if(p1 == NULL){
            if(p2 == NULL)
                break;
            temp.add(p2->getValue());
            p2 = p2->getProx();
            continue;
        }
        if(p2 == NULL){
            if(p1 == NULL)
                break;
            temp.add(p1->getValue());
            p1 = p1->getProx();
            continue;
        }

        if(p1->getValue() < p2->getValue()){
            temp.add(p1->getValue());
            p1 = p1->getProx();
        }else{
            temp.add(p2->getValue());
            p2 = p2->getProx();
        }
    }
    return temp;
}

//---------------------------------------------------------------------------------//

int main(){
    Pile pi1;
    Pile pi2;
    Pile pi3;

    pi1.add(5);
    pi1.add(4);
    pi1.add(1);
    pi1.add(0);

    pi2.add(66);
    pi2.add(34);
    pi2.add(14);
    pi2.add(2);

    pi3 = organize(pi1, pi2);
    pi3.show();
}