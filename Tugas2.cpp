#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SortedLinkedList {
private:
    Node* head;
public:
    SortedLinkedList() : head(nullptr) {}

    void insert (int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (!head || head->data > data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(int data) {
        if (!head) return;
        if (head->data == data) {
            removefront();
            return;
        }
        if (!head->next) {
            removefront();
        } else if (!head->next->next && head->next->data == data) {
            removeback();
        } else if (head->next && head->next->data == data) {
            removeback();
        }
        }

        void removefront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        }

        void removeback() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* n = head;
        while (n->next->next) {
            n = n->next;
        }
        delete n->next;
        n->next = nullptr;
        }

    void display() {
        Node* n = head;
        while (n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    ~SortedLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SortedLinkedList list;
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(7);
    cout << "Tampilan awal: ";
    list.display();
    list.remove(3);
    cout << "tampilan akhir: ";
    list.display();
}