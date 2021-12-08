#include <iostream>
#include <cmath>

using namespace std;

struct BinTree{
    int value;
    BinTree* left;
    BinTree* right;
};

void newBinTree (int val, BinTree** Tree) {
    if ((*Tree) == NULL){
        (*Tree) = new BinTree;
        (*Tree)->value = val;
        (*Tree)->left = (*Tree)->right = NULL;
    }
    if (val > (*Tree)->value)
        newBinTree(val, &(*Tree)->right);
    else newBinTree(val, &(*Tree)->left);
}

void Print (BinTree* Tree){
    if (Tree != NULL){
        cout << Tree->value << endl;
        Print(Tree->left);
        Print(Tree->right);
    }
}

BinTree* Search (BinTree* Tree, int key){
    if (Tree == NULL) return NULL;
    if (Tree->value == key) return Tree;
    if (Tree->value > key)
        Search(Tree->left, key);
    else Search(Tree->right, key);
}