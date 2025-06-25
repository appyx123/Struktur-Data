#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL, *tail = NULL, *n = NULL, *x = NULL;

void createNewNode(int data){
	n = new Node;
	n->data = data;
	tail = n;
	head = n;
	tail->next = NULL;
}

void addBack(int data){
	n = new Node;
	n->data = data;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void addFront(int data){
	n = new Node;
	n->data = data;
	n->next = head;
	head = n;
}



void removeFront(){
	x = head;
	head = head->next;
	delete x;
	x = NULL;
}

void removeBack(){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete x->next;
	tail->next = NULL;
}

void removeMid(int i){
	Node *temp=NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete x;
	x = NULL;
}

bool dataExists(int data){
	x = head;
	while(x != NULL){
		if (data == x->data)
			return true;
		x = x->next;
	}
	return false;
}

void remove(int data){
	if(data == head->data)
		removeFront();
	else if(data == tail->data)
		removeBack();
	else{
		if(dataExists(data))
			removeMid(data);
	}	
}

void tampil(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}



void tampilBelakang() {
    x = tail;
    while(x != NULL) {
        if (x == head) {
            cout << x->data << " ";  
            break;
        }

        cout << x->data << " ";

        Node *temp = head;
        while(temp->next != x) temp = temp->next;
        x = temp; 
    }
}

void addMid(int j, int data){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = data;
	n->next = x->next;
	x->next = n;
}

void insert(int data){
    x = head;
    if(head == NULL){
        createNewNode(data);
    }else if(data < head->data){
        addFront(data);
    }else if(data > tail->data){
        addBack(data);
    }else{
        while(x->next != NULL && x->next->data < data) {
            x = x->next;
        }
        if(x->next == NULL) {
            addBack(data);
        } else {
            addMid(x->data, data);
        }
    }
}

int main(){
    createNewNode(8);
    addBack(12);
    addFront(20);
    addMid(8, 20);
    addBack(100);
    tampil();
    cout << endl;
    cout << endl;
    tampilBelakang();

    cout << endl;
    cout << endl;
}