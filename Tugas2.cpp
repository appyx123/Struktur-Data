#include <iostream>
using namespace std;


struct Node{
	int data;
	Node *next;
};

Node *head, *tail, *n, *x;

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

void addMid(int j, int data){
	x = head;
	while(x->data != j) x = x->next;
	n = new Node;
	n->data = data;
	n->next = x->next;
	x->next = n;
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
    if (x == NULL){
        cout << "Data kosong\n";
        return;
    }
    cout << "Data Awal: ";
    while(x != NULL){
        cout << x->data << " ";
        x = x->next;
    }
    cout << endl;
}


void tampilTerbalik(Node* node){
	if (node == NULL) return;
	tampilTerbalik(node->next);
	cout << node->data << " ";
}

void insert(int data){
	x = head;
	if (head == NULL){
		createNewNode(data);
	} else if(data < head->data){
		addFront(data);
	} else if(data > tail->data){
		addBack(data);
	} else {
		while (x->next != NULL && x->next->data < data){
			x = x->next;
		}
		if (x->next == NULL){
			addBack(data);
		} else {
			addMid(x->data, data);
		}
	}		
}

int main(){
	insert(2);
    addBack(3);
    addFront(7);
    addBack(5);
    addMid(7, 4);
    addMid(5, 6);
    tampil();
	tampilTerbalik(head);

    cout << endl;
    cout << endl;

}