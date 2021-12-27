#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class binaryTree
{
private:

    struct node
    {
        string data;
        node* left;
        node* right;
        node(string val)
        {
            left = nullptr;
            right = nullptr;
            data = val;
        }
    };

    node* root;
    int treeSize;
    void printTree(node* t)
    {
        if (t)
        {
            printTree(t->left);
            cout << t->data << " ";
            printTree(t->right);
        }
    }
    void deleteTree(node* t)
    {
        if (t)
        {
            deleteTree(t->left);
            deleteTree(t->right);
            delete t;
        }
    };

public:
    int treeCompare = 0;
    binaryTree()
    {
        root = nullptr;
        treeSize = 0;
    }

    binaryTree(string x)
    {
        root = new node(x);
        treeSize = 1;
    }
    ~binaryTree()
    {
        deleteTree(root);
    }
    void print() {
        printTree(root);
        cout << endl;
    }
    bool find(string x)
    {
        node* t = root;
        while (t && t->data != x)
        {
            if (t->data > x)
                t = t->left;
            else
                t = t->right;
        }
        return t != nullptr;
    }
    void insert(string x)
    {
        if(!root)
        {
            root = new node(x);
            ++treeCompare;
            ++treeSize;
            return;
        }
        node* t = root;
        while (t && t->data != x)
        {
            treeCompare += 2;
            if (t->data > x && t->left == nullptr)
            {
                t->left = new node(x);
                treeCompare += 2;
                ++treeSize;
                return;
            }
            if (t->data < x && t->right == nullptr)
            {
                t->right = new node(x);
                ++treeSize;
                treeCompare += 2;
                return;
            }
            if (t->data > x) {
                t = t->left;
                treeCompare++;
            }

            else {
                t = t->right;
                treeCompare++;
            }

        }
    }
    void remove(string x)
    {
        node* t = root;
        node* parent = nullptr;
        while (t && t->data != x)
        {
            parent = t;
            if (t->data > x)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        if (!t)
            return;
        if (t->left == nullptr)
        {
            //подвешивается правое поддерево
            if (parent && parent->left == t)
                parent->left = t->right;
            if (parent && parent->right == t)
                parent->right = t->right;
            --treeSize;
            delete t;
            return;
        }
        if (t->right == nullptr)
        {
            if (parent && parent->left == t)
                parent->left = t->left;
            if (parent && parent->right == t)
                parent->right = t->left;
            --treeSize;
            delete t;
            return;
        }
        node* replace = t->right;
        while (replace->left)
            replace = replace->left;
        string replace_value = replace->data;
        remove(replace_value);
        t->data = replace_value;
    }
    int size() {
        return treeSize;
    }
};