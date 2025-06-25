#include <iostream>
using namespace std;
#define MAX 5

struct Stack {
    char elements[MAX];
    int top;
};

void createStack(Stack &s) {
    s.top = -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

void push(Stack &s, char data) {
    if (!isFull(s)) {
        s.elements[++s.top] = data;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &s, char &x) {
    if (!isEmpty(s)) {
        x = s.elements[s.top--];
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void tampilStack(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = 0; i <= s.top; i++) {
            cout << s.elements[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack s;
    createStack(s);
    char data;
    int pilihan;

    do {
        cout << "Menu Stack\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Tampil Stack\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan karakter: ";
                cin >> data;
                push(s, data);
                break;
            case 2:
                pop(s, data);
                if (!isEmpty(s)) {
                    cout << "Data yang di pop: " << data << endl;
                }
                break;
            case 3:
                tampilStack(s);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
