#include <iostream>
#include <string>

using namespace std;
 
struct Node {
    string val;
    struct Node* next;
    Node(string x)
    {
        val = x;
        next = nullptr;
    }
};
 
class List {
private:
    int listSize = 0;
 
public:
    int listCompare = 0;
    Node* head;
    Node* sorted;
 
    void push(string val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        listSize = 0;
    }

    void insertionSort(Node* headRef)
    {
        sorted = nullptr;
        Node* current = headRef;
        while (current != nullptr) {
            Node* next = current->next;
            sortedInsert(current);
            current = next;
            listCompare++;
        }
        head = sorted;
    }
 
    /*
     * function to insert a new_node in a list. Note that
     * this function expects a pointer to head_ref as this
     * can modify the head of the input linked list
     * (similar to push())
     */
    void sortedInsert(Node* newnode)
    {
        /* Special case for the head end */
        if (sorted == nullptr || sorted->val >= newnode->val) {
            newnode->next = sorted;
            sorted = newnode;
            listCompare += 2;
        }
        else {
            Node* current = sorted;
            /* Locate the node before the point of insertion
             */
            while (current->next != nullptr
                   && current->next->val < newnode->val) {
                current = current->next;
                listCompare += 2;
            }
            newnode->next = current->next;
            current->next = newnode;
            listSize++;
        }
    }

    void printList(Node* head)
    {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
    }
};
