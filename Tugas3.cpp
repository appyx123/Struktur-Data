#include <iostream>
using namespace std;

template <typename T>
struct SingleLinkedListNode {
    struct Node {
        T data;
        Node* next;
    };

    Node *head=NULL, *tail=NULL, *current=NULL, *temp=NULL;

    

