#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

using namespace std;
class List {
protected:
    struct Node {
        Node() : next(nullptr) {}

        Node(string val) : a(val), next(nullptr) {}

        string a;
        Node *next;
    };

    Node *head;
    int listSize;
public:
    int listCompare = 0;

    List() {
        head = nullptr;
        listSize = 0;
    };

    ~List() {
        while (head) { del(); }
    };

    string headEl() const { return head->a; }

    void insert(const string t)
    {
        if (head) {
            Node *i = head;
            while (i != nullptr && i->a < t) {
                listCompare += 2;
                if (i->next) {
                    i = i->next;
                    listCompare++;
                }
                else {
                    Node *nw = new Node();
                    nw->a = t;
                    nw->next = nullptr;
                    i->next = nw;
                    i = nullptr;
                    listSize++;
                    listCompare++;
                    return;
                }
            }
            if (i) {
                listCompare++;
                if (i != head) {
                    listCompare++;
                    if (i->a == t) {
//                        listCompare++;
                    }
                    else {
                        Node *nw = new Node();
                        nw->next = i->next;
                        nw->a = i->a;
                        i->next = nw;
                        i->a = t;
                        listSize++;
                        listCompare++;
                        return;
                    }
                }
                else {
                    listCompare++;
                    if (i->a == t) {
//                        listCompare++;
                    }
                    else {
                        Node *nw = new Node();
                        nw->next = head;
                        head = nw;
                        nw->a = t;
                        listCompare++;
                        listSize++;
                        return;
                    }
                }
            }
        }
        else {
            Node *nw = new Node();
            head = nw;
            nw->a = t;
            listSize++;
            listCompare++;
            return;
        }
    }

    void del()
    {
        if (head)
        {
            Node *newhead = head->next;
            delete head;
            head = newhead;
        }
    }

//    void print() {
//        Node *p = head;
//        while (p != nullptr) {
//            cout << "(" << p->a.first << ", " << p->a.second << ") ";
//            p = p->next;
//        }
//    }

    int size(){
        return listSize;
    }
};