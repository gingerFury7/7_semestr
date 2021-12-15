#include <iostream>
#include "string"
#include "List.h"
#include "BinaryTree.h"

using namespace std;


int main() {
    List list;
    BinTree *tree;
    int a = 0;
    srand(time(nullptr));

    int n = 10;

    for (int i = 0; i < n; i++){
        a = rand() % 1000;
        list.push_front(a);
        tree = insert(tree, a);
    }
    tree = insert(tree, 502);
    list.print();
    cout << endl;
    printBinTree(tree);
    cout << endl;
//    BinTree *searchTree = search(tree, 106);
//    printBinTree(searchTree);
}
