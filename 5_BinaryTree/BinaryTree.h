#include <iostream>

using namespace std;

struct BinTree {
    int key;
    struct BinTree *left, *right;
};

struct BinTree *newBinTree (int item) {
    struct BinTree *temp = (struct BinTree *)malloc(sizeof(struct BinTree));
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

struct BinTree *insert (struct BinTree *BinTree, int key){
    if (BinTree == nullptr) return newBinTree(key);

    if (key < BinTree->key)
        BinTree->left = insert(BinTree->left, key);
    else
        BinTree->right = insert(BinTree->right, key);

    return BinTree;
}

struct BinTree *insertWithCount (struct BinTree *BinTree, int key){
    static int k = 0;
    if (BinTree == nullptr) return newBinTree(key);

    if (key < BinTree->key) {
        BinTree->left = insert(BinTree->left, key);
        k++;
    }
    else {
        BinTree->right = insert(BinTree->right, key);
        k++;
    }

    cout << k << endl;
    return BinTree;
}

struct BinTree *minValueNode(struct BinTree *node) {
    struct BinTree *current = node;

    // Find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

struct BinTree *deleteBinTree(struct BinTree *root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteBinTree(root->left, key);
    else if (key > root->key)
        root->right = deleteBinTree(root->right, key);
    else {
        if (root->left == nullptr) {
            struct BinTree*temp = root->right;
            free(root);
            return temp;
        } else if (root->right == nullptr) {
            struct BinTree *temp = root->left;
            free(root);
            return temp;
        }

        struct BinTree *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteBinTree(root->right, temp->key);
    }
    return root;
}

struct BinTree *search (struct BinTree *tree, int key){
    while (tree && tree->key != key){
        if (tree->key < key)
            tree = tree->right;
        else
            tree = tree->left;
    }
    return tree;
}

void printBinTree (struct BinTree *tree){
    if (tree != nullptr){
        printBinTree(tree->left);
        cout << tree->key << "->";
        printBinTree(tree->right);
    }
}