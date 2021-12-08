#include <iostream>
#include <cmath>

using namespace std;

struct BinTree{
    int value;
    BinTree* left;
    BinTree* right;
};

void newBinTree (int val, BinTree** Tree) {
    if ((*Tree) == nullptr){
        (*Tree) = new BinTree;
        (*Tree)->value = val;
        (*Tree)->left = (*Tree)->right = nullptr;
    }
    if (val > (*Tree)->value)
        newBinTree(val, &(*Tree)->right);
    else newBinTree(val, &(*Tree)->left);
}

void Print (BinTree* Tree){
    if (Tree != nullptr){
        cout << Tree->value << endl;
        Print(Tree->left);
        Print(Tree->right);
    }
}

BinTree* Search (BinTree* Tree, int key){
    if (Tree == nullptr) return nullptr;
    if (Tree->value == key) return Tree;
    if (Tree->value > key)
        Search(Tree->left, key);
    else Search(Tree->right, key);
}

void destroyBinTree (BinTree* Tree){
    if (Tree != nullptr){
        destroyBinTree(Tree->left);
        destroyBinTree(Tree->right);
        delete(Tree);
    }
}