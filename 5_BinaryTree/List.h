#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class List {
    Node* head;
    Node* tail;
    int size;

public:
    List(){
        head = nullptr;
        size = 0;
    }

    ~List(){
        tail = head;
        while (head)
        {
            head = head->next;
            delete tail;
            tail = head;
        }
    }
    void print()
    {
        Node* node = head;
        while (node != nullptr)
        {
            cout << node->data << '\t';
            node = node->next;
        }
        cout << endl;
    }

    void push_front(int data) {
        Node* newElem = new Node;
        newElem->data = data;
        newElem->next = head;
        head = newElem;
        size++;
    }

    int search(int data) {
        Node* node = head;
        for (int i = 0; i < size - 1; i++){
            if (node->data == data){
                return i;
            }
        }
        return -1;
    }

};