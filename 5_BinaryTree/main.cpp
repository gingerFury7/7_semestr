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

    int n = 100;

    for (int i = 0; i < n; i++){
        a = rand() % 1000;
        list.push_front(a);
        tree = insert(tree, a);
    }
//    tree = insertWithCount(tree, 502);
//    cout << endl;
    int x = list.search(502);
    cout << x << endl;
    list.print();
//    cout << endl;
//    printBinTree(tree);
//    cout << endl;
}
