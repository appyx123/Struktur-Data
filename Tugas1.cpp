#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class stack {
private:
    node* top;
public:
    stack() { top = nullptr; }

    void push(int nilai) {
        node* newNode = new node();
        newNode->data = nilai;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (kosong()) {
            cout << "Data kosong\n";
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
    }

    bool kosong() {
        return top == nullptr;
    }

    void tampilkan() {
        node* temp = top;
        cout << "Data: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~stack() {
        while (!kosong()) {
            pop();
        }
    }
};

int main() {
    stack t;
    int pilihan, nilai;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Tampilkan\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                t.push(nilai);
                break;
            case 2:
                t.pop();
                break;
            case 3:
                t.tampilkan();
                break;
            case 0:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 0);
    return 0;
}
